#include "class_students.h"

void Students::inputData()                       // Ввод данных с клавиатуры 
{
    int numberOfTerm;
    bool flag;

    cout << "***STUDENT DATA***\n" << endl;

    // Ввод ФИО и проверка на корректность ввода
    flag = true;
    while (true) {
        cout << "Surname, name, patronymic: "; cin >> data.surname >> data.name >> data.patronymic;
        if (checkInput(data.surname, data.name, data.patronymic)) {
            flag = false;
            break;
        }
    }

    // Ввод даты рождения и проверка на корректность ввода
    flag = true;
    while (true) {
        cinClear(); cout << "Date, month, year of birthday: "; cin >> data.date >> data.month >> data.year;
        if (checkInput(data.date, data.month, data.year)) {
            flag = false;
            break;
        }
    }

    cout << "YearOfAdmission: "; cin >> data.yearOfAdmission;
    cout << "Faculty: "; cin >> data.faculty;
    cout << "Department: "; cin >> data.department;
    cout << "GradebookNumb: "; cin >> data.gradebookNumb;
    cout << "Group: "; cin >> data.group;
    cout << "Gender: "; cin >> data.gender; cout << "\n";
    clearScreen();

    // Ввод количества семестров 
    cout << "Number of term: "; cin >> numberOfTerm;

    // Ввод данных по семестру
    for (int i = 0; i < numberOfTerm; i++) {
        clearScreen();
        cout << "\n***TERM " << i + 1 << "***\n" << endl;
        for (int k = 0; k < 10; k++) {
            cout << "Subject and mark " << k + 1 << ": "; cin >> data.term[i].subject[k].value; cin >> data.term[i].mark[k].value;
        }
    }
    clearScreen();
}

void Students::displayData()                     // Вывод всех данных на экран
{
    // Вывод данных о студенте на экран
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

    // Вывод данных по каждому семестру
    for (int i = 0; i < 9; i++) {
        cout <<  "\nTerm " << i + 1 << endl;
        for (int k = 0; k < 10; k++) {
            cout.width(15); cout << data.term[i].subject[k].value << " | " << data.term[i].mark[k].value << endl; 
        }
    }
    drawLine();
}

void Students::displayData(int termNumber)       // Вывод данных на экран с опцией текущего семестра
{
    // Вывод данных о студенте на экран
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

    // Вывод данных по выбранному семестру
    cout <<  "\nTERM " << termNumber + 1 << endl;
    for (int k = 0; k < 10; k++) {
        cout.width(15); cout << data.term[termNumber].subject[k].value << " | " << data.term[termNumber].mark[k].value << endl; 
    }
    drawLine();
}

void Students::setData(int changesMenuChoice)    // Изменение определенных данных
{
    switch(changesMenuChoice)
    {
        case 1:
        {
            bool flag;
            flag = true;
            while (true) {
                cout << "Surname, name, patronymic: "; cin >> data.surname >> data.name >> data.patronymic;
                if (checkInput(data.surname, data.name, data.patronymic)) {
                    flag = false;
                    break;
                }
            }
        } break;

        case 2:
        {
            bool flag;
            flag = true;
            while (true) {
                cinClear(); cout << "Date, month, year of birthday: "; cin >> data.date; cin >> data.month; cin >> data.year;
                if (checkInput(data.date, data.month, data.year)) {
                    flag = false;
                    break;
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

            // Проверка правильности ввода termNumber
            while (true) {
                cout << "Number of term: "; cin >> termNumber;
                clearScreen();
                if (termNumber > 0 and termNumber < 10) {
                    break;
                } else {
                    cout << "Incorrect input!\n";
                }
            }
            termNumber -= 1;

            // Ввод данных по семестру
            clearScreen();
            cout <<  "***TERM " << termNumber + 1 << "***\n" << endl;
            for (int k = 0; k < 10; k++) {
                 cout << "Subject and mark" << k + 1 << ": "; cin >> data.term[termNumber].subject[k].value; cin >> data.term[termNumber].mark[k].value;
            }
        } break;
    }
    clearScreen();
}

Data Students::getData() const {
    return data;
}              							 		 // Возвращает объект типа 'Data'