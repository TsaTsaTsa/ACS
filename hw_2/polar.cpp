//------------------------------------------------------------------------------
// polar_coordinates.cpp - содержит процедуру ввода параметров
// для уже созданных полярных координат
//------------------------------------------------------------------------------

#include "polar.h"
#include <fstream>
#include <cmath>

//------------------------------------------------------------------------------
// Ввод полярных координат из файла
Polar::Polar() : angel(0), x(1), y(2) {}

Polar::~Polar() {}

void Polar::In(std::ifstream &ifst) {
    ifst >> angel >> x >> y;
}

// Случайный ввод полярных координат
void Polar::InRnd() {
    angel = Random();
    x = Random();
    y = Random();
}

//------------------------------------------------------------------------------
// Вывод полярных координат в форматируемый поток
void Polar::Out(std::ofstream &ofst) {
    ofst << "It is polar coordinates: angel = " << angel
         << ", x coordinate = " << x
         << ", y coordinate = " << y
         << ". Convert to real number " << ConvertToRealNumber() << "\n";
}

//------------------------------------------------------------------------------
// Вычисление действительного представления полярных координат
double Polar::ConvertToRealNumber() {
    return std::sqrt(x * x + y * y);
}
