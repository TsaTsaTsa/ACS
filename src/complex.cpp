//------------------------------------------------------------------------------
// complex.cpp - содержит процедуру ввода параметров
// для уже созданного комплексного числа
//------------------------------------------------------------------------------

#include "complex.h"
#include <fstream>
#include <cmath>
//------------------------------------------------------------------------------
// Ввод комплексного числа из файла
void In(complex &c, std::ifstream &ifst) {
    ifst >> c.real_part >> c.imaginary_part;
}

// Случайный ввод комплексного числа
void InRnd(complex &c) {
    c.real_part = Random();
    c.imaginary_part = Random();
}

//------------------------------------------------------------------------------
// Вывод  комплексного числа в форматируемый поток
void Out(complex &c, std::ofstream &ofst) {
    ofst << "It is complex number: real part = " << c.real_part << ", imaginary part = " << c.imaginary_part
    <<". Convert to real number " << ConvertToRealNumber(c) << "\n";
}

//------------------------------------------------------------------------------
// Вычисление действительного представления комплексного числа
double ConvertToRealNumber(complex &c) {
    return std::sqrt(c.real_part * c.real_part + c.imaginary_part * c.imaginary_part);
}
