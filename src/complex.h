#ifndef __complex__
#define __complex__

# include "rnd.h"
#include <fstream>

struct complex {
    double real_part;
    double imaginary_part;
};

// Ввод параметров комплексного числа из файла
void In(complex &c, std::ifstream &ifst);

// Случайный ввод комплексного числа
void InRnd(complex &c);

// Вывод комплексного числа в форматируемый поток
void Out(complex &c, std::ofstream &ofst);

// Вычисление действительного представления комплексного числа
double ConvertToRealNumber(complex &c);

#endif //__complex__
