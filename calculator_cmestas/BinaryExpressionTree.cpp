// Calculator.cpp Metodos de la clase Binary Tree Expresion
// Curso: Tecnologia de Objetos
// Laboratorio: B
// Autor: Carlos Alberto Mestas Escarcena

#include "BinaryExpressionTree.h"

/*
 * Constructor con la raiz nula
 */
BinaryExpressionTree::BinaryExpressionTree(){
    this->rootNode = NULL;
}
/*
 * Metodo para colocar un nodo ya sea raiz o no
 */
void BinaryExpressionTree::putNode(BETNode *_node){
    // En el caso de que el nodo sea nulo lo ingresamos en ese lugar
    if(rootNode == NULL){
        rootNode = new BETNode(_node->getData());
    }
    // De otro caso lo ingresamos tanto en la derecha o la izquierda
    else{
        // En el caso de que el nodo a la izquierda este vacio
        if(this->rootNode->leftNode == NULL){
            std::string aux = rootNode->getData();
            std::cout << "aux \t" << aux << std::endl;
            std::cout << "aux2\t" << _node->getData() << std::endl;
            rootNode = new BETNode(_node->getData());
            rootNode->setLeftNode(new BETNode(aux));

        }
        // En el caso de que el nodo de la derecha este vacio
        else if (this->rootNode->rightNode == NULL) {
            std::cout << "test derecha" << std::endl;
            std::string aux = _node->getData();
            std::cout << "aux3\t" << aux << std::endl;
            rootNode->setRightNode(new BETNode(aux));
        }
    }
}

/*
 * Metodo para colocar dos nodos
 * En este caso un nodo que contenga a la operacion
 * Y otro nodo con el correspondiente numero
 */
void BinaryExpressionTree::putTwoNode(BETNode *_nodeOperation, BETNode *_nodeNumber){
    // En el caso de que tengamos una suma antes y ahora una multiplicacion
    // En este caso tenemos que colocar una rotacion para que la multiplicacion
    // Sea la que tenga prioridad
    if(rootNode->getData() == "+" && _nodeOperation->getData() == "*"){
        std::cout << "Test dato " << std::endl;
        std::string aux = rootNode->getRightNode().getData();
        std::cout << "info root " << aux <<std::endl;
        rootNode->setRightNode(new BETNode(_nodeOperation->getData()));
        putLF(rootNode->rightNode, aux, _nodeNumber->getData());
        std::cout << "info root derecha " << rootNode->getRightNode().getData() <<std::endl;
        std::cout << "info a colocar " << aux << "\t "<< _nodeNumber->getData() <<std::endl;
        std::cout << "info root derecha izq" << rootNode->getRightNode().getLeftNode().getData() << std::endl;
        std::cout << "info root derecha der" << rootNode->getRightNode().getRightNode().getData() <<std::endl;

    }
    // En caso de ser solo dos sumas entonces se agrega sin problema
    else if(rootNode->getData() == "+" && _nodeOperation->getData() == "+"){
         BETNode *tmp = rootNode;
         rootNode = new BETNode(_nodeOperation->getData());
         rootNode->setLeftNode(tmp);
         rootNode->setRightNode(new BETNode(_nodeNumber->getData()));
    }
    // Lo tratamos de la misma manera que suma suma ya que la suma tiene menos prioridad
    else if(rootNode->getData() == "*" && _nodeOperation->getData() == "+"){
         BETNode *tmp = rootNode;
         rootNode = new BETNode(_nodeOperation->getData());
         rootNode->setLeftNode(tmp);
         rootNode->setRightNode(new BETNode(_nodeNumber->getData()));
    }
    // Lo tratamos como suma suma ya que dos multiplicaciones tienen la misma prioridad
    else if(rootNode->getData() == "*" && _nodeOperation->getData() == "*"){
         BETNode *tmp = rootNode;
         rootNode = new BETNode(_nodeOperation->getData());
         rootNode->setLeftNode(tmp);
         rootNode->setRightNode(new BETNode(_nodeNumber->getData()));
    }

}

/*
 * Metodo para agregar a ambos lados de un nodo de operacion los numeros
 */
void BinaryExpressionTree::putLF(BETNode *_nodeFather, std::string _num1, std::string _num2){
    _nodeFather->setLeftNode(new BETNode(_num1));
    _nodeFather->setRightNode(new BETNode(_num2));

}
/*
 * Metodo para imprimir el arbol que estamos generando
 */
void BinaryExpressionTree::printTree(){
    printTreeAux(rootNode);
}

/*
 * Metodo que ayuda al metodo de imprimir
 * En este caso podemos observar que se realizar una impresion de padre, hijo izquierda e hijo derecha
 */
void BinaryExpressionTree::printTreeAux(BETNode *_node){
    if(_node != NULL){
        std::cout << _node->getData() << " Test" << std::endl;
        printTreeAux(_node->leftNode);
        printTreeAux(_node->rightNode);

    }
}

/*
 * Metodo para realizar la suma
 * AUN NO IMPLEMENTADO TOTALMENTE
 */
void BinaryExpressionTree::operate(){
    uint16_t ans = 0;
    operateAux(ans, rootNode);
}

/*
 * Metodo que ayuda a realizar la suma
 * AUN NO IMPLEMENTADO TOTALMENTE
 */
void BinaryExpressionTree::operateAux(uint16_t _ans,BETNode *_node){
    if(_node->leftNode != NULL && _node->rightNode != NULL){
        if(_node->getData() == "+"){
            _ans = Operation::adition(std::stoi(_node->leftNode->getData()),std::stoi(_node->rightNode->getData()));
        }
    }

}

/*
 * Metodo que trata las operaciones que se ingresan como un solo dato
 */
void BinaryExpressionTree::enterPlaneText(std::string _text){
    std::vector<uint16_t> vectorOfNumbers = TextProcesor::obtainNumbers(_text);
    std::vector<char> vectorOfOperations = TextProcesor::obtainOperations(_text);

    TextProcesor::printNumbers(vectorOfNumbers);
    TextProcesor::printOperations(vectorOfOperations);

    uint8_t i2 = 0;
    uint8_t size = vectorOfOperations.size();
    std::string aux = std::to_string(vectorOfNumbers.at(0));

    // Ingresamos el nodo raiz
    BETNode *tmp = new BETNode(aux);
    BinaryExpressionTree::putNode(tmp);

    // Ingresamos los dos primeros nodos
    aux = "";
    aux.push_back(vectorOfOperations.at(i2));
    std::cout <<  aux << "Put op 1 \t" << std::endl;
    BETNode *tmp2 = new BETNode(aux);
    putNode(tmp2);

    aux = "";
    aux = std::to_string(vectorOfNumbers.at(i2 + 1));
    std::cout << aux << "Put num 2 \t" <<std::endl;
    BETNode *tmp3 = new BETNode(aux);
    putNode(tmp3);

    i2++;

    std::string aux2;

    // Ingresamos los nodos de dos en dos, operacion con su numero
    while (i2 < size){
        aux = "";
        aux.push_back(vectorOfOperations.at(i2));

        aux2 ="";
        aux2 = std::to_string(vectorOfNumbers.at(i2 + 1));

        std::cout << "Put num 3 \t" << aux << "\t" << aux2 << std::endl;
        putTwoNode(new BETNode(aux), new BETNode(aux2));

        i2++;
    }
}
