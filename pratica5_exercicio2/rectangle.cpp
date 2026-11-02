#include <iostream>
#include "rectangle.hpp"

// O construtor define os valores padrão como 1
Rectangle::Rectangle() {
    _length = 1.0;
    _width = 1.0;
}

float Rectangle::getLength() {
    return _length;
}

float Rectangle::getWidth() {
    return _width;
}

void Rectangle::setLenght(float length) {
    // Verifica se é maior que 0 e menor que 20
    if (length > 0.0 && length < 20.0)
        _length = length;
    else
        std::cout << "Erro: length (" << length << ") invalido. Mantendo o anterior (" << _length << ")." << std::endl;
}

void Rectangle::setWidth(float width) {
    
    if (width > 0.0 && width < 20.0)
        _width = width;
    else 
        std::cout << "Erro: width (" << width << ") invalido. Mantendo o anterior (" << _width << ")." << std::endl;
}

float Rectangle::calcPerimeter() {
    return 2 * (_length + _width);
}

float Rectangle::calcArea() {
    return _length * _width;
}