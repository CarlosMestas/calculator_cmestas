// Calculator.cpp Metodos de la clase Binary Tree Expresion Node
// Curso: Tecnologia de Objetos
// Laboratorio: B
// Autor: Carlos Alberto Mestas Escarcena

#include "BETNode.h"

// Contructor por defecto con nodos vacios a los costados
BETNode::BETNode(std::string _data){
    this->data = _data;
    this->leftNode = NULL;
    this->rightNode = NULL;
}

BETNode BETNode::getLeftNode(){
    return *leftNode;
}

BETNode BETNode::getRightNode(){
    return *rightNode;
}

void BETNode::setLeftNode(BETNode *_betNode){
    this->leftNode = _betNode;
}
void BETNode::setRightNode(BETNode *_betNode){
    this->rightNode = _betNode;
}

std::string BETNode::getData(){
    return this->data;
}
