// TextProcesor.cpp Metodos de la clase procesador de texto
// Curso: Tecnologia de Objetos
// Laboratorio: B
// Autor: Carlos Alberto Mestas Escarcena

#include "TextProcesor.h"

void TextProcesor::printNumbers(std::vector<uint16_t> _vector){
    uint8_t size2 = _vector.size();
    for(uint8_t i2 = 0; i2 < size2 ; i2++){
        std::cout << _vector.at(i2) << std::endl;
    }
}

void TextProcesor::printOperations(std::vector<char> _vector){
    uint8_t size2 = _vector.size();
    for(uint8_t i2 = 0; i2 < size2 ; i2++){
        std::cout << _vector.at(i2) << std::endl;
    }
}

std::vector<uint16_t> TextProcesor::obtainNumbers(std::string _text){
    std::vector<uint16_t> vectorOfNumbers;
    uint8_t i = 0;
    uint8_t size = _text.size();
    while(i < size){
        std::string tmpNumber = "";
        while(i < size && _text.at(i) != '+' ){
            tmpNumber += _text.at(i);
            i++;
        }
        vectorOfNumbers.push_back(std::stoi(tmpNumber));
        i++;
    }
//    TextProcesor::printNumbers(vectorOfNumbers);
    return vectorOfNumbers;
}

std::vector<char> TextProcesor::obtainOperations(std::string _text){
    std::vector<char> vectorOfOperations;
    uint8_t i = 0;
    uint8_t size = _text.size();
    while(i < size){
        if(_text.at(i) == '+'){
            vectorOfOperations.push_back(_text.at(i));
        }
        i++;
    }
//    TextProcesor::printOperations(vectorOfOperations);
    return vectorOfOperations;
}



