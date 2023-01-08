#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define SIZE 10
#define MAX_INT_SIZE 10
#define FUNC_COUNT 9
#define EXIT 0

// Add your recursive functions declarations here
bool isEven(int num, int dig);
int howManyPaths(int x, int y);
int biggestLowPower(int x, int num);
int partSum(int num);
void intToStr(int num, char s[]);
void fillMaxPrefixesArray(int numbers[], int n, int maxPrefixesArray[]);
void getMinToStart(int numbers[], int n);
void combineArrays(int sortedArr1[], int size1, int sortedArr2[], int size2);
int countSmaller(int arr[], int start, int end, int num);

// Testing functions
int readArray(int data[], int maxSize);
void printArray(int data[], int size);
void bubbleSort(int arr[], int size);
void swap(int arr[], int i, int j);
void checkQ1();
void checkQ2();
void checkQ3();
void checkQ4();
void checkQ5();
void checkQ6();
void checkQ7();
void checkQ8();
void checkQ9();

/*********** main - don't make any changes here !!! ***************************/
void main()
{
    int funcNum;
    bool exit = false;

    while (!exit)
    {
        printf("Enter the number of function you want to check (1-%d) or %d to exit the program: ", FUNC_COUNT, EXIT);
        scanf("%d", &funcNum);

        switch (funcNum)
        {
        case 1:
            checkQ1();
            break;
        case 2:
            checkQ2();
            break;
        case 3:
            checkQ3();
            break;
        case 4:
            checkQ4();
            break;
        case 5:
            checkQ5();
            break;
        case 6:
            checkQ6();
            break;
        case 7:
            checkQ7();
            break;
        case 8:
            checkQ8();
            break;
        case 9:
            checkQ9();
            break;
        case EXIT:
            exit = true;
            break;
        default:
            printf("Invalid choice.\n");
        }
        printf("\n");
    }
}

/***************** Testing functions - don't make any changes here!!! ***************/
void checkQ1()
{
    int num, dig;

    printf("Enter a positive integer: ");
    scanf("%d", &num);
    printf("Enter a digit: ");
    scanf("%d", &dig);
    if (isEven(num, dig))
    {
        printf("%d appears even number of times in %d\n", dig, num);
    }
    else
    {
        printf("%d appears odd number of times in %d\n", dig, num);
    }
}

void checkQ2()
{
    int x, y;

    printf("Enter two non-negative integers: ");
    scanf("%d%d", &x, &y);
    printf("There are %d paths from (0,0) to (%d,%d)\n", howManyPaths(x, y), x, y);
}

void checkQ3()
{
    int x, num;

    printf("Enter two positive integers: ");
    scanf("%d%d", &x, &num);
    printf("The biggest power of %d which is smaller than %d is %d\n", x, num, biggestLowPower(x, num));
}

void checkQ4()
{
    int num;

    printf("Enter a positive integer: ");
    scanf("%d", &num);
    printf("The partial sum of %d digits is %d\n", num, partSum(num));
}

void checkQ5()
{
    int num;
    char string[MAX_INT_SIZE + 1];

    printf("Enter a positive integer: ");
    scanf("%d", &num);
    intToStr(num, string);
    printf("The string representing the integer %d is %s\n", num, string);
}

void checkQ6()
{
    int numbers[SIZE];
    int maxPrefixes[SIZE];
    int size;

    size = readArray(numbers, SIZE);
    fillMaxPrefixesArray(numbers, size, maxPrefixes);
    printf("Max prefixes array: ");
    printArray(maxPrefixes, size);
}

void checkQ7()
{
    int numbers[SIZE];
    int size;

    size = readArray(numbers, SIZE);
    getMinToStart(numbers, size);
    printf("The minimal number is: %d\n", numbers[0]);

    // check if all other numbers are still inb array
    bubbleSort(numbers, size);
    printf("The sorted array: ");
    printArray(numbers, size);
}

void checkQ8()
{
    int arr1[SIZE], arr2[2 * SIZE];
    int size1, size2;

    size1 = readArray(arr1, SIZE);
    size2 = readArray(arr2, 2 * SIZE - size1);

    // sort arrays
    bubbleSort(arr1, size1);
    bubbleSort(arr2, size2);

    combineArrays(arr1, size1, arr2, size2);
    printf("The combined sorted array: ");
    printArray(arr2, size1 + size2);
}

void checkQ9()
{
    int numbers[SIZE];
    int size, num;

    // read numbers from user (assumption: numbers are different from each other)
    size = readArray(numbers, SIZE);
    bubbleSort(numbers, size);

    printf("Please enter an integer: ");
    scanf("%d", &num);

    printf("There are %d numbers in array that are smaller than %d\n", countSmaller(numbers, 0, size - 1, num), num);
}

// This function reads a series of integers from user into data array.
// The function will first ask the user to enter the number of integers he wishes
// to enter to array. If number is bigger than maxSize, then only the first masSize
// numbers will be read.
// The fucntion returns the arrays logical size (number of elements inserted into array).
int readArray(int data[], int maxSize)
{
    int count;
    int i; // number of elements inserted into array

    printf("How many numbers would you like to enter to array ? (no more than %d) ", maxSize);
    scanf("%d", &count);
    if (count > maxSize)
    {
        count = maxSize;
    }
    printf("Please enter %d integers: ", count);

    for (i = 0; i < count; i++)
    {
        scanf("%d", &data[i]); // read current input number
    }

    return count;
}

// This function prints the first size elements of data array (integers).
void printArray(int data[], int size)
{
    int i;

    for (i = 0; i < size; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");
}

// This functions sorts arr in increasing order using bubble sort algorithm
void bubbleSort(int arr[], int size)
{
    int i, j;

    for (i = 0; i < size - 1; i++)
        for (j = 0; j < size - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr, j, j + 1);
}

void swap(int arr[], int i, int j)
{
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

/******************************* Recursive functions **************************/
// Add recursive functions implementation here

bool isEven(int num, int dig)
{
    /*this function checks if the number of appearances of dig in num is even

    Args:
        int num: the number to check from
        int dig: the digit to  find in the number
    return: none
    */
    if (num == 0)
    {
        return true;
    }
    if ((num % 10) == dig)
    {
        return !isEven(num / 10, dig);
    }
    else
    {
        return isEven(num / 10, dig);
    }
}

int howManyPaths(int x, int y)
{
    /*this function finds the number of paths from grid
    of (0,0) to (x,y)

    Args:
        int x: x axis of the top right coordinate
        int y: y axis of the top right coordinate
    return: int paths: the number of paths
    */
    int paths = 0;

    if (x == 0 && y == 0)
    {
        return 1;
    }
    if (y > 0)
        paths += howManyPaths(x, y - 1);
    if (x > 0)
        paths += howManyPaths(x - 1, y);
    return paths;
}

int biggestLowPower(int x, int num)
{
    /*this function finds the biggest power of x
    that is under the value of num

    Args:
        int x: the number we want to power
        int num: the value the max power must be under
    return: int max power of x under num

    */
    if (x > num)
    {
        return 1;
    }
    return x * biggestLowPower(x, num / x);
}

int partSum(int num)
{
    /*this function finds the sum of every digit within a given
    number, but the most left side digit (lsb)

    Args:
        int num: given number to check
    return: sum of digits except the lsb
    */
    int temp = num, counter = 1;

    if (temp <= 9)
        return 0;
    while (temp > 9)
    {
        temp /= 10;
        counter *= 10;
    }
    return temp + partSum(num - (counter * temp));
}

void intToStr(int num, char s[])
{
    /*this function suppose to create a string from a integer number
    the number 0 made me create lot of cases :(

    Args:
        int num: int number to create a string from
        char s[]: the string to fill in the number representation
    return: none
    */
    if (num == -1)
    {
        s[0] = 0;
        return;
    }
    if (num == 0)
    {
        s[0] = '0';
        intToStr(-1, s);
    }
    else
    {
        if ((num / 10) != 0)
        {
            intToStr(num / 10, s);
        }
        else
        {
            intToStr(-1, s);
        }
    }
    s[strlen(s) + 1] = 0;
    s[strlen(s)] = ('0' + (num % 10));
}

void fillMaxPrefixesArray(int numbers[], int n, int maxPrefixesArray[])
{
    /*get a list of numbers and fill in maxPrefixesArray[i] the max number from numbers[0] to numbers[i]

    Args:
        int numbers[]: list of numbers
        int n: len of numbers to check within the list
        int maxPrefixesArray[]: output list
    return: none
    */
    if (n == 1)
    {
        maxPrefixesArray[n - 1] = numbers[n - 1];
        return;
    }
    fillMaxPrefixesArray(numbers, n - 1, maxPrefixesArray);
    if (numbers[n - 1] > maxPrefixesArray[n - 2])
    {
        maxPrefixesArray[n - 1] = numbers[n - 1];
    }
    else
    {
        maxPrefixesArray[n - 1] = maxPrefixesArray[n - 2];
    }
}

void getMinToStart(int numbers[], int n)
{
    /*this function place the minimum number at the first spot of a given list

    Args:
        int numbers[]: array of numbers to find the minimum from
        int n: len of the array
    return: none
    */
    if (n < 2)
    {
        return;
    }
    if (numbers[0] > numbers[n - 1])
    {
        swap(numbers, 0, n - 1);
    }
    getMinToStart(numbers, n - 1);
}

void combineArrays(int sortedArr1[], int size1, int sortedArr2[], int size2)
{
    /*this function combine two sorted arrays into one

    Args:
        int sortedArr1[]: first sorted array
        int size1: len of sortedArr1[]
        int sortedArr2[]: second sorted array ,the one to fill in the combination of the two arrays
        int size2: initiate len of sortedArr2[]
    return: none
    */
    int i;
    if (size1 == 0)
    {
        return;
    }
    sortedArr2[size2] = sortedArr1[size1 - 1];
    size2++;
    size1--;
    for (i = size2 - 1; i > 0; i--)
    {
        if (sortedArr2[i] < sortedArr2[i - 1])
        {
            swap(sortedArr2, i, i - 1);
        }
    }
    combineArrays(sortedArr1, size1, sortedArr2, size2);
}

int countSmaller(int arr[], int start, int end, int num)
{
    /*this function search how many numbers under a specific number2 in a given array

    Args:
        int arr[]: array of sorted numbers
        int start: start index of the array
        int end: stop index of the array
        int num: the number to compare with
    return: int: counter represent the amount of numbers that are smaller than "num"

    */
    int mid = (end + 1 + start) / 2;

    if (end < start)
    {
        return 0;
    }
    if (num > arr[mid])
    {
        return ((mid + 1 - start) + countSmaller(arr, mid + 1, end, num));
    }
    else
    {
        return countSmaller(arr, start, mid - 1, num);
    }
}