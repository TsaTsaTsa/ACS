#ifndef __polar_coordinates__
#define __polar_coordinates__

//------------------------------------------------------------------------------
// polar_coordinates - содержит описание поярные координат и их интерфейса
//------------------------------------------------------------------------------

#include <fstream>

# include "rnd.h"

struct polar_coordinates {
    double angel; // угол в радианах
    int x, y; // координаты конечной точки на плоскости
};

// Ввод параметров полярных координат из файла
void In(polar_coordinates &pc, std::ifstream &ifst);

// Случайный ввод параметров полярных координат
void InRnd(polar_coordinates &pl);

// Вывод параметров полярных координат в форматируемый поток
void Out(polar_coordinates &pl, std::ofstream &ofst);

// Вычисление действительного представления полярных координат
double ConvertToRealNumber(polar_coordinates &pl);

#endif // __polar_coordinates__
