//      Student Database Control Panel
//              Version 4.0

#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
#include <limits>

using namespace std;

/*
*   Функции для оформления
*/

void clearScreen()      // Очистка экрана
{
    for (int i = 0; i < 10; i++) {
        cout << "\n\n\n\n\n\n\n\n\n\n";
    }
}

void drawLine()         // Нарисовать линию
{
    for (int i = 0; i <= 41; i++) {
        cout << "-";
    }
    cout << endl;
}

void drawMainMenu()     // Нарисовать главное меню
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

void drawChangesMenu()  // Нарисовать меню изменения
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

/*
*   Шаблоны типа структуры
*/

struct Subject
{
    char value[16] = "NONE";
};

struct Mark
{
    int value = 0;
};

struct Term
{
    struct Subject subject[10];
    struct Mark mark[10];
};

struct Data
{
    char surname[21] = "NONE", name[21] = "NONE", patronymic[21] = "NONE";
    int date = 0, month = 0, year = 0;
    int yearOfAdmission = 0;
    char faculty[31] = "NONE";
    char department[31] = "NONE";
    char group[16] = "NONE";
    char gradebookNumb[16] = "NONE";
    char gender[2] = "N";
    struct Term term[9];
};

/*
*   Функции
*/

void cinClear()     // Очистка буфера cin
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

bool checkInputSNP(string surname, string name, string patronymic)   // Проверка правильности ввода ФИО
{
    string full_name = surname + name + patronymic;
    bool valid = true;

    // Использует переменную "c" для хранения одного символа в строке и проверяет каждый символ
    for (char c : full_name) { 
        if (!isalpha(c)) {
            valid = false;
            break;
        } else {
            valid = true;
        }
    }

    // Возвращает значение bool
    if (valid) {
        return true;
    } else {
        cout << "\nIncorrect input!\n" << endl;
        return false;
    }
}

bool checkInputDMY(int day, int month, int year)    // Проверка правильности ввода даты рождения
{
    if (day < 1 || month > 12 || year < 1800) {
        cout << "\nIncorrect input!\n" << endl;
        return false;
    } else {
        return true;
    }
}

/*
*   Классы
*/

class Students {
private:
    struct Data data;
public:
    Students() {}
    ~Students() {}

    void inputData()                              // Ввод данных с клавиатуры 
    {
        int numberOfTerm;
        bool flag;

        cout << "***STUDENT DATA***\n" << endl;

        // Ввод ФИО и проверка на корректность ввода
        flag = true;
        while (true) {
            cout << "Surname, name, patronymic: "; cin >> data.surname >> data.name >> data.patronymic;
            if (checkInputSNP(data.surname, data.name, data.patronymic)) {
                flag = false;
                break;
            }
        }

        // Ввод даты рождения и проверка на корректность ввода
        flag = true;
        while (true) {
            cinClear(); cout << "Date, month, year of birthday: "; cin >> data.date; cin >> data.month; cin >> data.year;
            if (checkInputDMY(data.date, data.month, data.year)) {
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

    void displayAllData()                         // Вывод всех данных на экран
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

    void displayCertainData(int termNumber)       // Вывод данных на экран с опцией текущего семестра
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

    void setData(int changesMenuChoice)           // Изменение определенных данных
    {
        switch(changesMenuChoice)
        {
            case 1:
            {
                bool flag;
                flag = true;
                while (true) {
                    cout << "Surname, name, patronymic: "; cin >> data.surname >> data.name >> data.patronymic;
                    if (checkInputSNP(data.surname, data.name, data.patronymic)) {
                        flag = false;
                        break;
                    }
                }
            }
            case 2:
            {
                bool flag;
                flag = true;
                while (true) {
                    cinClear(); cout << "Date, month, year of birthday: "; cin >> data.date; cin >> data.month; cin >> data.year;
                    if (checkInputDMY(data.date, data.month, data.year)) {
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
            }
        }
        clearScreen();
    }

    Data getData() const {
        return data;
    }                     // Возвращает объект типа 'Data'
};


int main()
{   
    struct Data data;
    int mainMenuChoice;
    char x;                      // Переменная для выхода из функции

    // Главное меню
    while(true) {
        clearScreen();
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

                // Ввод пользовательских данных о студенте
                student->inputData();

                // Отображение данных введенных
                student->displayAllData();

                // Открытие базы данных и запись студента
                ofstream database;
                database.open("Database.bin", ios::app | ios::binary);
                database.write((char*)student, sizeof(Data));
                database.close();

                cout << "\nThe student successfully added!" << endl;
                cout << "Enter something to return to the main menu: "; cin >> x;
                delete student;
            } break;

            case 2:                 // Отображение студентов в базе данных с определенным семестром
            {clearScreen();

                int termNumber = 0;
                Students* student = new Students();

                // Открытие базы данных
                ifstream database;
                database.open("Database.bin", ios::binary);

                if (database.is_open()) {

                    // Ввод значения в переменную termNumber и проверка ввода termNumber
                    while (true) {
                         cout << "Term number: "; cin >> termNumber;
                        clearScreen();
                        if (termNumber > 0 and termNumber < 10) {
                            break;
                        } else {
                            cout << "Incorrect input!\n";
                        }
                    }
                    termNumber -= 1;

                    // Отображение студентов
                    while (database.read(reinterpret_cast<char*>(student), sizeof(Data))) {
                        student->displayCertainData(termNumber);
                    }
                    database.close();

                } else {
                    cout << "There are no records in the database!\n";
                }

                cout << "\nEnter something to return to the main menu: "; cin >> x;
                delete student;
        } break;

            case 3:                 // Отображение студентов в базе данных со всеми семестрами
            {clearScreen();

                Students* student = new Students();

                // Открытие базы данных
                ifstream database;
                database.open("Database.bin", ios::binary);

                if (database.is_open()) {

                    // Отображение студентов
                    while (database.read(reinterpret_cast<char*>(student), sizeof(Data))) {
                        student->displayAllData();
                    }
                    database.close();

                } else {
                    cout << "There are no records in the database!\n";
                }
                cout << "\nEnter something to return to the main menu: "; cin >> x;
                delete student;
            } break;

            case 4:                 // Изменение данных студента
            {clearScreen();

                char number[16];
                int changesMenuChoice;
                bool flag = false;                  // Булевая переменная для проверки
                Students* student = new Students();

                // Открытие базы данных
                fstream database;
                database.open("Database.bin", ios::in | ios::out | ios::binary);

                if (database.is_open()) {

                    // Ввод номера зачетной книжки искомого студента
                    cout << "Enter gradebook number of student to edit: "; cin >> number;
                    clearScreen();

                    while (database.read(reinterpret_cast<char*>(student), sizeof(Data))) {

                        // Поиск студента по номеру зачетной книжки, отображение данных о студенте
                        if (strcmp(student->getData().gradebookNumb, number) == 0) {
                            student->displayAllData();

                            // Открытие меню и выбор изменяемого поля информации
                            drawChangesMenu();
                             cin >> changesMenuChoice;
                            clearScreen();

                            // Изменение информации о студенте
                            student->setData(changesMenuChoice);

                            // Запись измененной информации в базу данных
                            database.seekp(-static_cast<int>(sizeof(Data)), ios::cur);
                            database.write(reinterpret_cast<char*>(student), sizeof(Data));
                            flag = true;
                        }
                    }
                    database.close();                    

                    // Проверка изменения информации студента
                    if (flag) {
                        cout << "\nThe student is edited successfully!" << endl;
                    } else {
                        cout << "\nThe student was not found!" << endl;
                    }

                } else {
                    cout << "There are no records in the database!\n" << endl;
                }

                cout << "Enter something to return to the main menu: "; cin >> x;
                delete student;
            } break;

            case 5:                 // Удаление студента из базы данных
            {clearScreen();

                char number[16];
                bool flag = false;  // Булевая переменная для проверки

                // Открытие базы данных и временного файла
                ifstream database;
                database.open("Database.bin", ios::binary);
                ofstream temp;
                temp.open("Temp.bin", ios::binary);

                if (database.is_open()) {

                    // Ввод номера зачетной книжки искомого студента
                    cout << "Enter gradebook number of student to delete: "; cin >> number;

                    // Чтение базы данных, запись всех студентов во временный файл, кроме искомого студента
                    while (database.read((char*)&data, sizeof(Data))) {
                        if (strcmp(data.gradebookNumb, number) != 0) {
                            temp.write((char*)&data, sizeof(Data));
                        } else {
                            flag = true;
                        }
                    }
                    database.close();
                    temp.close();

                    // Удаление старой базы данных и переименование временного файла
                    remove("Database.bin");
                    rename("Temp.bin", "Database.bin");

                    // Проверка удаления студента
                    if (flag) {
                        cout << "\nThe student is deleted successfully!" << endl;
                    } else {
                        cout << "\nThe student was not found!" << endl;
                    }

                } else {
                    cout << "There are no records in the database!\n" << endl;
                }
                
                cout << "Enter something to return to the main menu: "; cin >> x;
            } break;

            case 6:                 // Определение и отображение лучшего и худшего студента
            {clearScreen();

                int minYear, maxYear;                                   // Диапазон года рождения
                int minTerm, maxTerm;                                   // Диапазон семестров
                float maxAverageMark = 1; float minAverageMark = 6;     // Минимальное и максимальное среднее значение
                float averageMark = 0;                                  // Среднее значение
                int counter = 0;
                char bestStudent[16]; char worstStudent[16];            // Номер зачетной книжки лучшего и худшего студента
                Students* student = new Students();

                // Открытие базы данных
                ifstream database;
                database.open("Database.bin", ios::binary);

                if (database.is_open()) {

                    // Ввод диапазона года рождения
                    cout << "Enter birth year range (min max): ";
                     cin >> minYear; cin >> maxYear;
                    clearScreen();

                    // Ввод диапазона семестров
                    cout << "Enter term range (min max): ";
                     cin >> minTerm; cin >> maxTerm;
                    clearScreen();

                    // Поиск студента по диапазону года рождения
                    while (database.read((char*)&data, sizeof(Data))) {
                        if (data.year >= minYear and data.year <= maxYear) {
                            counter = 0;
                            averageMark = 0;

                            // Вычисление, в диапазоне семестров, суммы всех оценок и количества предметов
                            for (int i = minTerm - 1; i < maxTerm; i++) {
                                for (int k = 0; k < 10; k++) {
                                    if (data.term[i].mark[k].value > 1) {
                                        averageMark += data.term[i].mark[k].value;
                                        counter += 1;
                                    }
                                }
                            }
                            if (counter != 0) {
                                averageMark = averageMark / counter;
                            }

                            // Запись максимальной средней оценки и запись номера зачетной книжки лучшего студента
                            if (averageMark > maxAverageMark) {
                            maxAverageMark = averageMark;
                            strcpy(bestStudent, data.gradebookNumb);
                            }

                            // Запись минимальной средней оценки и запись номера зачетной книжки худшего студента
                            if (averageMark < minAverageMark) {
                            minAverageMark = averageMark;
                            strcpy(worstStudent, data.gradebookNumb);
                            }
                        }
                    }
                    database.close();

                    // Открытие базы данных
                    database.open("Database.bin", ios::binary);

                    // Отображение студентов    
                    while (database.read(reinterpret_cast<char*>(student), sizeof(Data))) {

                        // Отображение лучшего студента
                        if (strcmp(student->getData().gradebookNumb, bestStudent) == 0) {
                            student->displayAllData();
                            cout.precision(2); cout << "Maximal average: " << fixed << maxAverageMark << endl;
                        }

                        // Отображение худшего студента
                        if (strcmp(student->getData().gradebookNumb, worstStudent) == 0) {
                            student->displayAllData();
                            cout.precision(2); cout << "Minimal average: " << fixed << minAverageMark << endl;
                        }
                    }
                    database.close();

                } else {
                    cout << "There are no records in the database!\n";
                }

                cout << "\nEnter something to return to the main menu: "; cin >> x;
                delete student;
            } break;
        }

        // Проверка ввода mainMenuChoice
        if (mainMenuChoice < 0 or mainMenuChoice > 6) {
            clearScreen();
            cout << "\nIncorrect input!\n";
            cout << "Enter something to return to the main menu: "; cin >> x;
        }
    }
    return 0;
}
