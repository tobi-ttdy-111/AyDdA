#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

// Nodo del árbol de Huffman
struct HuffmanNode {
    char data;
    unsigned frequency;
    HuffmanNode *left, *right;

    HuffmanNode(char data, unsigned frequency) : data(data), frequency(frequency), left(nullptr), right(nullptr) {}
};

// Función comparadora para la cola de prioridad
struct Compare {
    bool operator()(HuffmanNode* a, HuffmanNode* b) {
        return a->frequency > b->frequency;
    }
};

// Función para imprimir el código Huffman de un árbol
void printHuffmanCodes(HuffmanNode* root, string code, unordered_map<char, string>& huffmanCodes) {
    if (root) {
        if (!root->left && !root->right) {
            cout << root->data << ": " << code << endl;
            huffmanCodes[root->data] = code;
        }

        printHuffmanCodes(root->left, code + "0", huffmanCodes);
        printHuffmanCodes(root->right, code + "1", huffmanCodes);
    }
}

// Función principal para construir el árbol de Huffman
HuffmanNode* buildHuffmanTree(const string& text, unordered_map<char, unsigned>& frequencyMap) {
    // Inicializar una cola de prioridad para los nodos del árbol de Huffman
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> minHeap;

    // Contar las frecuencias de cada carácter en el texto
    for (char c : text) {
        frequencyMap[c]++;
    }

    // Crear nodos hoja para cada carácter y agregarlos a la cola de prioridad
    for (const auto& pair : frequencyMap) {
        minHeap.push(new HuffmanNode(pair.first, pair.second));
    }

    // Construir el árbol de Huffman combinando los nodos de menor frecuencia
    while (minHeap.size() > 1) {
        HuffmanNode* left = minHeap.top();
        minHeap.pop();

        HuffmanNode* right = minHeap.top();
        minHeap.pop();

        HuffmanNode* internalNode = new HuffmanNode('$', left->frequency + right->frequency);
        internalNode->left = left;
        internalNode->right = right;

        minHeap.push(internalNode);
    }

    // Devolver el nodo raíz del árbol de Huffman
    return minHeap.top();
}

// Función para imprimir el árbol de Huffman
void printHuffmanTree(HuffmanNode* root, int indent = 0) {
    if (root) {
        if (root->data == '$') {
            cout << string(indent, ' ') << "[Internal Node] " << root->frequency << endl;
        } else {
            cout << string(indent, ' ') << root->data << ": " << root->frequency << endl;
        }

        printHuffmanTree(root->left, indent + 4);
        printHuffmanTree(root->right, indent + 4);
    }
}

int main() {
    string inputText = "ESCUELASUPERIORDECOMPUTO";
    unordered_map<char, unsigned> frequencyMap;

    HuffmanNode* root = buildHuffmanTree(inputText, frequencyMap);

    unordered_map<char, string> huffmanCodes;
    printHuffmanCodes(root, "", huffmanCodes);

    cout << "\nFrecuencias utilizadas:\n";
    for (const auto& pair : huffmanCodes) {
        cout << pair.first << ": " << frequencyMap[pair.first] << endl;
    }

    cout << "\nArbol de Huffman:\n";
    printHuffmanTree(root);

    // Liberar la memoria del árbol
    delete root;

    return 0;
}