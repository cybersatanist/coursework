#ifndef STUDENTS_H
#define STUDENTS_H

#include <iostream>
#include "structure_templates.h"
#include "design_functions.h"
#include "functions.h"

using namespace std;

class Students {
private:
    struct Data data;
public:
    Students() {}
    ~Students() {}

    void inputData();                        // Ввод данных с клавиатуры
    void displayData();                      // Вывод всех данных на экран
    void displayData(int termNumber);        // Вывод данных на экран с опцией текущего семестра
    void setData(int changesMenuChoice);     // Изменение определенных данных
    Data getData() const;                    // Возвращает объект типа 'Data'
};

#endif