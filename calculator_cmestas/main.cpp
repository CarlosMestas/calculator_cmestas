// main.cpp Clase principal para mostrar el funcionamiento de la calculadora
// Curso: Tecnologia de Objetos
// Laboratorio: B
// Autor: Carlos Alberto Mestas Escarcena

#include "Calculator.h"

int main(){
    std::string test1 = "12+34";
    std::string test2 = "42+1+34";
    std::string test3 = "1+2+3+4+5+6";
    std::string test4 = "1123+451+12+1+10+100+45+489+12";
    Calculator myCalculator;
    myCalculator.operate(test1);
    myCalculator.operate(test2);
    myCalculator.operate(test3);
    myCalculator.operate(test4);
    return 0;
}
