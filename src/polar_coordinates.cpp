//------------------------------------------------------------------------------
// polar_coordinates.cpp - содержит процедуру ввода параметров
// для уже созданных полярных координат
//------------------------------------------------------------------------------

#include "polar_coordinates.h"
#include <fstream>
#include <cmath>
//------------------------------------------------------------------------------
// Ввод полярных координат из файла
void In(polar_coordinates &pl, std::ifstream &ifst) {
    ifst >> pl.angel >> pl.x >> pl.y;
}

// Случайный ввод полярных координат
void InRnd(polar_coordinates &pl) {
    pl.angel = Random();
    pl.x = Random();
    pl.y = Random();
}

//------------------------------------------------------------------------------
// Вывод полярных координат в форматируемый поток
void Out(polar_coordinates &pl, std::ofstream &ofst) {
    ofst << "It is polar coordinates: angel = " << pl.angel << ", x coordinate = " << pl.x
            << ", y coordinate = " << pl.y
    <<". Convert to real number " << ConvertToRealNumber(pl) << "\n";
}

//------------------------------------------------------------------------------
// Вычисление действительного представления полярных координат
double ConvertToRealNumber(polar_coordinates &pl) {
    return std::sqrt(pl.x * pl.x + pl.y * pl.y);
}
