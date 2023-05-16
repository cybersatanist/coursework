#ifndef CLASS_STUDENTS_H
#define CLASS_STUDENTS_H

#include <iostream>
#include "structure_templates.h"
#include "design_functions.h"
#include "functions.h"

using namespace std;

class Students {
private:
    struct Data data;
    Students* next;
    Students* prev;
public:
    Students() {}
    ~Students() {}

    void inputData();                      // Ввод данных
    void displayData();                    // Вывод всех данных на экран
    void displayData(int termNumber);      // Вывод данных на экран с выбранным семетром
    void setData(int changesMenuChoice);   // Изменение определенных данных

    Data getData() const;                  // Возвращает объект типа Data
    void setData(const Data &newData);     // Установка новых значений для объекта data

    void setNext(Students *next);          // Установка указателя на следующий элемент списка
    void setPrev(Students *prev);          // Установка указателя на предыдущий элемент списка

    Students* getNext() const;             // Возвращает указатель на следующий элемент в списке
    Students* getPrev() const;             // Возвращает указатель на предыдущий элемент в списке
};

#endif