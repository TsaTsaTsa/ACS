#ifndef __number__
#define __number__

//------------------------------------------------------------------------------
// number.h - содержит описание обобщающего числа
//------------------------------------------------------------------------------

#include "complex.h"
#include "fractional.h"
#include "polar_coordinates.h"

//------------------------------------------------------------------------------
// структура, обобщающая все имеющиеся типы чисел
struct number {
    // значения ключей для каждого из типов
    enum key {COMPLEX, FRACTIONAL, POLAR_COORDINATES};
    key k; // ключ
    // используемые альтернативы
    union { // используем простейшую реализацию
        complex c;
        fractional f;
        polar_coordinates pc;
    };
};

// Ввод обобщенного числа
bool In(number &n, std::ifstream &ifdt);

// Случайный ввод обобщенной числа
bool InRnd(number &n);

// Вывод обобщенного числа
void Out(number &n, std::ofstream &ofst);

// Приведение к действительному числу
double ConvertToRealNumber(number &n);

#endif //__number__
