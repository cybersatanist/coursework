#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <limits>

using namespace std;

void cinClear();     											 // Очистка буфера cin
bool checkInput(string surname, string name, string patronymic); // Проверка правильности ввода ФИО
bool checkInput(int day, int month, int year);    				 // Проверка правильности ввода даты рождения

#endif