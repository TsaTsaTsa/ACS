//------------------------------------------------------------------------------
// complex.cpp - содержит процедуру ввода параметров
// для уже созданного комплексного числа
//------------------------------------------------------------------------------

#include "fractional.h"
#include <fstream>

//------------------------------------------------------------------------------
Fractional::Fractional() : numerator(0), denominator(1) {}

Fractional::~Fractional() {}
// Ввод дроби из файла
void Fractional::In(std::ifstream &ifst) {
    ifst >> numerator >> denominator;
}

// Случайный ввод комплексного числа
void Fractional::InRnd() {
    numerator = Random();
    denominator = Random();
}

//------------------------------------------------------------------------------
// Вывод дроби в форматируемый поток
void Fractional::Out(std::ofstream &ofst) {
    ofst << "It is fraction: Numerator = " << numerator
         << ", Denominator = " << denominator
         << ". Convert to real number " << ConvertToRealNumber() << "\n";
}

//------------------------------------------------------------------------------
// Вычисление действительного представления дроби
double Fractional::ConvertToRealNumber() {
    return ((double) numerator / denominator);
}
