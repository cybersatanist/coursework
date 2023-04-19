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

        cout << "\n" << "Student" << "\n" << endl;
        cout.width(18); cout << "Surname: "; cin >> data.surname;
        cout.width(18); cout << "Name: "; cin >> data.name;
        cout.width(18); cout << "Patronymic: "; cin >> data.patronymic;
        cout.width(18); cout << "Date: "; cin >> data.date;
        cout.width(18); cout << "Month: "; cin >> data.month;
        cout.width(18); cout << "Year: "; cin >> data.year;
        cout.width(18); cout << "YearOfAdmission: "; cin >> data.yearOfAdmission;
        cout.width(18); cout << "Faculty: "; cin >> data.faculty;
        cout.width(18); cout << "Department: "; cin >> data.department;
        cout.width(18); cout << "GradebookNumb: "; cin >> data.gradebookNumb;
        cout.width(18); cout << "Group: "; cin >> data.group;
        cout.width(18); cout << "Gender: "; cin >> data.gender;
        for (int i = 0; i < 9; i++) {
            cout <<  "\nTerm " << i + 1 << endl;
            for (int k = 0; k < 10; k++) {
                cout.width(21); cout << "Subject and mark" << k + 1 << ": "; cin >> data.term[i].subject[k].value; cin >> data.term[i].mark[k].value;
            }
        }

        ofstream file("Database.bin", ios::app | ios::binary);
        if (file.is_open()) 
        {
            file.write(reinterpret_cast<const char*>(&data), sizeof(Data));
            file.close();
        }
    }

    void display_data()
    {
        clear_screen();
        
        ifstream file("Database.bin", ios::binary);
        if (file.is_open()) {
            file.seekg(0, ios::end);
            int size = file.tellg();
            int numData = size / sizeof(Data);
            Data* data = new Data[numData];
            file.seekg(0, ios::beg);
            int n = 0;

            while(file.read(reinterpret_cast<char*>(&data[n]), sizeof(Data))) {
                cout << "\n" << "Student " << n + 1 << "\n" << endl;
                cout.width(18); cout << "Surname : " << data[n].surname << endl;
                cout.width(18); cout << "Name : " << data[n].name << endl;
                cout.width(18); cout << "Patronymic : " << data[n].patronymic << endl;
                cout.width(18); cout << "Date : " << data[n].date << endl;
                cout.width(18); cout << "Month : " << data[n].month << endl;
                cout.width(18); cout << "Year : " << data[n].year << endl;
                cout.width(18); cout << "YearOfAdmission : " << data[n].yearOfAdmission << endl;
                cout.width(18); cout << "Faculty : " << data[n].faculty << endl;
                cout.width(18); cout << "Department : " << data[n].department << endl;
                cout.width(18); cout << "GradebookNumb : " << data[n].gradebookNumb << endl;
                cout.width(18); cout << "Group : " << data[n].group << endl;
                cout.width(18); cout << "Gender : " << data[n].gender << endl;
                for (int i = 0; i < 9; i++) {
                    cout <<  "\nTerm " << i + 1 << endl;
                    for (int k = 0; k < 10; k++) {
                        cout.width(15); cout << data[n].term[i].subject[k].value << " | " << data[n].term[i].mark[k].value << endl; 
                    }
                }
                draw_line();
                n++;  
            }
        file.close();
        delete[] data;  
        }
    }
};

int main() {
	Students students;
	students.set_data();
	students.display_data();
	return 0;
}
