//      Student Database Control Panel
//              Version 3.0

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

// Оформление

void clearScreen()
{
    for (int i = 0; i < 10; i++) {
        cout << "\n\n\n\n\n\n\n\n\n\n";
    }
}

void drawLine()
{
    for (int i = 0; i <= 41; i++) {
        cout << "-";
    }
    cout << endl;
}

void drawMainMenu()
{
    drawLine();
    cout.width(25); cout << "Main menu" << endl;
    drawLine();
    cout << "1 - Add student" << endl;
    cout << "2 - Display students with the current term" << endl;
    cout << "3 - Display students with all terms" << endl;
    cout << "4 - Change student" << endl;
    cout << "5 - Delete student" << endl;
    cout << "6 - Complete the task" << "\n" << endl;
    cout << "0 - Exit program" << endl;
    drawLine();
    cout << "Choice: ";
}

void drawChangesMenu()
{
    cout << "1 - Surname, name, patronymic" << endl;
    cout << "2 - Date, month, year of birthday" << endl;
    cout << "3 - YearOfAdmission" << endl;
    cout << "4 - Faculty" << endl;
    cout << "5 - Department" << endl;
    cout << "6 - GradebookNumb" << endl;
    cout << "7 - Group" << endl;
    cout << "8 - Gender" << endl;
    cout << "9 - Terms" << endl;
    drawLine();
    cout << "Choice: ";
}

// Шаблоны типа структуры

struct Subject
{
    char value[16] = "NONE";
};

struct Mark
{
    unsigned int value = 0;
};

struct Term
{
    struct Subject subject[10];
    struct Mark mark[10];
};

struct Data
{
    char surname[21] = "NONE", name[21] = "NONE", patronymic[21] = "NONE";
    unsigned short date = 0, month = 0, year = 0;
    unsigned short yearOfAdmission = 0;
    char faculty[31] = "NONE";
    char department[31] = "NONE";
    char group[16] = "NONE";
    char gradebookNumb[16] = "NONE";
    char gender[2] = "N";
    struct Term term[9];
};

class Students {
private:
    struct Data data;
public:
    Students() {}
    ~Students() {}

    void inputData()       // Ввод данных с клавиатуры 
    {
        unsigned int numberOfTerm;

        cout << "***STUDENT DATA***\n" << endl;
        cout << "Surname, name, patronymic: "; cin >> data.surname >> data.name >> data.patronymic;
        cout << "Date, month, year of birthday: "; cin >> data.date; cin >> data.month; cin >> data.year;
        cout << "YearOfAdmission: "; cin >> data.yearOfAdmission;
        cout << "Faculty: "; cin >> data.faculty;
        cout << "Department: "; cin >> data.department;
        cout << "GradebookNumb: "; cin >> data.gradebookNumb;
        cout << "Group: "; cin >> data.group;
        cout << "Gender: "; cin >> data.gender; cout << "\n";

        clearScreen();
        cout << "Number of term: "; cin >> numberOfTerm;

        for (int i = 0; i < numberOfTerm; i++) {
            clearScreen();
            cout << "\n***TERM " << i + 1 << "***\n" << endl;
            for (int k = 0; k < 10; k++) {
                cout << "Subject and mark" << k + 1 << ": "; cin >> data.term[i].subject[k].value; cin >> data.term[i].mark[k].value;
            }
        }
        clearScreen();
    }

    void displayAllData()     // Вывод всех данных на экран
    {
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

    void displayCertainData(int termNumber)     // Вывод данных на экран с опцией текущего семестра
    {
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

    void setData(unsigned int changesMenuChoice)     // Изменение определённых данных
    {
        switch(changesMenuChoice)
        {
            case 1:
            {
                cout << "Surname, name, patronymic: ";
                cin >> data.surname >> data.name >> data.patronymic;
            } break;

            case 2:
            {
                cout << "Date, moth, year: ";
                cin >> data.date >> data.month >> data.year;
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

                clearScreen();
                cout << "Number of session: "; cin >> termNumber; termNumber -= 1;
                clearScreen();

                cout <<  "***TERM " << termNumber + 1 << "***\n" << endl;
                for (int k = 0; k < 10; k++) {
                    cout << "Subject and mark" << k + 1 << ": "; cin >> data.term[termNumber].subject[k].value; cin >> data.term[termNumber].mark[k].value;
                }
            }
        }
    }

    Data getData() const {
        return data;
    }       // Возвращает объект типа 'Data'
};

int main()
{   
    struct Data data;
    unsigned int mainMenuChoice;
    char x;                      // Для выхода из функции

    // Главное меню
m1: clearScreen();
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

            student->inputData();

            ofstream database;
            database.open("Database.bin", ios::app | ios::binary);
            database.write((char*)student, sizeof(Data));
            database.close();

            student->displayAllData();

            cout << "\n" << "Student successfully added!" << endl;
            cout << "Enter <x> to exit: "; cin >> x;
            delete student;
            goto m1;
        } break;

        case 2:                 // Отображение студентов в базе данных с определённым семестром
        {clearScreen();

            int termNumber = 0;
            Students* student = new Students();

            cout << "Session number: "; cin >> termNumber; termNumber -= 1;
            clearScreen();

            ifstream database;
            database.open("Database.bin", ios::binary);
            while (database.read(reinterpret_cast<char*>(student), sizeof(Data))) {
                student->displayCertainData(termNumber);
            }
            database.close();

            cout << "\n" << "Enter <x> to exit: "; cin >> x;
            delete student;
            goto m1;
        } break;

        case 3:                 // Отображение студентов в базе данных со всеми семестрами
        {clearScreen();

            Students* student = new Students();

            ifstream database;
            database.open("Database.bin", ios::binary);
            while (database.read(reinterpret_cast<char*>(student), sizeof(Data))) {
                student->displayAllData();
            }
            database.close();

            cout << "\n" << "Enter <x> to exit: "; cin >> x;
            delete student;
            goto m1;
        } break;

        case 4:                 // Изменение данных студента
        {clearScreen();

            char number[16];
            unsigned int changesMenuChoice;
            Students* student = new Students();

            cout << "Enter gradebook number of student to edit: "; cin >> number;
            clearScreen();

            fstream database;
            database.open("Database.bin", ios::in | ios::out | ios::binary);
            while (database.read(reinterpret_cast<char*>(student), sizeof(Data))) {
                if (strcmp(student->getData().gradebookNumb, number) == 0) {
                    student->displayAllData();
                    drawChangesMenu();
                    cin >> changesMenuChoice;

                    clearScreen();
                    student->setData(changesMenuChoice);

                    database.seekp(-static_cast<int>(sizeof(Data)), ios::cur);
                    database.write(reinterpret_cast<char*>(student), sizeof(Data));
                    break;
                }
            }
            database.close();

            cout << "\n" << "Student is edited successfully!" << endl;
            cout << "Enter <x> to exit: "; cin >> x;
            delete student;
            goto m1;
        } break;

        case 5:                 // Удаление студента из базы данных
        {clearScreen();

            char number[16];

            cout << "Enter gradebook number of student to delete: "; cin >> number;

            ifstream database;
            database.open("Database.bin", ios::binary);
            ofstream temp;
            temp.open("Temp.bin", ios::binary);

            while (database.read((char*)&data, sizeof(Data))) {
                if (strcmp(data.gradebookNumb, number) != 0) {
                    temp.write((char*)&data, sizeof(Data));
                }
            }
            database.close();
            temp.close();
            remove("Database.bin");
            rename("Temp.bin", "Database.bin");

            cout << "\n" << "Student is deleted successfully!" << endl;
            cout << "Enter <x> to exit: "; cin >> x;
            goto m1;
        } break;

        case 6:                 // Определение и отображение лучшего и худшего студента
        {clearScreen();
            unsigned int minYear, maxYear;
            unsigned int minSession, maxSession;
            float maxAverage = -10000; float minAverage = 10000; float valAverage = 0;
            int counter = 0;
            char bestStudent[16]; char worstStudent[16];           // Номер зачетной книжки лучшего и худшего студента
            Students* student = new Students();

            cout << "Enter birth year range (min max): ";
            cin >> minYear; cin >> maxYear;
            clearScreen();

            cout << "Enter session range (min max): ";
            cin >> minSession; cin >> maxSession;
            clearScreen();

            ifstream database;                                     // Поиск минимального и максимального среднего значения оценки
            database.open("Database.bin", ios::binary);
            while (database.read((char*)&data, sizeof(Data))) {
                counter = 0;
                valAverage = 0;
                for (int i = minSession - 1; i < maxSession; i++) {
                    for (int k = 0; k < 10; k++) {
                        if (data.year >= minYear && data.year <= maxYear) {
                            valAverage += data.term[i].mark[k].value;
                            counter += 1;
                        }
                    }
                }
                valAverage = valAverage / counter;

                if (valAverage > maxAverage) {
                    maxAverage = valAverage;
                    strcpy(bestStudent, data.gradebookNumb);

                }
                if (valAverage < minAverage) {
                    minAverage = valAverage;
                    strcpy(worstStudent, data.gradebookNumb);
                }
            }
            database.close();

            database.open("Database.bin", ios::binary);                                     // Отображение лучшего студента
            while (database.read(reinterpret_cast<char*>(student), sizeof(Data))) {
                if (strcmp(student->getData().gradebookNumb, bestStudent) == 0) {
                    student->displayAllData();
                    cout.precision(2); cout << "Maximal average: " << fixed << maxAverage << endl;
                }
            }
            database.close();

            database.open("Database.bin", ios::binary);                                     // Отображение худшего студента
            while (database.read(reinterpret_cast<char*>(student), sizeof(Data))) {
                if (strcmp(student->getData().gradebookNumb, worstStudent) == 0) {
                    student->displayAllData();
                    cout.precision(2); cout << "Minimal average: " << fixed << minAverage << endl;
                }
            }
            database.close();

            cout << "\n" << "Enter <x> to exit: "; cin >> x;
            delete student;
            goto m1;
        } break;
    }
    return 0;
}
