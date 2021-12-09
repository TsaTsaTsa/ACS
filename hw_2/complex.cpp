//------------------------------------------------------------------------------
// complex.cpp - содержит процедуру ввода параметров
// для уже созданного комплексного числа
//------------------------------------------------------------------------------

#include "complex.h"
#include <fstream>
#include <cmath>
//------------------------------------------------------------------------------

Complex::Complex() : real_part(0), imaginary_part(1) {}

// Ввод комплексного числа из файла
void Complex::In(std::ifstream &ifst) {
    ifst >> this->real_part >> this->imaginary_part;
}

// Случайный ввод комплексного числа
void Complex::InRnd() {
    this->real_part = Random();
    this->imaginary_part = Random();
}

//------------------------------------------------------------------------------
// Вывод  комплексного числа в форматируемый поток
void Complex::Out(std::ofstream &ofst) {
    ofst << "It is complex number: real part = " << real_part
         << ", imaginary part = " << imaginary_part
         <<". Convert to real number " << ConvertToRealNumber() << "\n";
}

//------------------------------------------------------------------------------
// Вычисление действительного представления комплексного числа
double Complex::ConvertToRealNumber() {
    return std::sqrt(real_part * real_part + imaginary_part * imaginary_part);
}
