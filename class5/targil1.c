#include <stdio.h>
#include <stdbool.h>

typedef struct student{
    char initial;
    int id;
    double grade1, grade2;
    double average;
}STUDENT;

//function prototypes
STUDENT getStudentData();
STUDENT updateAverageGrade(STUDENT stud);
void printStudentData(STUDENT std);
char getSuccessfulStudentInitial(STUDENT stud1, STUDENT stud2);

void main()
{
    char betterStudent;

    STUDENT std1, std2;
    std1 = getStudentData();
    std2 = getStudentData();
    std1 = updateAverageGrade(std1);
    std2 = updateAverageGrade(std2);
    printStudentData(std1);
    printStudentData(std2);
    betterStudent = getSuccessfulStudentInitial(std1, std2);
    printf("Successful student is:  %c\n", betterStudent);
}

STUDENT getStudentData()
{
    STUDENT stud;
    bool goodInput = false;

    printf("please enter student data as:\n");
    while (!goodInput)
    {
        printf("Student initial: ");
        scanf(" %c", &stud.initial);
        if (!((stud.initial >= 'a' && stud.initial <= 'z') || (stud.initial >= 'A' && stud.initial <= 'Z')))
        {
            printf("Wrong initial (should be a-z or A-Z). try again: ");
        }
        else 
        {
            goodInput = true;
        }
    }
    printf("Enter student ID: ");
    scanf(" %d", &stud.id);
    printf("Enter student grades: ");
    scanf(" %lf %lf", &stud.grade1, &stud.grade2);
    return stud;
}

STUDENT updateAverageGrade(STUDENT stud)
{
    stud.average = (stud.grade1 + stud.grade2) / 2;
    return stud;
}

void printStudentData(STUDENT std)
{
    printf("Student data :\n"
    "Initial: %c\n"
    "ID: %d\n"
    "Grades: %lf %lf\n"
    "Average grade: %lf\n\n",
    std.initial, std.id, std.grade1, std.grade2, std.average
    );
}

char getSuccessfulStudentInitial(STUDENT stud1, STUDENT stud2)
{
    char Initial = stud1.initial;
    if (stud1.average < stud2.average)
    {
        Initial = stud2.initial;
    }
    return Initial;
}