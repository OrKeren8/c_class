// Or Keren
// 315155531

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NAME_LEN 11
#define MAX_FULL_NAME_LEN ((MAX_NAME_LEN*2)-1)
#define MAX_COURSES 2
#define NUM_OF_GROUPS 3
#define NUM_OF_STUDENTS_IN_GROUP 6
#define GROUPS_NAMES "ABC"

typedef struct CourseInfo{
    int courseNum;
    int grade;
} COURSE_INFO;

typedef struct Student{
    char name[MAX_NAME_LEN];
    int identity;
    int nofCourses; //number of courses taken in semesterA
    COURSE_INFO course_info[MAX_COURSES];
} STUDENT;

void welcomeCall();
void getStudentsData(STUDENT groups[][NUM_OF_STUDENTS_IN_GROUP]);
void getStudentData(STUDENT *student);
void getStudentName(char fullName[]);
int getIDNumber();



void main()
{
    // STUDENT groupA[NUM_OF_STUDENTS_IN_GROUP] = {0};
    // STUDENT groupB[NUM_OF_STUDENTS_IN_GROUP] = {0};
    // STUDENT groupC[NUM_OF_STUDENTS_IN_GROUP] = {0};

    STUDENT groups[NUM_OF_GROUPS][NUM_OF_STUDENTS_IN_GROUP] = {0};
    char fullName[MAX_FULL_NAME_LEN] = "";

    welcomeCall();
    getStudentsData(groups);
}

void welcomeCall()
{
    /*welcome text

    Args: none
    return: none
    */
    printf(" ********************\n"
        "* Welcome Students *\n"
        "********************\n\n");
}

void getStudentsData(STUDENT groups[][NUM_OF_STUDENTS_IN_GROUP])
{
    for (int group=0; group<NUM_OF_GROUPS; group++){
        printf("Enter students data for GROUP %c\n", GROUPS_NAMES[group]);
        printf("-----------------------------");
        for(int student=0; student<NUM_OF_STUDENTS_IN_GROUP; student++){
            getStudentData(&groups[group][student]);
        }
    }
}

void getStudentData(STUDENT *student)
{
    getStudentName(student->name);
    student->identity = getIDNumber();
}

void getStudentName(char fullName[])
{
    /*get a full name from the user

    get the first name and last name separated by " "
    and create a string of full name
    Args: 
        string fullName: full name to fill in
    return: None
    */
    char firstName[MAX_NAME_LEN] = "";
    char lastName[MAX_NAME_LEN] = "";
    strcpy(fullName, "");

    printf("Enter student first name and last name (seperated by spaces): ");
    scanf("%s %s", &firstName, &lastName);
    printf("%s\n%s", firstName, lastName);

    strcat(fullName, firstName);
    strcat(fullName, " ");
    strcat(fullName, lastName);
}

int getIDNumber()
{
    /*get user ID number
    get user id and validate if it is a real id number with check digit
    
    Args: none
    return: 
        int id: the id number of the user
    */
    int id, sum, wholeID;
    int currentCheckDigit, realCheckDigit;
    int digit, subDigit, i;
    bool validID = false;

    while (!validID)
    {
        sum = 0, i = 0;

        printf("Please enter your ID number: \n");
        scanf("%d", &id);
        wholeID = id;
        
        if(id <= 999999999 && id != 0)
        {
            currentCheckDigit = id%10;
            id = id/10;
            while(id > 0)
            {
                
                digit = id%10;
                id = id / 10;
                if (i%2)
                    digit *= 1;
                else
                    digit *= 2; 
                while(digit > 0)
                {
                    subDigit = digit%10;
                    digit = digit / 10;
                    sum += subDigit;
                }
                i ++;
            }
            
            realCheckDigit = 10 - (sum % 10);  // calculate id check digit
            if (realCheckDigit == currentCheckDigit)
                validID = true;
            else
                printf("Invalid check digit! Try again.\n");
        } 
        else
            printf("Invalid ID number! Try again.\n");
    }
    printf("\n");
    return wholeID;
}