#include <stdio.h>
#include <stdlib.h>

void main()
{
    Monom *polynom1, *polynom2;              // The input polynoms
    unsigned int polynom1Size, polynom2Size; // The size of each polynom

    printf("Please enter the first polynom:\n");
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