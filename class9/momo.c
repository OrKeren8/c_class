// Roy Kalfon
// 315254243
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX_NAME_LEN 22
#define MAX_FULL_NAME_LEN 22
#define MAX_FIRST_NAME 11
#define MAX_LAST_NAME 11
#define MAX_COURSES 10
#define NUM_OF_GROUP 3
#define GROUP_STUDENT_NUMBER 6
#define TOTAL_STUDENTS 18
#define GROUP_A 0
#define GROUP_B 1
#define GROUP_C 2

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
void getStudentInfo(STUDENT studata[][GROUP_STUDENT_NUMBER], int groupNum);
int getStudentNames(STUDENT stuData[][GROUP_STUDENT_NUMBER], int rows, int cols, int courseNum, char stuNames[][MAX_FULL_NAME_LEN]);
void replaceNamesLois(char[][MAX_FULL_NAME_LEN], int numOfStuInCours);
void removingLex(char[][MAX_FULL_NAME_LEN], int numOfStuInCours);
void prindgradesOfSpecCourse(char nameArr[][MAX_FULL_NAME_LEN], STUDENT stuData[][GROUP_STUDENT_NUMBER], int courseNum, int gradesOfCourse[NUM_OF_GROUP][GROUP_STUDENT_NUMBER]);

void main()
{
	STUDENT stuArrGroup[NUM_OF_GROUP][GROUP_STUDENT_NUMBER];
	char stuNames[TOTAL_STUDENTS][MAX_FULL_NAME_LEN];
	int gradesOfCourse[NUM_OF_GROUP][GROUP_STUDENT_NUMBER];
	int courseNumForNames;
	int numOfstuInSelectedCourse;
	int i = 0;
	int j = 0;
	printf("********************\n");
	printf("* Welcome Students *\n");
	printf("********************\n");
	printf("Enter students data for GROUP A:\n");
	printf("________________________________\n");
	getStudentInfo(stuArrGroup, GROUP_A);
	printf("Enter students data for GROUP B:\n");
	printf("________________________________\n");
	getStudentInfo(stuArrGroup, GROUP_B);
	printf("Enter students data for GROUP C:\n");
	printf("________________________________\n");
	getStudentInfo(stuArrGroup, GROUP_C);
	printf("Enter course number: ");
	scanf("%d", &courseNumForNames);
	// getStudentNames(stuArrGroup, NUM_OF_GROUP, GROUP_STUDENT_NUMBER, courseNumForNames, stuNames);
	numOfstuInSelectedCourse = getStudentNames(stuArrGroup, NUM_OF_GROUP, GROUP_STUDENT_NUMBER, courseNumForNames, stuNames);
	for (i = 0; i < numOfstuInSelectedCourse; i++)
	{
		for (j = 0; stuNames[i][j] != '\0'; j++)
		{
			printf("%c", stuNames[i][j]);
		}
		printf("\n");
	}
}

void getStudentInfo(STUDENT studata[][GROUP_STUDENT_NUMBER], int groupNum)
{
	int i;
	int j;
	char firstname[MAX_FIRST_NAME];
	char lastname[MAX_LAST_NAME];
	char fullName[MAX_NAME_LEN];
	for (i = 0; i < GROUP_STUDENT_NUMBER; i++)
	{
		printf("Enter student first name and last name (seperated by spaces):");
		scanf("%s %s", &firstname, &lastname);
		strcpy(fullName, firstname);
		strcat(fullName, " ");
		strcat(fullName, lastname);
		strcpy(studata[groupNum][i].name, fullName);
		printf("Enter student ID: ");
		scanf("%d", &studata[groupNum][i].identity);
		printf("Enter number of courses taken in semester A: ");
		scanf("%d", &studata[groupNum][i].nofCourses);
		for (j = 0; j < studata[groupNum][i].nofCourses; j++)
		{
			printf("Enter Course number and grade: ");
			scanf("%d %d", &studata[groupNum][i].course_info[j].courseNum, &studata[groupNum][i].course_info[j].grade);
		}
	}
}
int getStudentNames(STUDENT stuData[][GROUP_STUDENT_NUMBER], int rows, int cols, int courseNum, char stuNames[][MAX_FULL_NAME_LEN])
{
	int i;
	int j;
	int k;
	int m;
	int p;
	int numOfStudenInCourse = 0;
	printf("Names of students in course #%d:", courseNum);
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			for (k = 0; k < stuData[i][j].nofCourses; k++)
			{
				if (stuData[i][j].course_info[k].courseNum == courseNum)
				{
					if (i == GROUP_A)
					{
						strcpy(stuNames[numOfStudenInCourse], "GroupA ");
					}
					else if (i == GROUP_B)
					{
						strcpy(stuNames[numOfStudenInCourse], "GroupB ");
					}
					else if (i == GROUP_C)
					{
						strcpy(stuNames[numOfStudenInCourse], "GroupC ");
					}
					strcat(stuNames[numOfStudenInCourse], stuData[i][j].name);

					numOfStudenInCourse += 1;
				}
			}
		}
	}
	return numOfStudenInCourse;
}

void repStuName(char nameArr[TOTAL_STUDENTS][MAX_FULL_NAME_LEN], int numOfStuInCourse)
{
	int i;
	int j;
	int k;
	int m = 0;
	int checkSpace = 1;
	char tempStr[MAX_FIRST_NAME];
	for (i = 0; i < numOfStuInCourse; i++)
	{
		for (j = 0; nameArr[i][j + 2] != '\0'; j++)
		{
			if (nameArr[i][j] == 'l' && nameArr[i][j + 1] == 'o' && nameArr[i][j + 2] == 'i' && nameArr[i][j + 2] == 's')
			{
				nameArr[i][j + 1] = 'a';
				nameArr[i][j + 2] = 'n';
				nameArr[i][j + 3] = 'e';
			}
			// tempStr[j] = nameArr[i][j];
			// checkSpace++;
		}
		/*	if (strcmp(tempStr, "Lois") == 0) {
				nameArr[i][1] = 'a';
				nameArr[i][2] = 'n';
				nameArr[i][3] = 'e';
			}
			for (k = checkSpace+1; nameArr[i][k] != '\0'; k++) {
				tempStr[m] = nameArr[i][k];
				m++;
			}
			if (strcmp(tempStr, "Lois") == 0) {
				nameArr[i][checkSpace+1] = 'a';
				nameArr[i][checkSpace+2] = 'n';
				nameArr[i][checkSpace+3] = 'e';
			}
			*/
	}
}

void removingLex(char nameArr[][MAX_FULL_NAME_LEN], int numOfStuInCours)
{
	int i;
	int j;
	int checkLexCounter = 0;
	bool found;

	for (i = 0; i < numOfStuInCours; i++)
	{
		found = false;
		for (j = 0; nameArr[i][j + 2] != '\0' && !found; j++)
		{
			if (nameArr[i][j] == 'l' && nameArr[i][j + 1] == 'e' && nameArr[i][j + 2] == 'x')
			{
				found = true;
			}
		}
		if (found)
		{
			nameArr[i][0] = '\0';
		}
	}
	eraseRowFromArray(nameArr, numOfStuInCours);
}
void eraseRowFromArray(char nameArr[][MAX_FULL_NAME_LEN], int numOfStuInCours)
{
	int read;
	int write = 0;
	int i = 0;
	int j = 0;
	for (read = 0; read < numOfStuInCours; read++)
	{
		if (nameArr[read][0] != '\0')
		{
			strcpy(nameArr[write], nameArr[read]);
			write++;
		}
	}
}

void prindgradesOfSpecCourse(char nameArr[][MAX_FULL_NAME_LEN], STUDENT stuData[][GROUP_STUDENT_NUMBER], int courseNum, int gradesOfCourse[NUM_OF_GROUP][GROUP_STUDENT_NUMBER])
{
	int i;
	int j;
	int m;
	int k = 0;
	int numOfStudenInCourseinGroupA;
	int numOfStudenInCourseinGroupB;
	int numOfStudenInCourseinGroupC;
	// int gradesOfCourse[NUM_OF_GROUP][GROUP_STUDENT_NUMBER];
	printf("Grades in course#%d:", courseNum);
	for (i = 0; i < TOTAL_STUDENTS; i++)
	{
		// for(j=0;j)
	}
	printf("groupA: ");
	for (m = 0; m < numOfStudenInCourseinGroupA; m++)
	{
		printf(" %d", gradesOfCourse[GROUP_A][m]);
	}
	printf("\n");
	printf("groupB: ");
	for (m = 0; m < numOfStudenInCourseinGroupB; m++)
	{
		printf(" %d", gradesOfCourse[GROUP_B][m]);
	}
	printf("\n");
	printf("groupC: ");
	for (m = 0; m < numOfStudenInCourseinGroupC; m++)
	{
		printf(" %d", gradesOfCourse[GROUP_C][m]);
	}
}
void printMaxzgrade(STUDENT stuData[][GROUP_STUDENT_NUMBER], int courseNum, int gradesOfCourse[NUM_OF_GROUP][GROUP_STUDENT_NUMBER])
{
	int i;
	int j;
	int k;
	int m;
	int maxA = 0;
	int secondMaxA = 0;
	int maxB = 0;
	int secondMaxB = 0;
	int maxC = 0;
	int secondMaxC = 0;
	int checkNullA = 0;
	int checkNullB = 0;
	int checkNullC = 0;
	printf("Maximum grades in course#%d:\n", courseNum);
	printf("GroupA: ");
	for (i = 0; i < GROUP_STUDENT_NUMBER; i++)
	{
		for (j = 0; j < stuData[GROUP_A][i].nofCourses; j++)
		{
			if (stuData[GROUP_A][i].course_info[j].courseNum == courseNum)
			{
				checkNullA++;
			}
		}
	}
	if (checkNullA == 0)
	{
		printf("no grades found in group");
	}
	else
	{
		for (k = 0; k < GROUP_STUDENT_NUMBER; k++)
		{
			if (gradesOfCourse[GROUP_A][k] > maxA)
			{
				maxA = gradesOfCourse[GROUP_A][k];
			}
		}
		for (m = 0; m < GROUP_STUDENT_NUMBER; m++)
		{
			if ((gradesOfCourse[GROUP_A][m] > secondMaxA) && (gradesOfCourse[GROUP_A][m] != maxA))
			{
				secondMaxA = gradesOfCourse[GROUP_A][m];
			}
		}
		printf("max grade is: %d and second max is: %d\n", maxA, secondMaxA);
	}

	printf("GroupB: ");
	for (i = 0; i < GROUP_STUDENT_NUMBER; i++)
	{
		for (j = 0; j < stuData[GROUP_B][i].nofCourses; j++)
		{
			if (stuData[GROUP_B][i].course_info[j].courseNum == courseNum)
			{
				checkNullB++;
			}
		}
	}
	if (checkNullB == 0)
	{
		printf("no grades found in group");
	}
	else
	{
		for (k = 0; k < GROUP_STUDENT_NUMBER; k++)
		{
			if (gradesOfCourse[GROUP_B][k] > maxB)
			{
				maxB = gradesOfCourse[GROUP_B][k];
			}
		}
		for (m = 0; m < GROUP_STUDENT_NUMBER; m++)
		{
			if ((gradesOfCourse[GROUP_B][m] > secondMaxB) && (gradesOfCourse[GROUP_B][m] != maxB))
			{
				secondMaxB = gradesOfCourse[GROUP_B][m];
			}
		}
		printf("max grade is: %d and second max is: %d\n", maxB, secondMaxB);
	}

	printf("GroupC: ");
	for (i = 0; i < GROUP_STUDENT_NUMBER; i++)
	{
		for (j = 0; j < stuData[GROUP_C][i].nofCourses; j++)
		{
			if (stuData[GROUP_C][i].course_info[j].courseNum == courseNum)
			{
				checkNullC++;
			}
		}
	}
	if (checkNullC == 0)
	{
		printf("no grades found in group");
	}
	else
	{
		for (k = 0; k < GROUP_STUDENT_NUMBER; k++)
		{
			if (gradesOfCourse[GROUP_C][k] > maxC)
			{
				maxC = gradesOfCourse[GROUP_C][k];
			}
		}
		for (m = 0; m < GROUP_STUDENT_NUMBER; m++)
		{
			if ((gradesOfCourse[GROUP_C][m] > secondMaxC) && (gradesOfCourse[GROUP_C][m] != maxC))
			{
				secondMaxC = gradesOfCourse[GROUP_C][m];
			}
		}
		printf("max grade is: %d and second max is: %d\n", maxC, secondMaxC);
	}
}