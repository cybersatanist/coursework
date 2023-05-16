#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <limits>

#include "class_students.h"

using namespace std;

void cinClear();     											   // Очистка буфер cin
bool checkInput(string surname, string name, string patronymic);   // Проверка на корректность ввода ФИО
bool checkInput(int day, int month, int year);    				   // Проверка на корректность ввода даты рождения

#endif