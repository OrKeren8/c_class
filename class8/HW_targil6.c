// Or Keren
// 315155531

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NAME_LEN 11
#define MAX_FULL_NAME_LEN ((MAX_NAME_LEN * 2) + 7) // + the size of the string "GroupA "
#define MAX_COURSES 10
#define NUM_OF_GROUPS 3
#define NUM_OF_STUDENTS_IN_GROUP 6
#define GROUPS_NAMES "ABC"
#define MAX_STRING_LEN 50
#define NONO_NAME "Lois"
#define BANNED_NAME "Lex"
#define BETTER_NAME "Lane"
#define NOT_FOUND -1
#define TOP_GRADES_LEN 2

typedef struct CourseInfo
{
    int courseNum;
    int grade;
} COURSE_INFO;

typedef struct Student
{
    char name[MAX_FULL_NAME_LEN];
    int identity;
    int nofCourses; // number of courses taken in semesterA
    COURSE_INFO course_info[MAX_COURSES];
} STUDENT;

void welcomeCall();
void getStudentsData(STUDENT groups[][NUM_OF_STUDENTS_IN_GROUP]);
void getStudentData(STUDENT *student);
void getStudentName(char fullName[]);
int getIDNumber();
int getNumberOfCourses(char semesterName);
int getSemesterCourses(COURSE_INFO courseArr[]);
int getStudentNames(STUDENT stuData[][NUM_OF_STUDENTS_IN_GROUP], int rows, int cols, int courseNum, char stuNames[][MAX_FULL_NAME_LEN]);
int subInString(char string[], char subString[]);
void replaceSubInString(char string[], char subString[], char desireString[]);
void printGrades(STUDENT stuData[][NUM_OF_STUDENTS_IN_GROUP], int rows, int cols, int courseNum, int grades[NUM_OF_GROUPS][NUM_OF_STUDENTS_IN_GROUP + 1]);
void printCNum(int data[], int size, int offset);


void findTopGrades(int grades[NUM_OF_STUDENTS_IN_GROUP + 1], int topGrades[], int topGradesLen)
{   
    int temp;

    for(int j=0; j<grades[0]; j++){
        if (topGrades[topGradesLen-1] < grades[j+1]){
            topGrades[topGradesLen-1] = grades[j+1];
            for (int m=topGradesLen-1; m>0; m--){    
                if (topGrades[m] > topGrades[m-1]){
                    temp = topGrades[m-1];
                    topGrades[m-1] = topGrades[m];
                    topGrades[m] = temp; 
                }
            }
        }
    }
}

void initIntArray(int intArray[], int len, int initializer)
{
    for (int i=0; i<len; i++){
        intArray[i] = initializer;
    }
}

void printTopGrades(int grades[NUM_OF_GROUPS][NUM_OF_STUDENTS_IN_GROUP + 1], int courseNumber)
{
    int topGrades[TOP_GRADES_LEN];
    int i;

    initIntArray(topGrades, TOP_GRADES_LEN, NOT_FOUND);
    printf("Maximum grades in course#%d:\n", courseNumber);
    for (i=0; i<NUM_OF_GROUPS; i++){
        findTopGrades(grades[i], topGrades, TOP_GRADES_LEN);
        printf("Group%c: ", GROUPS_NAMES[i]);
        if (topGrades[0] == NOT_FOUND){
            printf("no grades found in group\n");
        }
        else if (topGrades[1] == NOT_FOUND){
            printf("max grade is: %d (no second max found)\n", topGrades[0]);
        }
        else{
            printf("max grade is: %d and second max is: %d\n", topGrades[0], topGrades[1]);
        }
        initIntArray(topGrades, TOP_GRADES_LEN, NOT_FOUND);
    }
}


void main()
{
    STUDENT groups[NUM_OF_GROUPS][NUM_OF_STUDENTS_IN_GROUP] = {0};
    char stuNames[NUM_OF_GROUPS * NUM_OF_STUDENTS_IN_GROUP][MAX_FULL_NAME_LEN] = {0};
    int courseNum, numOfStudents;

    welcomeCall();
    getStudentsData(groups);

    // check who learned a specific course
    printf("\nEnter a course number: ");
    scanf("%d", &courseNum);
    numOfStudents = getStudentNames(groups, NUM_OF_GROUPS, NUM_OF_STUDENTS_IN_GROUP, courseNum, stuNames);
    printf("Names of students in course#%d:\n", courseNum);
    for (int i = 0; i < numOfStudents; i++){
        printf("%s \n", stuNames[i]);
    }
    printf("\n");

    printf("Names after changing \"%s\" to \"%s\":\n", NONO_NAME, BETTER_NAME);
    
    //replace names sub strings
    for (int i = 0; i < numOfStudents; i++)
        replaceSubInString(stuNames[i], NONO_NAME, BETTER_NAME);
    for (int i = 0; i < numOfStudents; i++)
        printf("%s \n", stuNames[i]);
    printf("\n");

    //delete names with banned name
    printf("Names after deleting names with \"%s\":\n", BANNED_NAME);
    int counter = 0;
    for (int i = 0; i < numOfStudents; i++)
        if (subInString(stuNames[i], BANNED_NAME) == NOT_FOUND)
        {
            strcpy(stuNames[counter], stuNames[i]);
            counter ++;
        }
    numOfStudents = counter;
    for (int i = 0; i < numOfStudents; i++)
        printf("%s \n", stuNames[i]);
    printf("\n");

    int grades[NUM_OF_GROUPS][NUM_OF_STUDENTS_IN_GROUP + 1] = {0};
    printGrades(groups, NUM_OF_GROUPS, NUM_OF_STUDENTS_IN_GROUP, courseNum, grades);
    printf("\n");

    printTopGrades(grades, courseNum);

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
    /*feel two dimension array of Student structures

    Args:
        STUDENT groups[][NUM_OF_STUDENTS_IN_GROUP]: two dimensional array of Student structures to feel in
    return: none
    */
    for (int group = 0; group < NUM_OF_GROUPS; group++)
    {
        printf("Enter students data for GROUP %c:\n", GROUPS_NAMES[group]);
        printf("________________________________\n");
        for (int student = 0; student < NUM_OF_STUDENTS_IN_GROUP; student++)
        {
            getStudentData(&groups[group][student]);
        }
    }
}

void getStudentData(STUDENT *student)
{
    /*get data of a single student

    Args:
        STUDENT *student: struct of student to feel in
        char semesterName: A capital letter which represent the course name
    return: none
    */
    getStudentName(student->name);
    student->identity = getIDNumber();
    student->nofCourses = getSemesterCourses(student->course_info);
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
    printf("\n");
    printf("Enter student first name and last name (seperated by spaces): ");
    scanf("%s %s", firstName, lastName);
    strcpy(fullName, firstName);
    strcat(fullName, " ");
    strcat(fullName, lastName);
}

int getIDNumber()
{
    /*get user ID number
    get student id number

    Args: none
    return:
        int id: the id number of a student
    */
    int id;
    printf("Enter student ID: \n");
    scanf("%d", &id);
    return id;
}

int getSemesterCourses(COURSE_INFO courseArr[])
{
    /*get courses data from the user of a specific semester

    Args:
        char semester: the name of the semester
        COURSE_INFO courseArr[]: array of course info structure
    return: int numOfCourses: the number of courses a student took in a semester
    */
    int numOfCourses;
    printf("Enter number of courses taken in semester A: ");
    scanf("%d", &numOfCourses);
    for (int i = 0; i < numOfCourses; i++)
    {
        printf("Enter Course number and grade: ");
        scanf("%d %d", &courseArr[i].courseNum, &courseArr[i].grade);
    }
    return numOfCourses;
}

int getStudentNames(STUDENT stuData[][NUM_OF_STUDENTS_IN_GROUP], int rows, int cols, int courseNum, char stuNames[][MAX_FULL_NAME_LEN])
{
    /*get the names of students that have learned a specific course,
    and insert them in a two dimensional array

    Args:
        STUDENT stuData[][NUM_OF_STUDENTS_IN_GROUP]: two dimension array of STUDENT structs
        int rows: number of rows in the student array
        int cols:number of cols in students array
        int courseNum: the number of the course we check
        char stuNames[][MAX_FULL_NAME_LEN]: array of strings to fell in the names of the students
    return: int counter: the number of students that learned the course
    */
    int counter = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++){
            for (int k=0; k<stuData[i][j].nofCourses; k++){
                if (stuData[i][j].course_info[k].courseNum == courseNum){
                    strcpy(stuNames[counter], "Group");
                    stuNames[counter][5] = GROUPS_NAMES[i];
                    strcat(stuNames[counter], " ");
                    strcat(stuNames[counter], stuData[i][j].name);
                    counter++;
                }
            }
        }
    }
    return counter;
}

int subInString(char string[], char subString[])
{
    /*check if a substring in a string 
    
    Args: 
        char string[]: the string we want to check
        char subString[]: the sub string
    return: int i: the index of the subString or NOT_FOUND
    */
    int stringLen = strlen(string);
    int subStringLen = strlen(subString);
    char subStringUnderTest[MAX_STRING_LEN] = "";

    for (int i = 0; i <= (stringLen-subStringLen); i++){
        if (string[i] == subString[0]){
            for (int c = 0; c < subStringLen; c++){
                subStringUnderTest[c] = string[i+c];
            }
            if (strcmp(subStringUnderTest, subString) == 0){
                return i;
            }
        }
    }
    return NOT_FOUND;
}

void replaceSubInString(char string[], char subString[], char desireString[])
{   
    /*modify the string:
    replace a sub string with a new one

    Args:
        char string[]: the string to modify
        char subString[]: the sub string we want to replace
        char desireString[]: the sub string to replace with
    return: None    
    */    
    int index = subInString(string, subString);
    int subStringLen = strlen(subString);

    while(index!=NOT_FOUND){
        for (int c = 0; c < subStringLen; c++){
            string[index+c] = desireString[c];
        }
        index = subInString(string, subString);
    }
}

void printCNum(int data[], int size, int offset)
{
    /*this function prints every item in array of integers

    Args:
        int data[]: array of integers
        int size: the length of the array
        int offset: where to start printing
    return: none
    */
    for (int i = offset; i < size; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");
}

void printGrades(STUDENT stuData[][NUM_OF_STUDENTS_IN_GROUP], int rows, int cols, int courseNum, int grades[NUM_OF_GROUPS][NUM_OF_STUDENTS_IN_GROUP + 1])
{
    /*print all of the grades from specific course

    Args:
        STUDENT stuData[][NUM_OF_STUDENTS_IN_GROUP]: two dimension array of students
        int rows: number of groups
        int cols: number of students in a group
        int courseNum: number of the course
        int grades[NUM_OF_GROUPS][NUM_OF_STUDENTS_IN_GROUP + 1]: two dimension array of grades to fill in 
    return: none
    */
    int numOfGrades=0; 

    for (int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            for(int k=0; k<stuData[i][j].nofCourses; k++){
                if (stuData[i][j].course_info[k].courseNum == courseNum){
                    grades[i][numOfGrades+1] = stuData[i][j].course_info[k].grade;
                    numOfGrades++;
                }
            }
        }
        grades[i][0] = numOfGrades;
        numOfGrades=0;
    }

    printf("Grades in course#%d:\n", courseNum);
    for(int i=0; i<rows; i++){
        printf("Group%c: ", GROUPS_NAMES[i]);
        if (grades[i][0] != 0)
            printCNum(grades[i], (grades[i][0]+1), 1);
        else
            printf("\n");
    }
}

