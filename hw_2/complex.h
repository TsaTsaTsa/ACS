#ifndef __complex__
#define __complex__

#include "rnd.h"
#include <fstream>
#include "rnd.h"
#include "number.h"
#include <cmath>

class Complex: public Number {
private:
    double real_part, imaginary_part;

public:
    Complex();

    // Ввод обобщенного числа из файла
    void In(std::ifstream &ifst) override;

    // Случайный ввод числа
    void InRnd() override;

    // Вывод числа в форматируемый поток
    void Out(std::ofstream &ofst) override;

    // Вычисление действительного представления комплексного числа
    double ConvertToRealNumber();
};



#endif //__complex__
