#include <stdio.h>

#define MAX_COURSES 10
#define SEMESTER_A 'A'
#define SEMESTER_B 'B'

typedef struct CourseInfo
{
    int courseNum;
    int grade;
} COURSE_INFO;

void welcomeCall();
int getSemesterCourses(char semester, COURSE_INFO courseArr[]);
void sortCourses(COURSE_INFO data[], int size);

void main()
{
    COURSE_INFO firstSemesterCoursesArr[MAX_COURSES];
    COURSE_INFO secondSemesterCoursesArr[MAX_COURSES];
    int numOfCoursesA, numOfCoursesB;

    welcomeCall();
    numOfCoursesA = getSemesterCourses(SEMESTER_A, firstSemesterCoursesArr);
    numOfCoursesB = getSemesterCourses(SEMESTER_B, secondSemesterCoursesArr);
    sortCourses(firstSemesterCoursesArr, numOfCoursesA);
}

void sortCourses(COURSE_INFO data[], int dataLen)
{
    COURSE_INFO tempCourseInfo;
    for (int j=dataLen-1; j>0; j--)
    {
        for (int i=0; i<j; i++)
        {
            if (data[i].courseNum > data[i + 1].courseNum)
            {
                tempCourseInfo = data[i];
                data[i] = data[i + 1];
                data[i + 1] = tempCourseInfo;
            }
        }
    }
    for (int j=0; j < dataLen-1; j++)
    {
        printf("%d", data[j].courseNum);
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

int getSemesterCourses(char semester, COURSE_INFO courseArr[])
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
    return numOfCourses;
}