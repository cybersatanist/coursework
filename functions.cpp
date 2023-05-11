#include "functions.h"

void cinClear()                                                   // Очистка буфера cin
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

bool checkInput(string surname, string name, string patronymic)   // Проверка правильности ввода ФИО
{
    string full_name = surname + name + patronymic;

    // Использует переменную "c" для хранения одного символа в строке и проверяет каждый символ
    for (char c : full_name) { 
        if (!isalpha(c)) {
            cout << "\nIncorrect input!\n" << endl;
            return false;
        }
    }
    return true;
}

bool checkInput(int day, int month, int year)                     // Проверка правильности ввода даты рождения
{
    if ((31 < day or 1 > day) || (12 < month or 1 > month) || (1800 > year)) {
        cout << "\nIncorrect input!\n" << endl;
        return false;
    }
    return true;
}