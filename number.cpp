//------------------------------------------------------------------------------
// number.cpp - содержит процедуры связанные с обработкой обобщенного числа
// и создания произвольного числа
//------------------------------------------------------------------------------

#include "number.h"

//------------------------------------------------------------------------------
// Ввод параметров обобщенного числа из файла
bool In(number &n, std::ifstream &ifst) {
    int k;
    ifst >> k;
    switch (k) {
        case 1:
            n.k = number::COMPLEX;
            In(n.c, ifst);
            return true;
        case 2:
            n.k = number::FRACTIONAL;
            In(n.f, ifst);
            return true;
        case 3:
            n.k = number::POLAR_COORDINATES;
            In(n.pc, ifst);
        default:
            return false;
    }
}

// Случайный ввод обобщенного числа
bool InRnd(number &n) {
    int k = rand() % 3 + 1;
    switch (k) {
        case 1:
            n.k = number::COMPLEX;
            InRnd(n.c);
            return true;
        case 2:
            n.k = number::FRACTIONAL;
            InRnd(n.f);
            return true;
        case 3:
            n.k = number::POLAR_COORDINATES;
            InRnd(n.pc);
        default:
            return false;
    }
}

//------------------------------------------------------------------------------
// Вывод параметров текущего числа в поток
void Out(number &n, std::ofstream &ofst) {
    switch(n.k) {
        case number::COMPLEX:
            Out(n.c, ofst);
            break;
        case number::FRACTIONAL:
            Out(n.f, ofst);
            break;
        case number::POLAR_COORDINATES:
            Out(n.pc, ofst);
            break;
        default:
            ofst << "Incorrect number!" << '\n';
    }
}

//------------------------------------------------------------------------------
// Приведение к действительному числу
double ConvertToRealNumber(number &n) {
    switch(n.k) {
        case number::COMPLEX:
            return ConvertToRealNumber(n.c);
        case number::FRACTIONAL:
            return ConvertToRealNumber(n.f);
        case number::POLAR_COORDINATES:
            return ConvertToRealNumber(n.pc);
        default:
            return 0.0;
    }
}
