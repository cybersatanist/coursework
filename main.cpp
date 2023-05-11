//      Student Database Control Panel
//              Version 4.0

#include <iostream>
#include <fstream>

#include "structure_templates.h"    // Шаблоны структур
#include "design_functions.h"       // Функции оформления
#include "functions.h"              // Функции
#include "class_students.h"         // Класс студенты

using namespace std;

int main()
{   
    struct Data data;
    int mainMenuChoice;
    char x;                      // Переменная для выхода из функции

    // Главное меню
    while(true) {
        clearScreen();
        drawMainMenu();
        cin >> mainMenuChoice; 

        // Выбор действия
        switch(mainMenuChoice)
        {
            case 0:                 // Выход из программы
            {clearScreen();

                cout << "-----EXIT-----" << endl;
                return 0;
            } break;

            case 1:                 // Добавление студента в базу данных
            {clearScreen();

                Students* student = new Students();

                // Ввод пользовательских данных о студенте
                student->inputData();

                // Отображение данных введенных
                student->displayData();

                // Открытие базы данных и запись студента
                ofstream database;
                database.open("Database.bin", ios::app | ios::binary);
                database.write((char*)student, sizeof(Data));
                database.close();

                cout << "\nThe student successfully added!" << endl;
                cout << "Enter something to return to the main menu: "; cin >> x;
                delete student;
            } break;

            case 2:                 // Отображение студентов в базе данных с определенным семестром
            {clearScreen();

                int termNumber = 0;
                Students* student = new Students();

                // Открытие базы данных
                ifstream database;
                database.open("Database.bin", ios::binary);

                if (database.is_open()) {

                    // Ввод значения в переменную termNumber и проверка ввода termNumber
                    while (true) {
                        cout << "Term number: "; cin >> termNumber;
                        clearScreen();
                        if (termNumber > 0 and termNumber < 10) {
                            break;
                        } else {
                            cout << "Incorrect input!\n";
                        }
                    }
                    termNumber -= 1;

                    // Отображение студентов
                    while (database.read(reinterpret_cast<char*>(student), sizeof(Data))) {
                        student->displayData(termNumber);
                    }
                    database.close();

                } else {
                    cout << "There are no records in the database!\n";
                }

                cout << "\nEnter something to return to the main menu: "; cin >> x;
                delete student;
            } break;

            case 3:                 // Отображение студентов в базе данных со всеми семестрами
            {clearScreen();

                Students* student = new Students();

                // Открытие базы данных
                ifstream database;
                database.open("Database.bin", ios::binary);

                if (database.is_open()) {

                    // Отображение студентов
                    while (database.read(reinterpret_cast<char*>(student), sizeof(Data))) {
                        student->displayData();
                    }
                    database.close();

                } else {
                    cout << "There are no records in the database!\n";
                }

                cout << "\nEnter something to return to the main menu: "; cin >> x;
                delete student;
            } break;

            case 4:                 // Изменение данных студента
            {clearScreen();

                char number[16];
                int changesMenuChoice;
                bool flag = false;                  // Булевая переменная для проверки
                Students* student = new Students();

                // Открытие базы данных
                fstream database;
                database.open("Database.bin", ios::in | ios::out | ios::binary);

                if (database.is_open()) {

                    // Ввод номера зачетной книжки искомого студента
                    cout << "Enter gradebook number of student to edit: "; cin >> number;
                    clearScreen();

                    while (database.read(reinterpret_cast<char*>(student), sizeof(Data))) {

                        // Поиск студента по номеру зачетной книжки, отображение данных о студенте
                        if (strcmp(student->getData().gradebookNumb, number) == 0) {
                            student->displayData();

                            // Открытие меню и выбор изменяемого поля информации
                            drawChangesMenu();
                            cin >> changesMenuChoice;
                            clearScreen();

                            // Изменение информации о студенте
                            student->setData(changesMenuChoice);

                            // Запись измененной информации в базу данных
                            database.seekp(-static_cast<int>(sizeof(Data)), ios::cur);
                            database.write(reinterpret_cast<char*>(student), sizeof(Data));
                            flag = true;
                        }
                    }
                    database.close();                    

                    // Проверка изменения информации студента
                    if (flag) {
                        cout << "\nThe student is edited successfully!" << endl;
                    } else {
                        cout << "\nThe student was not found!" << endl;
                    }

                } else {
                    cout << "There are no records in the database!\n" << endl;
                }

                cout << "Enter something to return to the main menu: "; cin >> x;
                delete student;
            } break;

            case 5:                 // Удаление студента из базы данных
            {clearScreen();

                char number[16];
                bool flag = false;  // Булевая переменная для проверки

                // Открытие базы данных
                ifstream database;
                database.open("Database.bin", ios::binary);

                if (database.is_open()) {

                    // Открытие временного файла
                    ofstream temp;
                    temp.open("Temp.bin", ios::binary);

                    // Ввод номера зачетной книжки искомого студента
                    cout << "Enter gradebook number of student to delete: "; cin >> number;

                    // Чтение базы данных, запись всех студентов во временный файл, кроме искомого студента
                    while (database.read((char*)&data, sizeof(Data))) {
                        if (strcmp(data.gradebookNumb, number) != 0) {
                            temp.write((char*)&data, sizeof(Data));
                        } else {
                            flag = true;
                        }
                    }
                    database.close();
                    temp.close();

                    // Удаление старой базы данных и переименование временного файла
                    remove("Database.bin");
                    rename("Temp.bin", "Database.bin");

                    // Проверка удаления студента
                    if (flag) {
                        cout << "\nThe student is deleted successfully!" << endl;
                    } else {
                        cout << "\nThe student was not found!" << endl;
                    }

                } else {
                    cout << "There are no records in the database!\n" << endl;
                }
                
                cout << "Enter something to return to the main menu: "; cin >> x;
            } break;

            case 6:                 // Определение и отображение лучшего и худшего студента
            {clearScreen();

                int minYear, maxYear;                                   // Диапазон года рождения
                int minTerm, maxTerm;                                   // Диапазон семестров
                float maxAverageMark = 1; float minAverageMark = 6;     // Минимальное и максимальное среднее значение
                float averageMark = 0;                                  // Среднее значение
                int counter = 0;
                char bestStudent[16]; char worstStudent[16];            // Номер зачетной книжки лучшего и худшего студента
                Students* student = new Students();

                // Открытие базы данных
                ifstream database;
                database.open("Database.bin", ios::binary);

                if (database.is_open()) {

                    // Ввод диапазона года рождения
                    cout << "Enter birth year range (min max): ";
                    cin >> minYear; cin >> maxYear;
                    clearScreen();

                    // Ввод диапазона семестров
                    cout << "Enter term range (min max): ";
                    cin >> minTerm; cin >> maxTerm;
                    clearScreen();

                    // Поиск студента по диапазону года рождения
                    while (database.read((char*)&data, sizeof(Data))) {
                        if (data.year >= minYear and data.year <= maxYear) {
                            counter = 0;
                            averageMark = 0;

                            // Вычисление, в диапазоне семестров, суммы всех оценок и количества предметов
                            for (int i = minTerm - 1; i < maxTerm; i++) {
                                for (int k = 0; k < 10; k++) {
                                    if (data.term[i].mark[k].value > 1) {
                                        averageMark += data.term[i].mark[k].value;
                                        counter += 1;
                                    }
                                }
                            }
                            if (counter != 0) {
                                averageMark = averageMark / counter;
                            }

                            // Запись максимальной средней оценки и запись номера зачетной книжки лучшего студента
                            if (averageMark > maxAverageMark) {
                                maxAverageMark = averageMark;
                                strcpy(bestStudent, data.gradebookNumb);
                            }

                            // Запись минимальной средней оценки и запись номера зачетной книжки худшего студента
                            if (averageMark < minAverageMark) {
                                minAverageMark = averageMark;
                                strcpy(worstStudent, data.gradebookNumb);
                            }
                        }
                    }
                    database.close();

                    // Открытие базы данных
                    database.open("Database.bin", ios::binary);

                    // Отображение студентов    
                    while (database.read(reinterpret_cast<char*>(student), sizeof(Data))) {

                        // Отображение лучшего студента
                        if (strcmp(student->getData().gradebookNumb, bestStudent) == 0) {
                            student->displayData();
                            cout.precision(2); cout << "Maximal average: " << fixed << maxAverageMark << endl;
                        }

                        // Отображение худшего студента
                        if (strcmp(student->getData().gradebookNumb, worstStudent) == 0) {
                            student->displayData();
                            cout.precision(2); cout << "Minimal average: " << fixed << minAverageMark << endl;
                        }
                    }
                    database.close();

                } else {
                    cout << "There are no records in the database!\n";
                }

                cout << "\nEnter something to return to the main menu: "; cin >> x;
                delete student;
            } break;
        }

        // Проверка ввода mainMenuChoice
        if (mainMenuChoice < 0 or mainMenuChoice > 6) {
            clearScreen();
            cout << "\nIncorrect input!\n";
            cout << "Enter something to return to the main menu: "; cin >> x;
        }
    }
    return 0;
}
