#include <stdio.h>
#define BASIC_PIZZA_PRICE 60.0
#define OLIVES_PRICE 10
#define MUSHROOMS_PRICE 12

void main()
{
    int i, m, k;
    int id;
    
    printf("Welcome to MTA-Pizza!\n\n");
    for (i = 0; i < 3; i++)
    {

        for (m = 0; m <(5-(i*2)) ; m++)
        {
            printf("*");    
        }
        printf("\n");
        for (k = 0; k<=i; k++)
        {
            printf(" ");
        }
    }

    printf("\nPlease enter your ID number: ");
    scanf("%d", &id);
    
    printf("Our menu:\n");
    printf("*********\n");
    printf("Basic pizza: %4.2f NIS for 40x40 size pizza\n", BASIC_PIZZA_PRICE);
    printf("Toppings for basic size pizza:\n");
    printf("Olives: %d NIS\n", OLIVES_PRICE);
    printf("Mushrooms: %d NIS\n", MUSHROOMS_PRICE);

    printf("Your order details:\n");
    printf("*******************\n");
    printf("ID number: %09d\n", id);
    printf("thank you for your order!");

    
}