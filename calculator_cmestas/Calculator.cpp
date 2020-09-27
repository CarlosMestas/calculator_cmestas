// Calculator.cpp Metodos de la clase calculadora
// Curso: Tecnologia de Objetos
// Laboratorio: B
// Autor: Carlos Alberto Mestas Escarcena

#include "Calculator.h"
#include "TextProcesor.h"
#include "Operation.h"

Calculator::Calculator(){

}

void Calculator::operate(std::string _text){
    std::vector<uint16_t> vectorOfNumbers;
    std::vector<char> vectorOfOperations;
    vectorOfNumbers = TextProcesor::obtainNumbers(_text);
    vectorOfOperations = TextProcesor::obtainOperations(_text);
    uint16_t ans = Calculator::finalAnswer(vectorOfNumbers, vectorOfOperations);
    std::cout << "Resultado de la entrada: " << _text << " = "<< ans << std::endl;
}

uint16_t Calculator::finalAnswer(std::vector<uint16_t> _vectorOfNumbers, std::vector<char> _vectorOfOperations){
    uint8_t size = _vectorOfOperations.size();
    uint16_t answer = _vectorOfNumbers.at(0);
    for(uint8_t i = 0; i < size; i++){
        if(_vectorOfOperations.at(i) == '+'){
//            std::cout << answer << std::endl;
            answer = Operation::adition(answer,_vectorOfNumbers.at(i + 1));
        }
    }
    return answer;
}

