#include "class_students.h"

void Students::inputData()                     // Ввод данных
{
    /*
    *   1) Ввод  ФИО и проверка на корректность ввода
    *   2) Ввод даты рождения и проверка на корректность ввода
    *   3) Ввод остальной основной информации о студенте 
    *   4) Ввод количества семестров и проверка на корректность ввода
    *   5) Ввод информации в каждом, выбранном, семестре студента
    */

    int numberOfTerm = 0;
    bool flag = true;

    cout << "***STUDENT DATA***\n" << endl;

    flag = true;
    while (flag) {
        cout << "Surname, name, patronymic: "; cin >> data.surname >> data.name >> data.patronymic;
        if (checkInput(data.surname, data.name, data.patronymic)) {
            flag = false;
        }
    }
    flag = true;
    while (flag) {
        cinClear(); cout << "Date, month, year of birthday: "; cin >> data.date >> data.month >> data.year;
        if (checkInput(data.date, data.month, data.year)) {
            flag = false;
        }
    }
    cout << "YearOfAdmission: "; cin >> data.yearOfAdmission;
    cout << "Faculty: "; cin >> data.faculty;
    cout << "Department: "; cin >> data.department;
    cout << "GradebookNumb: "; cin >> data.gradebookNumb;
    cout << "Group: "; cin >> data.group;
    cout << "Gender: "; cin >> data.gender; cout << "\n";

    clearScreen();

    while (true) {
        cout << "Number of term: "; cin >> numberOfTerm;
        clearScreen();
        if (numberOfTerm > 0 and numberOfTerm < 10) {
            break;
        } else {
            cout << "Incorrect input!\n" << endl;
        }
    }

    for (int i = 0; i < numberOfTerm; i++) {
        clearScreen();
        cout << "\n***TERM " << i + 1 << "***\n" << endl;
        for (int k = 0; k < 10; k++) {
            cout << "Subject and mark " << k + 1 << ": "; cin >> data.term[i].subject[k].value; cin >> data.term[i].mark[k].value;
        }
    }

    clearScreen();
}

void Students::displayData()                   // Вывод всех данных на экран
{
    /*
    *   1) Вывод информации о студенте на экран
    *   2) Вывод информации о каждом семестре студента
    */

    drawLine();

    cout.width(18); cout << "Surname : " << data.surname << endl;
    cout.width(18); cout << "Name : " << data.name << endl;
    cout.width(18); cout << "Patronymic : " << data.patronymic << endl;
    cout.width(18); cout << "Date : " << data.date << "." << data.month << "." << data.year << endl;
    cout.width(18); cout << "YearOfAdmission : " << data.yearOfAdmission << endl;
    cout.width(18); cout << "Faculty : " << data.faculty << endl;
    cout.width(18); cout << "Department : " << data.department << endl;
    cout.width(18); cout << "GradebookNumb : " << data.gradebookNumb << endl;
    cout.width(18); cout << "Group : " << data.group << endl;
    cout.width(18); cout << "Gender : " << data.gender << endl;
    for (int i = 0; i < 9; i++) {
        cout <<  "\nTerm " << i + 1 << endl;
        for (int k = 0; k < 10; k++) {
            cout.width(15); cout << data.term[i].subject[k].value << " | " << data.term[i].mark[k].value << endl; 
        }
    }

    drawLine();
}

void Students::displayData(int termNumber)     // Вывод данных на экран с выбранным семетром
{
    /*
    *   1) Вывод информации о студенте на экран
    *   2) Вывод информации о выбранном семестре студента
    */

    drawLine();

    cout.width(18); cout << "Surname : " << data.surname << endl;
    cout.width(18); cout << "Name : " << data.name << endl;
    cout.width(18); cout << "Patronymic : " << data.patronymic << endl;
    cout.width(18); cout << "Date : " << data.date << "." << data.month << "." << data.year << endl;
    cout.width(18); cout << "YearOfAdmission : " << data.yearOfAdmission << endl;
    cout.width(18); cout << "Faculty : " << data.faculty << endl;
    cout.width(18); cout << "Department : " << data.department << endl;
    cout.width(18); cout << "GradebookNumb : " << data.gradebookNumb << endl;
    cout.width(18); cout << "Group : " << data.group << endl;
    cout.width(18); cout << "Gender : " << data.gender << endl;
    cout <<  "\nTERM " << termNumber + 1 << endl;
    for (int k = 0; k < 10; k++) {
        cout.width(15); cout << data.term[termNumber].subject[k].value << " | " << data.term[termNumber].mark[k].value << endl; 
    }

    drawLine();
}

void Students::setData(int changesMenuChoice)  // Изменение определенных данных
{

    /*
    *   1) В качестве параметра для функции switch используется, выбранный пользователем, номер изменяемого поля
    *   2) Ввод новой информации о студенте или выбранном семестре
    */

    switch(changesMenuChoice)
    {
        case 1:
        {
            bool flag = true;

            while (flag) {
                cout << "Surname, name, patronymic: "; cin >> data.surname >> data.name >> data.patronymic;
                // Проверка на корректность ввода
                if (checkInput(data.surname, data.name, data.patronymic)) {
                    flag = false;
                }
            }
        } break;

        case 2:
        {
            bool flag = true;

            while (flag) {
                cinClear(); cout << "Date, month, year of birthday: "; cin >> data.date; cin >> data.month; cin >> data.year;
                // Проверка на корректность ввода
                if (checkInput(data.date, data.month, data.year)) {
                    flag = false;
                }
            }
        } break;

        case 3:
        {
            cout << "YearOfAdmission: ";
            cin >> data.yearOfAdmission;
        } break;

        case 4:
        {
            cout << "Faculty: ";
            cin >> data.faculty;
        } break;

        case 5:
        {
            cout << "Department: ";
            cin >> data.department;
        } break;

        case 6:
        {
            cout << "GradebookNumb: ";
            cin >> data.gradebookNumb;
        } break;

        case 7:
        {
            cout << "Group: ";
            cin >> data.group;
        } break;

        case 8:
        {
            cout << "Gender: ";
            cin >> data.gender;
        } break;

        case 9:
        {
            int termNumber = 0;
            bool flag = true;

            // Проверка на корректность ввода номера семестра
            while (flag) {
                cout << "Number of term: "; cin >> termNumber;
                clearScreen();
                if (termNumber > 0 and termNumber < 10) {
                    flag = false;
                } else {
                    cout << "Incorrect input!\n" << endl;
                }
            }
            // Ввод информации о выбранном семестре студента
            clearScreen();
            cout <<  "***TERM " << termNumber << "***\n" << endl;
            for (int k = 0; k < 10; k++) {
                 cout << "Subject and mark" << k + 1 << ": "; cin >> data.term[termNumber-1].subject[k].value; cin >> data.term[termNumber-1].mark[k].value;
            }
        } break;
    }

    clearScreen();
}

Data Students::getData() const                 // Возвращает объект типа Data
{
    return data;
}

void Students::setData(const Data &newData)    // Установка новых значений для объекта data
{
    data = newData;
}

void Students::setNext(Students *next)         // Установка указателя на следующий элемент списка
{
    this->next = next;
}

void Students::setPrev(Students *prev)         // Установка указателя на предыдущий элемент списка
{
    this->prev = prev;
}

Students* Students::getNext() const            // Возвращает указатель на следующий элемент в списке
{
    return next;
}

Students* Students::getPrev() const            // Возвращает указатель на предыдущий элемент в списке
{
    return prev;
}