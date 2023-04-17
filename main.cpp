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
	struct Data record;
	struct Activity activity;
	struct Mark mark;
public:
    Student() 
    {
        strcpy(record.surname, "Libov");
        strcpy(record.name, "Maxim");
        strcpy(record.patronymic, "Ivanovich");
        record.date = 1;
        record.month = 1;
        record.year = 2000;
        record.yearOfAdmission = 0;
        strcpy(record.faculty, "IKB");
        strcpy(record.department, "KB-1");
        strcpy(record.group, "BBBO-06-22");
        strcpy(record.gender, "M");
        for (int i = 0; i < 11; i++) {
        	strcpy(record.activity.subject[i].value, "None");
        	record.activity.mark[i].value = 0;
        }
    }
    ~Student() {}
};

int main() {

	return 0;
}
