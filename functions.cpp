#include "functions.h"

void cinClear()                                                   // Очистка буфера cin
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

bool checkInput(string surname, string name, string patronymic)   // Проверка на корректность ввода ФИО
{
    /*
    *   1) Записывает ФИО в одну строку
    *   2) Использует переменную "c" для хранения одного символа в строке и проверяет каждый символ на корректность ввода
    *   3) Если строка прошла проверку - возвращает true, иначе false
    */

    string full_name = surname + name + patronymic;

    for (char c : full_name) { 
        if (!isalpha(c)) {
            cout << "\nIncorrect input!\n" << endl;
            return false;
        }
    }
    return true;
}

bool checkInput(int day, int month, int year)                     // Проверка на корректность ввода даты рождения
{
    /*
    *   1) Проверяет каждое значение переменной на корректность ввода
    *   2) Если все переменные прошли проверку - возвращает true, иначе false
    */

    if ((31 < day or 1 > day) || (12 < month or 1 > month) || (1800 > year)) {
        cout << "\nIncorrect input!\n" << endl;
        return false;
    }
    return true;
}