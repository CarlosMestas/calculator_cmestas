// Calculator.h Cabecera de la clase Binary Tree Expresion
// Curso: Tecnologia de Objetos
// Laboratorio: B
// Autor: Carlos Alberto Mestas Escarcena

#ifndef BINARYEXPRESSIONTREE_H
#define BINARYEXPRESSIONTREE_H

#include "BETNode.h"
#include "TextProcesor.h"
#include "Operation.h"

#include <stddef.h>
#include <cinttypes>
#include <vector>

class BinaryExpressionTree{
private:
    BETNode *rootNode; // Nodo raiz
    std::vector<std::string> tree;
public:
    BinaryExpressionTree();
    void putNode(BETNode *_node); // Metodo para ingresar un nodo
    void putTwoNode(BETNode *_nodeOperation, BETNode *_nodeNumber); // Metodo para ingresar tanto una operacion y un nodo
    void putLF(BETNode *_nodeFather, std::string _num1, std::string _num2); // Metodo para ingresar dos nodos con una operacion
    void enterPlaneText(std::string _text); // Metodo para ingresar el texto plano
    void operate(); // Metodo para realizar la suma (Aun sin terminar)
    void operateAux(std::vector<std::string> _tree); // Metodo que ayuda a realizar la suma (Aun sin terminar)
    void printTree(); // Metodo para imprimir el arbol
    void printTreeAux(BETNode *_node); // Metodo que ayuda a imprimir el arbol
    void putInPostOrder(); // Metodo para imprimir el arbol
    void putInPostOrderAux(BETNode *_node); // Metodo que ayuda a imprimir el arbol

};

#endif // BINARYEXPRESSIONTREE_H
