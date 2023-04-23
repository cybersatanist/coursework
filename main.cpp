#include <iostream>
#include <fstream>

using namespace std;

void clear_screen() 
{
    int n;
    for (n = 0; n < 10; n++)
    cout << "\n\n\n\n\n\n\n\n\n\n";
}

void draw_line()
{
    for (int i = 0; i <= 50; i++) {
        cout << "-";
    }
    cout << endl;
}

void draw_main_menu() 
{
    clear_screen();
    cout.width(15); cout << "Main menu" << endl;
    cout << "1 - Add student" << endl;
    cout << "2 - Display students" << endl;
    cout << "3 - Edit student" << endl;
    cout << "4 - Delete student" << endl;
    cout << "0 - Exit program" << endl;
    cout << "Choice: ";
}

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

    void set_data()
    {
        clear_screen();

        cout << "\n" << "Student data" << "\n" << endl;
        cout << "Surname, name, patronymic: "; cin >> data.surname; cin >> data.name; cin >> data.patronymic;
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
        ofstream file;
        file.open("Database.bin", ios::app | ios::binary);
        if (file.is_open()) 
        {
            file.write((char*)&data, sizeof(Data));
            file.close();
        }
    }

    void display_data()
    {
        cout.width(18); cout << "Surname : " << data.surname << endl;
        cout.width(18); cout << "Name : " << data.name << endl;
        cout.width(18); cout << "Patronymic : " << data.patronymic << endl;
        cout.width(18); cout << "Date : " << data.date << endl;
        cout.width(18); cout << "Month : " << data.month << endl;
        cout.width(18); cout << "Year : " << data.year << endl;
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
        draw_line();
    }
};

int main() {

    struct Data data;
    char x;
    int choice;

    while (true) {
        draw_main_menu();
        cin >> choice;
    
        switch(choice)
        {
        
            case 1: // Ввод данных с клавиатуры -> запись в объект -> вывод объекта в бинарный файл -> выход из пункта меню
            {
                Students* student = new Students();
                student->set_data();
                delete student;
    
                cout << "Student successfully added!" << endl;
                cout << "Enter <x> to exit program: "; cin >> x;

            } break;
        
            case 2: // Чтение структуры в файле (цикл) -> запись в объект (цикл) -> вывод на экран (цикл) -> выход из пункта меню
            {
                ifstream file;
                file.open("Database.bin", ios::binary);
                while (true) {
                    Students* student = new Students();
                    file.read(reinterpret_cast<char*>(student), sizeof(Data));
                    if (file.eof()) {
                    delete student;
                    break;
                }
                student->display_data();
                delete student;
                }
                file.close();
    
                cout << "Students are displayed successfully!" << endl;
                cout << "Enter <x> to exit: "; cin >> x;
            } break;
        
            case 3: // Запись данных из файла в динамические объекты, выбор определённого объекта, его удаление
            {
                cout << "NONE" << endl;
            } break;
            
            case 4:
            {
                cout << "NONE" << endl;
            } break;
            
            default:
            {
                clear_screen();
                cout << "**EXIT**" << endl;
                return 0;
            } break;
        
        }
    }
}
