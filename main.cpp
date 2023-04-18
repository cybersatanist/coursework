#include <iostream>
#include <cstring>

using namespace std;

struct Subject
{
	char value[17];
};

struct Mark
{
	unsigned short value;
};

struct Activity
{
	unsigned short sessionNumb;
	struct Subject subject[11];
	struct Mark mark[11]; 
};

struct Data
{
	char surname[21], name[21], patronymic[21];
	unsigned short date, month, year;
	unsigned short yearOfAdmission;
	char faculty[11];
	char department[11];
	char group[11];
	char gradebookNumb[11];
	char gender[1];
	struct Activity activity;
};

class Student {
private:
	struct Data record[31];
	struct Activity activity;
	struct Mark mark;
public:
    Student() 
    {
        strcpy(record[1].surname, "Surname0");
        strcpy(record[1].name, "Name0");
        strcpy(record[1].patronymic, "Patronymic0");
        record[1].date = 1;
        record[1].month = 2;
        record[1].year = 3456;
        record[1].yearOfAdmission = 7890;
        strcpy(record[1].faculty, "faculty0");
        strcpy(record[1].department, "department0");
        strcpy(record[1].group, "group0");
        strcpy(record[1].gender, "g");
        for (int i = 1; i < 11; i++) {
        	strcpy(record[1].activity.subject[i].value, "None");
        	record[1].activity.mark[i].value = 0;
        }
    }
    ~Student() {}

    void set_data(int k)
    {
    	cout << "\n" << "Student " << k << endl;
    	cout.width(18); cout << "Surname: "; cin >> record[k].surname;
    	cout.width(18); cout << "Name: "; cin >> record[k].name;
    	cout.width(18); cout << "Patronymic: "; cin >> record[k].patronymic;
    	cout.width(18); cout << "Date: "; cin >> record[k].date;
    	cout.width(18); cout << "Month: "; cin >> record[k].month;
    	cout.width(18); cout << "Year: "; cin >> record[k].year;
    	cout.width(18); cout << "YearOfAdmission: "; cin >> record[k].yearOfAdmission;
    	cout.width(18); cout << "Faculty: "; cin >> record[k].faculty;
    	cout.width(18); cout << "Department: "; cin >> record[k].department;
    	cout.width(18); cout << "Group: "; cin >> record[k].group;
    	cout.width(18); cout << "Gender: "; cin >> record[k].gender;
    	cout << "\n" << "Activity " << endl;
    	for (int i = 1; i < 11; i++) {
    		cout.width(22); cout << "Subject_and_mark" << i << ": "; cin >> record[k].activity.subject[i].value; cin >> record[k].activity.mark[i].value;
    	}
    }

    void get_data(int k)
    {
    	cout << "\n" << "Student " << k << endl;
    	cout.width(24); cout << "Surname: " << record[k].surname << endl;
    	cout.width(24); cout << "Name: " << record[k].name << endl;
    	cout.width(24); cout << "Patronymic: " << record[k].patronymic << endl;
    	cout.width(24); cout << "Date: " << record[k].date << endl;
    	cout.width(24); cout << "Month: " << record[k].month << endl;
    	cout.width(24); cout << "Year: " << record[k].year << endl;
    	cout.width(24); cout << "YearOfAdmission: " << record[k].yearOfAdmission << endl;
    	cout.width(24); cout << "Faculty: " << record[k].faculty << endl;
    	cout.width(24); cout << "Department: " << record[k].department << endl;
    	cout.width(24); cout << "Group: " << record[k].group << endl;
    	cout.width(24); cout << "Gender: " << record[k].gender << endl;
    	cout << "\n" << "Activity " << endl;
    	for (int i = 1; i < 11; i++) {
    		cout.width(22); cout << record[k].activity.subject[i].value << " | " << record[k].activity.mark[i].value << endl;
    	}
    }
};

int main() {
	Student student;
	student.set_data(1);
	cout << endl;
	student.get_data(1);

	return 0;
}
