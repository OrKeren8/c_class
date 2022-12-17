#include <stdio.h>

#define MAX_COURSES 10
#define SEMESTER_A 'A'
#define SEMESTER_B 'B'

typedef struct CourseInfo
{
    int courseNum;
    int grade;
}COURSE_INFO;

void welcomeCall();
void getSemesterCourses(char semester, COURSE_INFO courseArr[]);
void sortCourses( COURSE_INFO data[], int size);

void main()
{
    COURSE_INFO firstSemesterCoursesArr[MAX_COURSES];
    COURSE_INFO secondSemesterCoursesArr[MAX_COURSES];
    welcomeCall();
    getSemesterCourses(SEMESTER_A, firstSemesterCoursesArr);
    getSemesterCourses(SEMESTER_B, secondSemesterCoursesArr);
}

void sortCourses(COURSE_INFO data[], int size)
{
    COURSE_INFO tempCourseInfo;
    for(int i=0; i<size-1; i++) 
    {
        if(data[i].courseNum < data[i+1].courseNum)
        {
            tempCourseInfo = data[i];
            data
        }
    }
}

void welcomeCall()
{
    /*introduction to the student

    Args: none
    return: none
    */
    printf("Welcome students!!\n"
           "and bye bye Pizzeria\n");
}

void getSemesterCourses(char semester, COURSE_INFO courseArr[])
{
    /*get courses data from the user of a specific semester

    Args:
        char semester: the name of the semester
        COURSE_INFO courseArr[]: array of course info structure
    return: none
    */
    int numOfCourses, courseNumber, grade;
    printf("Please enter number of courses in semester %c: ", semester);
    scanf("%d", &numOfCourses);
    for (int i = 0; i < numOfCourses; i++)
    {
        printf("Enter course number and grade: ");
        scanf("%d %d", &courseArr[i].courseNum, &courseArr[i].grade);
    }
}