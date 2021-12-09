//------------------------------------------------------------------------------
// complex.cpp - содержит процедуру ввода параметров
// для уже созданного комплексного числа
//------------------------------------------------------------------------------

#include "fractional.h"
#include <fstream>

//------------------------------------------------------------------------------
// Ввод дроби из файла
void In(fractional &f, std::ifstream &ifst) {
    ifst >> f.numerator >> f.denominator;
}

// Случайный ввод комплексного числа
void InRnd(fractional &f) {
    f.numerator = Random();
    f.denominator = Random();
}

//------------------------------------------------------------------------------
// Вывод дроби в форматируемый поток
void Out(fractional &f, std::ofstream &ofst) {
    ofst << "It is fraction: Numerator = " << f.numerator << ", Denominator = " << f.denominator
         <<". Convert to real number " << ConvertToRealNumber(f) << "\n";
}

//------------------------------------------------------------------------------
// Вычисление действительного представления дроби
double ConvertToRealNumber(fractional &f) {
    return ((double)f.numerator / f.denominator);
}
