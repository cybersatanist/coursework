#include "design_functions.h"

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