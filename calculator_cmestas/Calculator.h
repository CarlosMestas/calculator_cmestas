// Calculator.h Cabecera de la clase calculadora
// Curso: Tecnologia de Objetos
// Laboratorio: B
// Autor: Carlos Alberto Mestas Escarcena

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <cinttypes>
#include <iostream>
#include <vector>

class Calculator{
private:
    uint16_t finalAnswer(std::vector<uint16_t> _vectorOfNumbers, std::vector<char> _vectorOfOperations);
public:
    Calculator();
    void operate(std::string _text);
};

#endif // CALCULATOR_H
