// Student Database Control Panel
// Version 1.0

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
    for (int i = 0; i <= 30; i++) {
        cout << "-";
    }
    cout << endl;
}

void drawMainMenu()
{
    cout.width(20); cout << "Main menu" << endl;
    drawLine();
    cout << "1 - Add student" << endl;
    cout << "2 - Display students" << endl;
    cout << "3 - Edit student" << endl;
    cout << "4 - Delete student" << "\n" << endl;
    cout << "0 - Exit program" << endl;
    drawLine();
    cout << "Choice: ";
}

void drawChangesMenu()
{
    drawLine();
    cout << "What data do you want to change?" << endl;
    drawLine();
    cout << "1 - Surname, name, patronymic" << endl;
    cout << "2 - Date, month, year of birthday (DD MM YY)" << endl;
    cout << "3 - YearOfAdmission" << endl;
    cout << "4 - Faculty" << endl;
    cout << "5 - Department" << endl;
    cout << "6 - GradebookNumb" << endl;
    cout << "7 - Group" << endl;
    cout << "8 - Gender" << endl;
    drawLine();
    cout << "Choice: ";
}

// Шаблоны типа структуры

struct Subject
{
    char value[31];
};

struct Mark
{
    unsigned int value;
};

struct Term
{
    struct Subject subject[10];
    struct Mark mark[10];
};

struct Data
{
    char surname[21], name[21], patronymic[21];
    unsigned short date, month, year;
    unsigned short yearOfAdmission;
    char faculty[31];
    char department[31];
    char group[16];
    char gradebookNumb[16];
    char gender[2];
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
        cout << "\n" << "Student data" << "\n" << endl;
        cout << "Surname, name, patronymic: "; cin >> data.surname >> data.name >> data.patronymic;
        cout << "Date, month, year of birthday (D M Y): "; cin >> data.date; cin >> data.month; cin >> data.year;
        cout << "YearOfAdmission: "; cin >> data.yearOfAdmission;
        cout << "Faculty: "; cin >> data.faculty;
        cout << "Department: "; cin >> data.department;
        cout << "GradebookNumb: "; cin >> data.gradebookNumb;
        cout << "Group: "; cin >> data.group;
        cout << "Gender: "; cin >> data.gender;

        for (int i = 0; i < 9; i++) {
            cout <<  "\nTerm " << i + 1 << endl;
            for (int k = 0; k < 10; k++) {
                cout << "Subject and mark" << k + 1 << ": "; cin >> data.term[i].subject[k].value; cin >> data.term[i].mark[k].value;
            }
        }
    }

    void displayData()     // Вывод данных на экран
    {
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
        }
    }

    Data getData() const {
        return data;
    }     // Возвращает объект типа 'Data'
};

int main()
{   
    // Переменные, указатели
    unsigned int mainMenuChoice;
    unsigned int changesMenuChoice;
    char x;
    char number[21];
    struct Data data;

    // Главное меню
m1: clearScreen();
    drawMainMenu();
    cin >> mainMenuChoice;

    // Выбор действия
    switch(mainMenuChoice)
    {
        case 0:                 // Выход из программы
        {
            clearScreen();
            cout << "**EXIT**" << endl;
            return 0;
        } break;

        case 1:                 // Добавление студента в базу данных
        {
            Students* student = new Students();
            student->inputData();

            ofstream database;
            database.open("Database.bin", ios::app | ios::binary);
            database.write((char*)student, sizeof(Data));
            database.close();

            cout << "\n" << "Student successfully added!" << endl;
            cout << "Enter <x> to exit: "; cin >> x;
            delete student;
            goto m1;
        } break;

        case 2:                 // Отображение всех студентов в базе данных
        {
            Students* student = new Students();

            ifstream database;
            database.open("Database.bin", ios::binary);
            while (database.read(reinterpret_cast<char*>(student), sizeof(Data))) {
                drawLine();
                student->displayData();
            }
            delete student;
            database.close();

            cout << "\n" << "Enter <x> to exit: "; cin >> x;
            goto m1;
        } break;

        case 3:                 // Изменение данных студента
        {
            drawLine();
            cout << "Enter gradebook number of student to edit: "; cin >> number;

            Students* student = new Students();

            fstream database;
            database.open("Database.bin", ios::in | ios::out | ios::binary);
            while (database.read(reinterpret_cast<char*>(student), sizeof(Data))) {
                if (strcmp(student->getData().gradebookNumb, number) == 0) {
                    student->displayData();
                    drawChangesMenu();
                    cin >> changesMenuChoice;

                    student->setData(changesMenuChoice);

                    database.seekp(-static_cast<int>(sizeof(Data)), ios::cur);
                    database.write(reinterpret_cast<char*>(student), sizeof(Data));
                    break;
                }
            }
            database.close();
            delete student;
            cout << "\n" << "Student is edited successfully!" << endl;
            cout << "Enter <x> to exit: "; cin >> x;
            goto m1;
        } break;

        case 4:                 // Удаление студента из базы данных
        {
            drawLine();
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
    }
    return 0;
}
