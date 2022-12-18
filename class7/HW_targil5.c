// Or Keren
// 315155531

#include <stdio.h>
#include <stdbool.h>

#define MAX_COURSES 10
#define UNITE_COURSES_SIZE MAX_COURSES * 2
#define MAX_EXERCISES 13
#define SEMESTER_A 'A'
#define SEMESTER_B 'B'

#define PASS_GRADE 60

typedef struct CourseInfo
{
    int courseNum;
    int grade;
} COURSE_INFO;

void welcomeCall();
int getSemesterCourses(char semester, COURSE_INFO courseArr[]);
void sortCourses(COURSE_INFO data[], int size);
void printCourses(COURSE_INFO data[], int size);
int unite(COURSE_INFO dataA[], int sizeA, COURSE_INFO dataB[], int sizeB, int uniteCourse[]);
int intersect(COURSE_INFO dataA[], int sizeA, COURSE_INFO dataB[], int sizeB, int interCourse[]);
void printCNum(int data[], int size);
COURSE_INFO findMinGrade(COURSE_INFO data[], int size);
int getExercisesInCourse(int exercises[], int courseNum);
int findFailPass(int grades[], int size);
int reorderGrades(int grades[], int size, int limit);

void main()
{
    COURSE_INFO dataA[MAX_COURSES], dataB[MAX_COURSES];
    COURSE_INFO worstCourse;
    int uniteCourse[UNITE_COURSES_SIZE], interCourse[MAX_COURSES];
    int dataALen, dataBLen, uniteCourseLen, interCourseLen;
    int exercises[MAX_EXERCISES], exercisesLen, exerciseIndex, limitGrade, failedExercises;

    welcomeCall();

    // get semester's courses
    dataALen = getSemesterCourses(SEMESTER_A, dataA);
    dataBLen = getSemesterCourses(SEMESTER_B, dataB);

    // sorting courses
    sortCourses(dataA, dataALen);
    sortCourses(dataB, dataBLen);
    printf("\n");
    printf("Sorted courses of semester %c:\n", SEMESTER_A);
    printCourses(dataA, dataALen);
    printf("Sorted courses of semester %c:\n", SEMESTER_B);
    printCourses(dataB, dataBLen);

    // get united and intersect arrays
    uniteCourseLen = unite(dataA, dataALen, dataB, dataBLen, uniteCourse);
    interCourseLen = intersect(dataA, dataALen, dataB, dataBLen, interCourse);
    printf("courses taken in semester A or semester B: ");
    printCNum(uniteCourse, uniteCourseLen);
    printf("courses taken in semester A and semester B: ");
    printCNum(interCourse, interCourseLen);
    printf("\n");

    // check the worst course of the student
    worstCourse = findMinGrade(dataA, dataALen);
    printf("Minimum grade in semester A is: %d in course #%d\n\n", worstCourse.grade, worstCourse.courseNum);

    // handle exercises of the student's worst course
    exercisesLen = getExercisesInCourse(exercises, worstCourse.courseNum);
    exerciseIndex = findFailPass(exercises, exercisesLen);
    printf("Please enter a limit grade: ");
    scanf("%d", &limitGrade);
    printf("\n");
    failedExercises = reorderGrades(exercises, exercisesLen, limitGrade);
    printf("After reordering grades, the grades smaller than %d are: ", limitGrade);
    for (int i = 0; i < failedExercises; i++)
    {
        printf("%d ", exercises[i]);
    }
}

void welcomeCall()
{
    /*introduction to the student

    Args: none
    return: none
    */
    printf(" Welcome students!!\n"
           "and bye bye Pizzeria\n\n");
}

int getSemesterCourses(char semester, COURSE_INFO courseArr[])
{
    /*get courses data from the user of a specific semester

    Args:
        char semester: the name of the semester
        COURSE_INFO courseArr[]: array of course info structure
    return: none
    */
    int numOfCourses;
    printf("Please enter number of courses in semester %c: \n", semester);
    scanf("%d", &numOfCourses);
    for (int i = 0; i < numOfCourses; i++)
    {
        printf("Enter course number and grade: \n");
        scanf("%d %d", &courseArr[i].courseNum, &courseArr[i].grade);
    }
    return numOfCourses;
}

void sortCourses(COURSE_INFO data[], int dataLen)
{
    /*this function sorts array of COURSE_INFO structures with bubble sort algorithm

    the run time of this function is O(n^2)
    Args:
        COURSE_INFO data[]: array of course
        int dataLen: the size of data array
    return: none
    */
    COURSE_INFO tempCourseInfo;
    for (int j = dataLen - 1; j > 0; j--)
    {
        for (int i = 0; i < j; i++)
        {
            if (data[i].courseNum > data[i + 1].courseNum)
            {
                tempCourseInfo = data[i];
                data[i] = data[i + 1];
                data[i + 1] = tempCourseInfo;
            }
        }
    }
}

void printCourses(COURSE_INFO data[], int size)
{
    printf("Course# Grade\n"
           "======= =====\n");
    for (int i = 0; i <= size - 1; i++)
    {
        printf("%d", data[i].courseNum);
        printf("\t");
        printf("%d\n", data[i].grade);
    }
    printf("\n");
}

int unite(COURSE_INFO dataA[], int sizeA, COURSE_INFO dataB[], int sizeB, int uniteCourse[])
{
    /*this function unite two courses arrays into one

    the run time of this program is O(length of the united array)
    Args:
        COURSE_INFO dataA[]: array of COURSE_INFO structure
        int sizeA: length of dataA array
        COURSE_INFO dataB[]: array of COURSE_INFO structure
        int sizeB: length of dataB array
        int uniteCourse: int array of courses numbers to fill in
    return: int uniteLen: length of uniteCourse
    */
    int i = 0, j = 0, uniteLen = 0;

    while (i < sizeB && j < sizeA)
    {
        if (dataB[i].courseNum < dataA[j].courseNum)
        {
            uniteCourse[uniteLen] = dataB[i].courseNum;
            i++;
        }
        else if (dataB[i].courseNum > dataA[j].courseNum)
        {
            uniteCourse[uniteLen] = dataA[j].courseNum;
            j++;
        }
        else
        {
            uniteCourse[uniteLen] = dataA[j].courseNum;
            i++;
            j++;
        }
        uniteLen++;
    }
    if (i < sizeB)
    {
        for (i; i < sizeB; i++)
        {
            uniteCourse[uniteLen] = dataB[i].courseNum;
            uniteLen++;
        }
    }
    else if (j < sizeA)
    {
        for (j; j < sizeA; j++)
        {
            uniteCourse[uniteLen] = dataA[j].courseNum;
            uniteLen++;
        }
    }
    return uniteLen;
}

int intersect(COURSE_INFO dataA[], int sizeA, COURSE_INFO dataB[], int sizeB, int interCourse[])
{
    /*this function intersect two COURSE_INFO arrays into one

    the output array contain the course numbers that appears in two
    of the arrays
    the run time of this function is O(sizeA*sizeB)
    Args:
        COURSE_INFO dataA[]: array of COURSE_INFO structure
        int sizeA: length of dataA array
        COURSE_INFO dataB[]: array of COURSE_INFO structure
        int sizeB: length of dataB array
        int interCourse: int array of courses numbers to fill in
    return: int interCourseLen: length of interCourse array
    */
    bool notFound;
    int interCourseLen = 0;

    for (int i = 0; i < sizeA; i++)
    {
        notFound = true;
        for (int j = 0; j < sizeB && notFound; j++)
        {
            if (dataA[i].courseNum == dataB[j].courseNum)
            {
                interCourse[interCourseLen] = dataA[i].courseNum;
                interCourseLen++;
                notFound = false;
            }
        }
    }
    return interCourseLen;
}

void printCNum(int data[], int size)
{
    /*this function prints every item in array of integers

    Args:
        int data[]: array of integers
        int size: the length of the array

    */
    for (int i = 0; i < size; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");
}

COURSE_INFO findMinGrade(COURSE_INFO data[], int size)
{
    /* this function finds the lowest grade course in a semester

    Args:
        COURSE_INFO data[]: array of COURSE_INFO structs
        int size: the length of data array
    return: COURSE_INFO worstCourse: the course with the lowest grade
    */
    COURSE_INFO worstCourse;

    worstCourse.grade = 100;
    for (int i = 0; i < size; i++)
    {
        if (data[i].grade <= worstCourse.grade)
        {
            worstCourse.grade = data[i].grade;
            worstCourse.courseNum = data[i].courseNum;
        }
    }
    return worstCourse;
}

int getExercisesInCourse(int exercises[], int courseNum)
{
    /*this function gets the exercises from a specific course,
    modify the first and last grades, and prints the grades back to the user

    Args:
        int courseNum: current course number
    return: none
    */
    int numOfExercises;

    printf("How many exercises were given in course #%d? ", courseNum);
    scanf("%d", &numOfExercises);
    printf("\n");
    printf("Enter exercises grades: \n");
    for (int i = 0; i < numOfExercises; i++)
    {
        scanf("%d", &exercises[i]);
    }
    exercises[0] = 30;
    exercises[numOfExercises - 1] = 100;
    printf("Exercise grades: ");
    for (int i = 0; i < numOfExercises; i++)
    {
        printf("%d ", exercises[i]);
    }
    printf("\n");
    return numOfExercises;
}

int findFailPass(int grades[], int size)
{
    /*this function finds two grade of which the first one did not pass,
    and the second one did
    the run time of this function is O(size)

    Args:
        int grades[]: grade list
        int size: length of grade list
    return: int gradeIndex: the index of the first grade from the two
    */
    bool notFound = true;
    int gradeIndex;

    for (int i = 0; i < size - 1 && notFound; i++)
    {
        if (grades[i] <= PASS_GRADE && grades[i + 1] >= PASS_GRADE)
        {
            notFound = false;
            gradeIndex = i;
        }
    }
    printf("Index of Fail-Pass is: %d\n", gradeIndex);
    return gradeIndex;
}

int reorderGrades(int grades[], int size, int limit)
{
    /*record grades from an array and check which of them did not pass

    the function check grades array and place every grade that under the limit
    at the start of the array
    the run time of this function is O(size)
    Args:
        int grades[]: array of grades
        int size: length of grades array
        int limit: the threshold of the grade to compare with
    return: int i: the number of grades that under the limit
    */
    int i = 0, j = 1;
    int tempGrade;
    while (i < size && j < size)
    {
        if (grades[i] < limit)
        {
            i++;
        }
        if ((grades[j] < limit) && (grades[j - 1] >= limit))
        {
            if (grades[i] >= limit)
            {
                tempGrade = grades[i];
                grades[i] = grades[j];
                grades[j] = tempGrade;
            }
        }
        else
        {
            j++;
        }
    }
    return i;
}
