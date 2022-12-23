// Or Keren
// 315155531

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_NAME_LEN 11
#define MAX_FULL_NAME_LEN ((MAX_NAME_LEN * 2) + 7) // + the size of the string "GroupA "
#define MAX_COURSES 2
#define NUM_OF_GROUPS 3
#define NUM_OF_STUDENTS_IN_GROUP 6
#define GROUPS_NAMES "ABC"

typedef struct CourseInfo
{
    int courseNum;
    int grade;
} COURSE_INFO;

typedef struct Student
{
    char name[MAX_NAME_LEN];
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
    for (int i = 0; i < numOfStudents; i++)
    {
        printf("%s \n", stuNames[i]);
    }
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
    return: int numOfStudents: the number of students that learned the course
    */
    int counter = 0, numOfStudents = 0;
    for (int i = 0; i < rows; i++)
    {
        numOfStudents += counter;
        counter = 0;
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
    return numOfStudents;
}
