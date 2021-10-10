//------------------------------------------------------------------------------
// container_Constr.cpp - содержит функции обработки контейнера
//------------------------------------------------------------------------------

#include "container.h"

//------------------------------------------------------------------------------
// Инициализация контейнера
void Init(container &c) {
    c.len = 0;
}

//------------------------------------------------------------------------------
// Очистка контейнера от элементов (освобождение памяти)
void Clear(container &c) {
    c.len = 0;
}

//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного потока
void In(container &c, std::ifstream &ifst) {
    while(!ifst.eof()) {
        if(In(c.cont[c.len], ifst)) {
            c.len++;
        }
    }
}

//------------------------------------------------------------------------------
// Случайный ввод содержимого контейнера
void InRnd(container &c, int size) {
    while(c.len < size) {
        if(InRnd(c.cont[c.len])) {
            c.len++;
        }
    }
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный поток
void Out(container &c, std::ofstream &ofst) {
    ofst << "Container contains " << c.len << " elements." << '\n';
    for(int i = 0; i < c.len; i++) {
        ofst << i << ": ";
        Out(c.cont[i], ofst);
    }
}

//------------------------------------------------------------------------------
// Сортировка
void Sort(container &c) {
    
    for (int gap = c.len/2; gap > 0; gap /= 2) {
        for (int j = gap; j < c.len; ++j) {
            number temp = c.cont[j];
            int i = 0;

            for (i = j; (i>=gap) && (ConvertToRealNumber(c.cont[i-gap]) < ConvertToRealNumber(temp)); i-=gap) {
                c.cont[i] = c.cont[i - gap];
            }
            c.cont[i] = temp;
        }
    }
    
}