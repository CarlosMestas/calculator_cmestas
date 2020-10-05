// Calculator.h Cabecera de la clase Binary Tree Expresion Node
// Curso: Tecnologia de Objetos
// Laboratorio: B
// Autor: Carlos Alberto Mestas Escarcena

#ifndef BETNODE_H
#define BETNODE_H

#include <iostream>
#include <stddef.h>

class BETNode{
private:
    std::string data;          // Informacion que tendra el nodo (simbolo o numero)

public:
    BETNode *leftNode;  // Nodo que se ubicara a su izquierda
    BETNode *rightNode; // Nodo que se ubicara a su derecha

    BETNode(std::string _data);    // Contructor principal
    BETNode getLeftNode();  // Getter para obtener el nodo de la izquierda
    BETNode getRightNode(); // Getter para obtener el nodo de la derecha
    void setLeftNode(BETNode *_betNode);     // Setter para agregar un nodo a la izquierda
    void setRightNode(BETNode *_betNode);    // Setter para agregar un nodo a la derecha
    std::string getData();
};

#endif // BETNODE_H
