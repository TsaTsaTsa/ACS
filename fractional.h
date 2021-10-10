#ifndef __fractional__
#define __fractional__

//------------------------------------------------------------------------------
// fractional.h - содержит описание дроби и ее интерфейса
//------------------------------------------------------------------------------

#include "rnd.h"
#include <fstream>

struct fractional {
    int numerator, denominator; // числитель и знаменатель
};

// Ввод параметров дроби из файла
void In(fractional &f, std::ifstream &ifst);

// Случайный ввод дроби
void InRnd(fractional &f);

// Вывод дроби в форматируемый поток
void Out(fractional &f, std::ofstream &ofst);

// Вычисление действительного представления дроби
double ConvertToRealNumber(fractional &f);

#endif //__fractional__
