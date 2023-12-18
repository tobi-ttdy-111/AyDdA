
// importaciones
const readline = require( 'readline' );


// clase para el nodo del arbol de Huffman
class HuffmanNode {

    constructor( caracter, frecuencia ) {
        this.caracter = caracter;
        this.frecuencia = frecuencia;
        this.anterior = null;
        this.siguiente = null;
    };

};


// funcion para calcular la frecuencia de cada caracter
const calcularFrecuencias = ( entrada ) =>  {

    const frecuencias = new Map();

    for ( const caracter of  entrada ) {
        frecuencias.set( caracter, ( frecuencias.get( caracter ) || 0 ) + 1 );
    };

    return frecuencias;

};


// construccion del arbol de huffman
const construirArbolHuffman = ( frecuencias ) => {

    const nodes = Array.from( frecuencias, ( [ caracter, frecuencia ] ) => new HuffmanNode( caracter, frecuencia ) );

    while ( nodes.length > 1 ) {

        nodes.sort( ( a, b ) => a.frecuencia - b.frecuencia );

        const anterior = nodes.shift();
        const siguiente = nodes.shift();

        const newNode = new HuffmanNode( null, anterior.frecuencia + siguiente.frecuencia );
        newNode.anterior = anterior;
        newNode.siguiente = siguiente;

        nodes.push( newNode );

    };

    return nodes[ 0 ];

};


// funcion para la construccion de tablas de huffman
const construirTablaCodigos = ( node, code = '', tablaCodigos = new Map() ) => {

    if ( node.caracter !== null ) {
        tablaCodigos.set( node.caracter, { code, frecuencia: node.frecuencia } );
    };

    if ( node.anterior !== null) {
        construirTablaCodigos( node.anterior, code + '0', tablaCodigos );
    };

    if ( node.siguiente !== null) {
        construirTablaCodigos( node.siguiente, code + '1', tablaCodigos );
    };

    return tablaCodigos;

};


// funcion para la codificacion usando la tabla de Huffman
const encode = ( entrada , tablaCodigos) => {

    return entrada.split( '' ).map( caracter => tablaCodigos.get( caracter ).code ).join( '' );

};


// funcion para la decodificacion usando el arbol de Huffman
const decode = ( encoded, tree ) => {

    let current = tree;
    const decoded = [];

    for ( const bit of encoded ) {
        if ( bit === '0' ) {
            current = current.anterior;
        } else {
            current = current.siguiente;
        };
        if (current.caracter !== null) {
            decoded.push(current.caracter);
            current = tree;
        };
    };
    return decoded.join('');

};


// cosntruccion interfaz
const rl = readline.createInterface({
    input : process.stdin,
    output: process.stdout
});


// salida
rl.question( 'Introduce la cadena a codificar: ', ( entrada ) => {

    const frecuencias = calcularFrecuencias( entrada );
    const arbolHuffman = construirArbolHuffman( frecuencias );
    const tablaCodigos = construirTablaCodigos( arbolHuffman );

    console.log( '\nFrecuencia y Código Huffman de cada carácter:' );
    for ( const [ caracter, { code, frecuencia }] of tablaCodigos ) {
        console.log( `${ caracter }: Frecuencia - ${ frecuencia }, Código Huffman - ${ code }` );
    };

    const encoded = encode( entrada , tablaCodigos );
    console.log( '\nCadena codificada:' );
    console.log( encoded );

    const decoded = decode( encoded, arbolHuffman );
    console.log( '\nCadena decodificada:' );
    console.log( decoded );

    rl.close();

});
