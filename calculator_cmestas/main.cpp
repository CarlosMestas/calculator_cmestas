// main.cpp Clase principal para mostrar el funcionamiento de la calculadora
// Curso: Tecnologia de Objetos
// Laboratorio: B
// Autor: Carlos Alberto Mestas Escarcena

#include "Calculator.h"
#include "BinaryExpressionTree.h"

int main(){
    /*
    BinaryExpressionTree myTree1;
    BinaryExpressionTree myTree2;
    BinaryExpressionTree myTree3;
    */
    BinaryExpressionTree myTree4;

    /*
    std::string test1 = "33+1";
    std::string test2 = "2*5";
    std::string test3 = "12+4*12";
    */
    std::string test4 = "34*3+1*90";
    std::string test5 = "15+30+11*30+2*3+10";

    /*
    myTree1.enterPlaneText(test1);
    myTree2.enterPlaneText(test2);
    myTree3.enterPlaneText(test3);
    */
    myTree4.enterPlaneText(test5);
    myTree4.operate();
    /*
    myTree1.printTree();
    myTree2.printTree();
    myTree3.printTree();
    */
    // myTree4.printTree();

    /*
    std::string test1 = "12+34";
    std::string test2 = "42+1+34";
    std::string test3 = "1+2+3+4+5+6";
    std::string test4 = "1123+451+12+1+10+100+45+489+12";
    Calculator myCalculator;
    myCalculator.operate(test1);
    myCalculator.operate(test2);
    myCalculator.operate(test3);
    myCalculator.operate(test4);
    */
    return 0;
}
