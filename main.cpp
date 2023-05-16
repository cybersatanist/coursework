//      Student Database Control Panel
//              Version 1.0.0

#include <iostream>
#include <fstream>

#include "structure_templates.h"    // Шаблоны структур
#include "design_functions.h"       // Функции оформления
#include "functions.h"              // Функции
#include "class_students.h"         // Класс "список"
// #include "encrypt_and_decrypt.h"    // Шифрование базы данных

using namespace std;

int main()
{
    int menuChoice;                                                 // Выбор пользователя (меню инициализации и главное меню)
    struct Data data;                                               // Экземепляр структуры Data
    char x;                                                         // Для выхода из функции
    class Students *head, *temp, *current = nullptr;                // Указатели для связного двунаправленного списка

    /*
    *   Меню инициализации БД
    */

    while (true) {
        clearScreen();
        drawUploadMenu();
        cin >> menuChoice;

        switch(menuChoice)
        {
            case 1:         // Инициализация БД
            {
                clearScreen();

                /*
                *   1) Считывает данные из БД
                *   2) Создает новый узел и записываем в него data
                *   3) Устанавливает указатели на предыдущий и следующий элементы списка
                */

                ifstream database("Database.bin", ios::binary);
                if (database.is_open()) {
                    while (database.read(reinterpret_cast<char*>(&data), sizeof(Data))) {
                        current = new Students;
                        current->setData(data);
                        // Если это голова списка
                        if (head == nullptr) {
                            current->setNext(nullptr);
                            current->setPrev(nullptr);
                            head = current;
                        }
                        // Если это не голова списка
                        else {
                            temp->setNext(current);
                            current->setPrev(temp);
                            current->setNext(nullptr);
                        }
                        temp = current;
                    }
                    database.close();
                    cout << "The database is initialized!" << endl;
                } else {
                    cout << "The database is uninitialized!" << endl;
                }

                cout << "\nEnter something to return to the main menu: "; cin >> x;
            } break;

            case 2:         // Бездействие
            {break;} break;
            
            default:
            {
                clearScreen();
                cout << "Incorrect input!" << endl;
                cout << "\nEnter something to return to the main menu: "; cin >> x;
            } break;
        }
        // Проверка ввода menuChoice
        if (menuChoice == 1 or menuChoice == 2) {
            break;
        }
    }

    /*
    *   Главное меню
    */

    while (true) {
        clearScreen();
        drawMainMenu();
        cin >> menuChoice;

        switch(menuChoice)
        {
            case 0:         // Выход из программы
            {
                clearScreen();

                /*
                *   1) Проверяет наличие хотя бы одного элемента в списке
                *   2) Если условие выполнено, записывает данные элемента связного списка в БД
                *   3) Освобождает память, занятую элементами списка
                */

                if (head != nullptr) {
                    ofstream database("Database.bin", ios::binary);
                    current = head;
                    while (current != nullptr) {
                        data = current->getData();
                        database.write(reinterpret_cast<char*>(&data), sizeof(Data));
                        current = current->getNext();
                    }
                    database.close();
                }

                while (head != nullptr) {
                    current = head;
                    head = current->getNext();
                    delete current;
                }

                return 0;
            } break;

            case 1:         // Добавление студента
            {
                clearScreen();

                /*
                *   1) Создаёт новый узел
                *   2) Пользователь вводит данные о студенте
                *   3) Устанавливает указатели на предыдущий и следующий элементы списка
                */

                current = new Students;
                current->inputData();
                // Если это голова списка
                if (head == nullptr) {
                    current->setNext(nullptr);
                    current->setPrev(nullptr);
                    head = current;
                }
                // Если это не голова списка
                else {
                    temp->setNext(current);
                    current->setPrev(temp);
                    current->setNext(nullptr);
                }
                temp = current;

                cout << "\nThe student successfully added!" << endl;
                cout << "\nEnter something to return to the main menu: "; cin >> x;
            } break;

            case 2:         // Отображение студентов и определенного семестра
            {
                clearScreen();

                /*
                *   1) Ввод значения termNumber и проверка ввода termNumber
                *   2) Отображение студентов
                */

                int termNumber = 0;     // Номер сессии

                while (true) {
                    cout << "Term number: "; cin >> termNumber;
                    clearScreen();
                    if (termNumber > 0 and termNumber < 10) {
                        break;
                    } else {
                        cout << "Incorrect input!\n" << endl;
                    }
                }
                termNumber -= 1;

                current = head;
                while (current != nullptr) {
                    current->displayData(termNumber);
                    current = current->getNext();
                }

                cout << "\nEnter something to return to the main menu: "; cin >> x;
            } break;

            case 3:         // Отображение студентов и все семестры
            {
                clearScreen();

                /*
                *   1) Отображение студентов
                */

                current = head;
                while (current != nullptr) {
                    current->displayData();
                    current = current->getNext();
                }

                cout << "\nEnter something to return to the main menu: "; cin >> x;
            } break;

            case 4:         // Изменение данных студента
            {
                clearScreen();

                /*
                *   1) Ввод номера зачетной книжки искомого студента
                *   2) Ищет студента по номеру зачетной книжки
                *   3) Отображает данные о студенте
                *   4) Открывает меню для изменения поля информации о студенте
                *   5) Проверяет изменилась ли информация о студенте
                */

                char number[16];        // Номер зачетной книжки
                int changesMenuChoice;  // Выбор пользователя
                bool flag = false;      // Для проверки изменения информации о студенте

                cout << "Enter gradebook number of student to edit: "; cin >> number;
                clearScreen();

                current = head;
                while (current != nullptr) {
                    if (strcmp(current->getData().gradebookNumb, number) == 0) {
                        current->displayData();

                        drawChangesMenu();
                        cin >> changesMenuChoice;
                        clearScreen();

                        current->setData(changesMenuChoice);
                        flag = true;
                        break;
                    } else {
                        current = current->getNext();
                    }
                }

                clearScreen();
                if (flag) {
                    cout << "\nThe student is edited successfully!" << endl;
                } else {
                    cout << "\nThe student was not found!" << endl;
                }

                cout << "\nEnter something to return to the main menu: "; cin >> x;
            } break;

            case 5:         // Удаление студента из базы данных
            {
                clearScreen();

                /*
                *   1) Ввод номера зачетной книжки искомого студента
                *   2) Ищет студента по номеру зачетной книжки
                *   3) Устанавливает указатели предыдущего и следующего элемента списка
                *   4) Освобождает память, занятую элементом списка
                */

                char number[16];    // Номер зачетной книжки искомого студента
                bool flag = false;  // Для проверки удаления студента

                cout << "Enter gradebook number of student to delete: "; cin >> number;

                current = head;
                while (current != nullptr) {
                    if (strcmp(current->getData().gradebookNumb, number) == 0) {
                        // Если это голова списка
                        if (current == head) {
                            head = current->getNext();
                            if (current != nullptr) {
                                current->setPrev(nullptr);
                            }
                        }
                        // Если это не голова списка
                        else {
                            if (current->getPrev() != nullptr) {
                                current->getPrev()->setNext(current->getNext());
                            }
                            if (current->getNext() != nullptr) {
                                current->getNext()->setPrev(current->getPrev());
                            }
                        }

                        flag = true;
                        Students* kill = current;       // Указатель на удаляемый элемент списка
                        current = current->getNext();
                        delete kill;
                        break;
                    } else {
                        current = current->getNext();
                    }
                }

                clearScreen();
                if (flag) {
                    cout << "\nThe student is deleted successfully!" << endl;
                } else {
                    cout << "\nThe student was not found!" << endl;
                }
                cout << "\nEnter something to return to the main menu: "; cin >> x;
            } break;

            case 6:         // Определение и отображение лучшего и худшего студента
            {
                clearScreen();

                 /*
                *   1) Ввод диапазона года рождения и семестров
                *   2) Поиск студента по диапазону года рождения
                *   3) Запись максимальной и минимальной средней оценки и запись номера зачетной книжки лучшего и худшего студента
                *   4) Отображение лучшего и худшего студента по номеру зачетной книжки
                */

                int minYear, maxYear;                                           // Диапазон года рождения
                int minTerm, maxTerm;                                           // Диапазон семестров
                float maxAverageMark = 1; float minAverageMark = 6;             // Минимальное и максимальное среднее значение оценок студентов
                float averageMark = 0;                                          // Среднее значение оценок студента
                int counter = 0;                                                // Количество предметов
                char bestStudent[16] = "NONE"; char worstStudent[16] = "NONE";  // Номер зачетной книжки лучшего и худшего студента

                cout << "Enter birth year range (min max): ";
                cin >> minYear; cin >> maxYear;
                clearScreen();

                cout << "Enter term range (min max): ";
                cin >> minTerm; cin >> maxTerm;
                clearScreen();

                current = head;
                while (current != NULL) {
                    if (current->getData().year >= minYear and current->getData().year <= maxYear) {
                        counter = 0;
                        averageMark = 0;
                        for (int i = minTerm - 1; i < maxTerm; i++) {
                            for (int k = 0; k < 10; k++) {
                                if (current->getData().term[i].mark[k].value > 1) {
                                    averageMark += current->getData().term[i].mark[k].value;
                                    counter += 1;
                                }
                            }
                        }
                        if (counter != 0) {
                            averageMark = averageMark / counter;
                        }
                        if (averageMark > maxAverageMark) {
                            maxAverageMark = averageMark;
                            strcpy(bestStudent, current->getData().gradebookNumb);
                        }
                        if (averageMark < minAverageMark) {
                            minAverageMark = averageMark;
                            strcpy(worstStudent, current->getData().gradebookNumb);
                        }
                    }
                    current = current->getNext();
                }
                current = head;
                while (current != NULL) {
                    if (strcmp(current->getData().gradebookNumb, bestStudent) == 0) {
                        current->displayData();
                        cout.precision(2); cout << "Maximal average: " << fixed << maxAverageMark << endl;
                    }
                    if (strcmp(current->getData().gradebookNumb, worstStudent) == 0) {
                        current->displayData();
                        cout.precision(2); cout << "Minimal average: " << fixed << minAverageMark << endl;
                    }
                    current = current->getNext();
                }

                cout << "\nEnter something to return to the main menu: "; cin >> x;
            } break;

            default: 
            {
                clearScreen();
                cout << "Incorrect input!" << endl;
                cout << "\nEnter something to return to the main menu: "; cin >> x;
            } break;
        }
    }

    /*
    *   Меню шифрования
    */

    // while (true) {
        // 
    // }
    return 0;
}