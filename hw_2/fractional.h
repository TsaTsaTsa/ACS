#ifndef __fractional__
#define __fractional__

//------------------------------------------------------------------------------
// fractional.h - содержит описание дроби и ее интерфейса
//------------------------------------------------------------------------------

#include "number.h"
#include "rnd.h"
#include <fstream>

class Fractional : public Number {
private:
    int numerator, denominator; // числитель и знаменатель

public:
    Fractional();
    ~Fractional();
    // Ввод параметров дроби из файла
    void In(std::ifstream &ifst) override;

    // Случайный ввод дроби
    void InRnd() override;

    // Вывод дроби в форматируемый поток
    void Out(std::ofstream &ofst) override;

    // Вычисление действительного представления дроби
    double ConvertToRealNumber() override;

};


#endif //__fractional__
