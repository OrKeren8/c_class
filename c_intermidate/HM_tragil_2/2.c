#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_POL_SIZE 100
#define MAX_INPUT_STRING_SIZE 1000

typedef struct monom
{
    int coefficient; // המקדם
    int power;       // החזקה
} Monom;

Monom *getPolynom(unsigned int *polynomSize);
void printPolyMul(Monom polynom1[], unsigned int polynom1Size, Monom polynom2[], unsigned int polynom2Size);
void beautifyPol(Monom uglyPol[], unsigned int size, Monom **goodPol, unsigned int *goodPolSize);
void printPol(Monom pol[], unsigned int PolLen);
void printPolySum(Monom polynom1[], unsigned int polynom1Size, Monom polynom2[], unsigned int polynom2Size);

void main()
{
    Monom *polynom1, *polynom2;              // The input polynoms
    unsigned int polynom1Size, polynom2Size; // The size of each polynom

    printf(" Please enter the first polynom:\n");
    polynom1 = getPolynom(&polynom1Size); // get polynom 1

    printf("Please enter the second polynom:\n");
    polynom2 = getPolynom(&polynom2Size); // get polynom 2

    printf("The multiplication of the polynoms is:\n"); // print the multiplication
    printPolyMul(polynom1, polynom1Size, polynom2, polynom2Size);
    printf("\n");

    printf("The sum of the polynoms is:\n"); // print the sum
    printPolySum(polynom1, polynom1Size, polynom2, polynom2Size);
    printf("\n");

    free(polynom1); // releasing all memory allocations
    free(polynom2);
}

Monom *getPolynom(unsigned int *polynomSize)
{
    /*get an array of polynom pointers from user input string

    args:
        unsigned int *polynomSize: output parameter, return the size of the array
    return: Monom *polynom: pointer to monom arrays
    */
    char string[MAX_INPUT_STRING_SIZE] = "";
    char seps[] = " ";
    char *token;
    Monom inputPolynom[MAX_POL_SIZE] = {0}, tmpMonom, *outputPolynom;
    unsigned int outputPolSize;

    gets(string);

    // build the polynom item by item
    token = strtok(string, seps);
    while (token != NULL)
    {
        // read a monom into it's place in the array
        sscanf(token, "%d", &tmpMonom.coefficient);
        token = strtok(NULL, seps);
        sscanf(token, "%d", &tmpMonom.power);
        token = strtok(NULL, seps);

        if (inputPolynom[tmpMonom.power].coefficient == 0)
            inputPolynom[tmpMonom.power] = tmpMonom;
        else
        {
            (inputPolynom[tmpMonom.power].coefficient) += tmpMonom.coefficient;
            (inputPolynom[tmpMonom.power].power) = tmpMonom.power;
        }
    }

    beautifyPol(inputPolynom, MAX_POL_SIZE, &outputPolynom, &outputPolSize);

    *polynomSize = outputPolSize;
    return outputPolynom;
}

void beautifyPol(Monom uglyPol[], unsigned int size, Monom **goodPol, unsigned int *goodPolSize)
{
    /*take unordered polynom and returns one with only the coefficients that are not equal to 0

    Args:
        Monom uglyPol[]: ugly and not ordered polynom
        unsigned int size: uglyPol length
        Monom **goodPol: pointer to dynamic monoms array aka the new Pol
        unsigned int *goodPolSize: goodPol length
    return: NULL
    */

    int monomsCount = 0;
    unsigned int outputPolynomIndex = 0;
    Monom *outputPol;

    // check how many monoms with only coefficients != 0
    for (unsigned int i = 0; i < size; i++)
    {
        if (uglyPol[i].coefficient != 0)
        {
            monomsCount += 1;
        }
    }

    // create output polynom
    outputPol = (Monom *)calloc(monomsCount, sizeof(Monom));
    if (outputPol == NULL)
    {
        printf("Memory Allocation Error!");
        exit(1); // exit the program
    }

    // fill the output polynom
    for (unsigned int i = 0; i < size; i++)
    {
        if (uglyPol[i].coefficient != 0)
        {
            outputPol[outputPolynomIndex] = uglyPol[i];
            outputPolynomIndex++;
        }
    }

    *goodPolSize = outputPolynomIndex;
    *goodPol = outputPol;
}

void printPolyMul(Monom polynom1[], unsigned int polynom1Size, Monom polynom2[], unsigned int polynom2Size)
{
    /*print the multiplication of two polynoms

    Args:
        Monom polynom1[]: first array of monoms, aka polynom 1
        unsigned int polynom1Size: the length of polynom1
        Monom polynom2[]: second array of monoms, aka polynom 2
        unsigned int polynom2Size: the length of polynom2
    return: NULL
    */

    // create a polynom that can hold the multiplication
    unsigned int highestPower, currentPower, goodPolLen;
    Monom *polMul, *goodPolMul;

    highestPower = polynom1[polynom1Size - 1].power + polynom2[polynom2Size - 1].power;
    polMul = (Monom *)calloc(highestPower + 1, sizeof(Monom));

    // calculate the mul
    for (unsigned int i = 0; i < polynom1Size; i++)
    {
        for (unsigned int j = 0; j < polynom2Size; j++)
        {
            currentPower = polynom1[i].power + polynom2[j].power;
            polMul[currentPower].power = currentPower;
            polMul[currentPower].coefficient += polynom1[i].coefficient * polynom2[j].coefficient;
        }
    }

    beautifyPol(polMul, highestPower + 1, &goodPolMul, &goodPolLen);
    free(polMul);
    printPol(goodPolMul, goodPolLen);
    free(goodPolMul);
}

void printPol(Monom pol[], unsigned int PolLen)
{
    /*prints a polynom aka monom array

    Args:
        Monom pol[]: polynom to print
        int PolLen: polynom's length
    return: NULL
    */
    for (int i = PolLen - 1; i >= 0; i--)
    {
        if (i == (int)(PolLen - 1))
        {
            if (pol[i].coefficient != 1 && (pol[i].coefficient != -1))
                printf("%d", pol[i].coefficient);
            else if (pol[i].coefficient < 0)
                printf("-");
        }
        else
        {
            if (pol[i].coefficient >= 0)
            {
                printf(" + ");
                if (pol[i].coefficient != 1)
                    printf("%d", pol[i].coefficient);
            }
            else
            {
                if (pol[i].coefficient != 1)
                {
                    printf(" - ");
                    printf("%d", -1 * pol[i].coefficient);
                }
                else
                    printf("-");
            }
        }
        if (pol[i].power == 1)
            printf("X");
        else if (pol[i].power >= 2)
            printf("X^%d", pol[i].power);
    }
}

void printPolySum(Monom polynom1[], unsigned int polynom1Size, Monom polynom2[], unsigned int polynom2Size)
{
    /*print the sum of two polynoms

    Args:
        Monom polynom1[]: first polynom
        int polynom1Size: polynom1 length
        Monom polynom2[]: second polynom
        int polynom2Size:polynom2 length
    return: NULL
    */
    Monom *rawSumPol, *sumPol;
    unsigned int sumPolLen, rawSumPolLen;

    // check the max size of sum pol
    if (polynom1[polynom1Size - 1].power > polynom2[polynom2Size - 1].power)
        rawSumPolLen = polynom1[polynom1Size - 1].power + 1;
    else
        rawSumPolLen = polynom2[polynom2Size - 1].power + 1;

    rawSumPol = (Monom *)calloc(rawSumPolLen, sizeof(Monom));

    // fill raw polynom
    for (unsigned int i = 0; i < polynom1Size; i++)
    {
        rawSumPol[polynom1[i].power].coefficient += polynom1[i].coefficient;
        rawSumPol[polynom1[i].power].power = polynom1[i].power;
    }
    for (unsigned int i = 0; i < polynom2Size; i++)
    {
        rawSumPol[polynom2[i].power].coefficient += polynom2[i].coefficient;
        rawSumPol[polynom2[i].power].power = polynom2[i].power;
    }

    beautifyPol(rawSumPol, rawSumPolLen, &sumPol, &sumPolLen);
    free(rawSumPol);
    printPol(sumPol, sumPolLen);
    free(sumPol);
}