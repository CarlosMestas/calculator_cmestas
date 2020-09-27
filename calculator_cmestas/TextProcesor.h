// TextProcesor.h Cabecera de la clase procesador de texto
// Curso: Tecnologia de Objetos
// Laboratorio: B
// Autor: Carlos Alberto Mestas Escarcena

#ifndef TEXTPROCESOR_H
#define TEXTPROCESOR_H

#include <cinttypes>
#include <iostream>
#include <vector>

class TextProcesor{
private:
    static void printNumbers(std::vector<uint16_t> _vector);
    static void printOperations(std::vector<char> _vector);
public:
    static std::vector<uint16_t> obtainNumbers(std::string _text);
    static std::vector<char> obtainOperations(std::string _text);

};

#endif // TEXTPROCESOR_H
