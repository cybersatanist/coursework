#ifndef STRUCTURE_TEMPLATES_H
#define STRUCTURE_TEMPLATES_H

/*
*   Информация о семестрах студента
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

/*
*   Информация о студенте
*/

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

#endif