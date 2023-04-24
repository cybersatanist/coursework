#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

// Оформление

void clear_screen()
{
    for (int i = 0; i < 10; i++) {
        cout << "\n\n\n\n\n\n\n\n\n\n";
    }
}

void draw_line()
{
    for (int i = 0; i <= 30; i++) {
        cout << "-";
    }
    cout << endl;
}

void draw_main_menu()
{
    cout.width(20); cout << "Main menu" << endl;
    draw_line();
    cout << "1 - Add student" << endl;
    cout << "2 - Display students" << endl;
    cout << "3 - Edit student" << endl;
    cout << "4 - Delete student" << "\n" << endl;
    cout << "0 - Exit program" << endl;
    draw_line();
    cout << "Choice: ";
}

// Шаблоны типа структуры

struct Subject
{
    char value[21];
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
    char faculty[21];
    char department[21];
    char group[21];
    char gradebookNumb[21];
    char gender[21];
    struct Term term[9];
};

class Students {
private:
    struct Data data;
public:
    Students() {}
    ~Students() {}

    void input_data()       // Ввод данных в объект с клавиатуры 
    {
        cout << "\n" << "Student data" << "\n" << endl;
        cout << "Surname, name, patronymic: "; cin >> data.surname >> data.name >> data.patronymic;
        cout << "Date, month, year of birthday (DD MM YY): "; cin >> data.date; cin >> data.month; cin >> data.year;
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

    void display_data()     // Вывод данных из объекта на экран
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
};

int main()
{   
    // Переменные, указатели
    unsigned int mainMenuChoice;
    char end;
    char number[21];
    struct Data data;

    // Главное меню
m1: clear_screen();
    draw_main_menu();
    cin >> mainMenuChoice;

    // Выбор действия
    switch(mainMenuChoice)
    {
        case 0:                 // Выход из программы
        {
            clear_screen();
            cout << "**EXIT**" << endl;
            return 0;
        } break;

        case 1:                 // Добавление студента в базу данных
        {
            Students student;
            student.input_data();

            ofstream database;
            database.open("Database.bin", ios::app | ios::binary);
            database.write((char*)&student, sizeof(Data));
            database.close();

            cout << "\n" << "Student successfully added!" << endl;
            cout << "Enter <x> to exit: "; cin >> end;
            goto m1;
        } break;

        case 2:                 // Отображение всех студентов из базы данных
        {
            Students student;

            ifstream database;
            database.open("Database.bin", ios::binary);
            while (database.read(reinterpret_cast<char*>(&student), sizeof(Data))) {
                draw_line();
                student.display_data();
            }
            database.close();

            cout << "\n" << "Enter <x> to exit: "; cin >> end;
            goto m1;
        } break;

        case 3:                 // Изменение данных студента
        {
            cout << "Enter gradebook number of student to edit: "; cin >> number;


            cout << "Student is edited successfully!" << endl;
            cout << "\n" << "Enter <x> to exit: "; cin >> end;
            goto m1;
        } break;

        case 4:                 // Удаление студента из базы данных
        {
            draw_line();
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

            cout << "Student is deleted successfully!" << endl;
            cout << "\n" << "Enter <x> to exit: "; cin >> end;
            goto m1;
        } break;
    }
    return 0;
}
