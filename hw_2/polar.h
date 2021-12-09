#ifndef __polar_coordinates__
#define __polar_coordinates__

//------------------------------------------------------------------------------
// polar_coordinates - содержит описание поярные координат и их интерфейса
//------------------------------------------------------------------------------

#include <fstream>
#include "number.h"
#include "rnd.h"

class Polar : public Number {
public:
    Polar();
    ~Polar();
    // Ввод параметров полярных координат из файла
    void In(std::ifstream &ifst) override;

    // Случайный ввод параметров полярных координат
    void InRnd() override;

    // Вывод параметров полярных координат в форматируемый поток
    void Out(std::ofstream &ofst) override;

    // Вычисление действительного представления полярных координат
    double ConvertToRealNumber() override;

private:
    double angel; // угол в радианах
    int x, y; // координаты конечной точки на плоскости
};

#endif // __polar_coordinates__
