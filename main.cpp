#include <iostream>
#include <cstring>

using namespace std;

void clear_screen() {
    int n;

    for (n = 0; n < 10; n++)
        cout << "\n\n\n\n\n\n\n\n\n\n";
}

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
	struct Data record;
	struct Activity activity;
	struct Mark mark;
public:
    Student() 
    {
        strcpy(record.surname, "Surname0");
        strcpy(record.name, "Name0");
        strcpy(record.patronymic, "Patronymic0");
        record.date = 1;
        record.month = 2;
        record.year = 3456;
        record.yearOfAdmission = 7890;
        strcpy(record.faculty, "faculty0");
        strcpy(record.department, "department0");
        strcpy(record.group, "group0");
        strcpy(record.gender, "g");
        for (int i = 1; i < 11; i++) {
        	strcpy(record.activity.subject[i].value, "None");
        	record.activity.mark[i].value = 0;
        }
    }
    ~Student() {}

    void set_data()
    {
    	clear_screen();
    	cout << "\n" << "Student" << endl;
    	cout.width(18); cout << "Surname: "; cin >> record.surname;
    	cout.width(18); cout << "Name: "; cin >> record.name;
    	cout.width(18); cout << "Patronymic: "; cin >> record.patronymic;
    	cout.width(18); cout << "Date: "; cin >> record.date;
    	cout.width(18); cout << "Month: "; cin >> record.month;
    	cout.width(18); cout << "Year: "; cin >> record.year;
    	cout.width(18); cout << "YearOfAdmission: "; cin >> record.yearOfAdmission;
    	cout.width(18); cout << "Faculty: "; cin >> record.faculty;
    	cout.width(18); cout << "Department: "; cin >> record.department;
    	cout.width(18); cout << "Group: "; cin >> record.group;
    	cout.width(18); cout << "Gender: "; cin >> record.gender;
    	cout << "\n" << "Activity " << endl;
    	for (int i = 1; i < 11; i++) {
    		cout.width(22); cout << "Subject_and_mark" << i << ": "; cin >> record.activity.subject[i].value; cin >> record.activity.mark[i].value;
    	}
    }

    void get_data()
    {
    	clear_screen();
    	cout << "\n" << "Student " << endl;
    	cout.width(24); cout << "Surname : " << record.surname << endl;
    	cout.width(24); cout << "Name : " << record.name << endl;
    	cout.width(24); cout << "Patronymic : " << record.patronymic << endl;
    	cout.width(24); cout << "Date : " << record.date << endl;
    	cout.width(24); cout << "Month : " << record.month << endl;
    	cout.width(24); cout << "Year : " << record.year << endl;
    	cout.width(24); cout << "YearOfAdmission : " << record.yearOfAdmission << endl;
    	cout.width(24); cout << "Faculty : " << record.faculty << endl;
    	cout.width(24); cout << "Department : " << record.department << endl;
    	cout.width(24); cout << "Group : " << record.group << endl;
    	cout.width(24); cout << "Gender : " << record.gender << endl;
    	cout << "\n" << "Activity " << endl;
    	for (int i = 1; i < 11; i++) {
    		cout.width(21); cout << record.activity.subject[i].value << " | " << record.activity.mark[i].value << endl;
    	}
    }

    void change_data()
    {
    	unsigned int choice, x;

	clear_screen();
    	cout << "\n" << "What data you want to change?" << endl;
    	cout << "1 - Data" << endl;
    	cout << "2 - Activity" << endl;
    	cout << "Choice: "; cin >> choice;
    	if (choice == 1) 
    	{
    		clear_screen();
    		cout << "What data you want to change?" << endl;
    		cout << "1 - Surname" << endl;
    		cout << "2 - Name" << endl;
    		cout << "3 - Patronymic" << endl;
    		cout << "4 - Date" << endl;
    		cout << "5 - Month" << endl;
    		cout << "6 - Year" << endl;
    		cout << "7 - YearOfAdmission" << endl;
    		cout << "8 - Faculty" << endl;
    		cout << "9 - Department" << endl;
    		cout << "10 - Group" << endl;
    		cout << "11 - Gender" << endl;
    		cout << "Choice: "; cin >> x;

    		switch(x)
    		{
    		case 1:
    			cout << "\n" << "New surname: "; cin >> record.surname;
    			break;
    		case 2:
    			cout << "\n" << "New name: "; cin >> record.name;
    			break;
    		case 3:
    			cout << "\n" << "New patronymic: "; cin >> record.patronymic;
    			break;
    		case 4:
    			cout << "\n" << "New date: "; cin >> record.date;
    			break;
    		case 5:
    			cout << "\n" << "New month: "; cin >> record.month;
    			break;
    		case 6:
    			cout << "\n" << "New year: "; cin >> record.year;
    			break;
    		case 7:
    			cout << "\n" << "New yearOfAdmission: "; cin >> record.yearOfAdmission;
    			break;
    		case 8:	
			cout << "\n" << "New faculty "; cin >> record.faculty;
			break;
    		case 9:
    			cout << "\n" << "New department: "; cin >> record.department;
    			break;
    		case 10:
    			cout << "\n" << "New group: "; cin >> record.group;
    			break;
    		case 11:
    			cout << "\n" << "New gender: "; cin >> record.gender;
    			break;
    		default:
    			cout << "ERROR";
    			break;
    		}
    	}
    	if (choice == 2)
    	{
    		clear_screen();
    		cout << "What number of subject and mark you want to change?" << endl;
    		cout << "Choice: "; cin >> x;

    		cout << "\n" << "New subject_and_mark" << x << ": "; cin >> record.activity.subject[x].value; cin >> record.activity.mark[x].value;
    	}
   	}

   	void delete_data()
   	{
   		int choice;
   		clear_screen();
   		cout << "\n" << "What student you want to delete?" << endl;
   		cout << "Choice: "; cin >> choice;
   	}
};

int main() {
	Student student;
	student.set_data();
	cout << endl;
	student.get_data();
	cout << endl;
	student.change_data();
	cout << endl;
	student.get_data();

	return 0;
}
