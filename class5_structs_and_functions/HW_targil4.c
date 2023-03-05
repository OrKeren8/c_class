//Or Keren
//315155531

#include <stdio.h>
#include <stdbool.h>

//sizes
#define BASIC_PIZZA_LENGTH 40
#define BASIC_PIZZA_WIDTH 50
#define BASIC_PIZZA_SIZE (BASIC_PIZZA_LENGTH * BASIC_PIZZA_WIDTH)

//prices
#define BASIC_PIZZA_PRICE 70.0
#define DELIVERY_PRICE 15
#define TAX 17.0 / 100

//toppings
#define OLIVES_PRICE 10
#define OLIVES 'O'
#define MUSHROOMS_PRICE 12
#define MUSHROOMS 'M'
#define TOMATOES_PRICE 9
#define TOMATOES 'T'
#define PINEAPPLE_PRICE 14
#define PINEAPPLE 'P'

//dough
#define REGULAR_NAME 'r'
#define REGULAR_PRICE 0
#define VEGAN_NAME 'v'
#define VEGAN_PRICE 5
#define WHOLE_WHEAT_NAME 'w'
#define WHOLE_WHEAT_PRICE 3
#define GLUTEN_FREE_NAME 'f'
#define GLUTEN_FREE_PRICE 4

#define WHOLE_INDEX 1
#define WHOLE 1
#define HALF_INDEX 2
#define HALF 0.5
#define QUARTER_INDEX 3
#define QUARTER 0.25
#define NONE_INDEX 0
#define NONE 0

#define DELIVERY 1
#define PICK_UP 0

#define BACK_SPACE ' '

typedef struct Pizza {
    int length; // pizza length (cm)
    int width; // pizza width (cm)
    int size; // pizza size (cm)
    char doughType; // dough type ('r'/'v'/'w'/'f')
    double olives; // olives amount (0/1/0.5/0.25)
    double mushrooms; // mushrooms amount (0/1/0.5/0.25)
    double tomatoes; // tomatoes amount (0/1/0.5/0.25)
    double pineapple; // pineapple amount (0/1/0.5/0.25)
    char q1; // topping type on first quarter ('O'/'M'/'T'/'P')
    char q2; // topping type on second quarter ('O'/'M'/'T'/'P')
    char q3; // topping type on third quarter ('O'/'M'/'T'/'P')
    char q4; // topping type on fourth quarter ('O'/'M'/'T'/'P')
    double price; // pizza price (without tax)
}PIZZA;

struct Money{
        int tens;
        int fives;
        int twos;
        int ones;
    }typedef Money;

int getIDNumber();
void printMenu();
int getNumOfPizzas();
PIZZA getPizza(int pizzaNumber);
PIZZA getPizzaDimensions();
PIZZA getDoughType(PIZZA pizza);
PIZZA getToppings(PIZZA pizza);
double getToppingPart(double occupiedSpace);
PIZZA fillPizzaToppings(PIZZA pizza, double toppingPart, char toppingSymbol);
void printPizzaDetails(PIZZA pizza, int pizzaNumber);
void printPizza(PIZZA pizza);
char charToPrint(int x, int y, PIZZA pizza);
int getDelivery();
void getPayment(int totalPrice);
void printLogo();

void main()
{
    PIZZA pizza;
    double totalPrice = 0, totalPriceWithTax = 0;
    int id, numOfPizzas, delivery;

    printLogo();
    id = getIDNumber();
    printMenu();
    numOfPizzas = getNumOfPizzas();
    for (int pizzaNumber=1; pizzaNumber <= numOfPizzas; pizzaNumber++)
    {
        pizza = getPizza(pizzaNumber);
        totalPrice += pizza.price;
    }
    
    delivery = getDelivery();
    //calculate total price
    totalPrice += delivery * DELIVERY_PRICE;
    totalPriceWithTax = totalPrice + totalPrice * TAX;
    
    //print order details
    printf("Your order details:\n");
    printf("*******************\n");
    printf("ID number: %09d\n", id);
    printf("Number of pizzas: %d\n", numOfPizzas);
    if (delivery)
        printf("Delivery\n");
    else
        printf("Pick-up\n");
    printf("Total price: %.2f\n", totalPrice);
    printf("Total price with tax (rounded down): %d \n\n", (int)totalPriceWithTax);

    getPayment((int)totalPriceWithTax);

    printf("Thank you for your order!\n");  

}
        
void printLogo()
{
    /*print MTA pizza logo

    Args: none
    return: none
    */
    printf(" Welcome to MTA-Pizza!\n\n");
    for (int i = 0; i < 3; i++)
    {

        for (int m = 0; m <(5-(i*2)) ; m++)
        {
            printf("*");    
        }
        printf("\n");
        for (int m = 0; m<=i; m++)
        {
            printf(" ");
        }
    }
    printf("\n");
}

int getIDNumber()
{
    /*get user ID number
    get user id and validate if it is a real id number with check digit
    
    Args: none
    return: 
        int id: the id number of the user
    */
    int id, sum, wholeID;
    int currentCheckDigit, realCheckDigit;
    int digit, subDigit, i;
    bool validID = false;

    while (!validID)
    {
        sum = 0, i = 0;

        printf("Please enter your ID number: \n");
        scanf("%d", &id);
        wholeID = id;
        
        if(id <= 999999999 && id != 0)
        {
            currentCheckDigit = id%10;
            id = id/10;
            while(id > 0)
            {
                
                digit = id%10;
                id = id / 10;
                if (i%2)
                    digit *= 1;
                else
                    digit *= 2; 
                while(digit > 0)
                {
                    subDigit = digit%10;
                    digit = digit / 10;
                    sum += subDigit;
                }
                i ++;
            }
            
            realCheckDigit = 10 - (sum % 10);  // calculate id check digit
            if (realCheckDigit == currentCheckDigit)
                validID = true;
            else
                printf("Invalid check digit! Try again.\n");
        } 
        else
            printf("Invalid ID number! Try again.\n");
    }
    printf("\n");
    return wholeID;
}

void printMenu()
{
    /*print the menu of MTA pizza

    Args: none
    return: none
    */
    printf("Our menu:\n");
    printf("*********\n");
    printf("Basic pizza: %4.2f NIS for %dx%d size pizza\n\n", BASIC_PIZZA_PRICE, BASIC_PIZZA_LENGTH, BASIC_PIZZA_WIDTH);
        
    //toppings
    printf("Toppings for basic size pizza:\n");
    printf("Olives: %d NIS\n", OLIVES_PRICE);
    printf("Mushrooms: %d NIS\n", MUSHROOMS_PRICE);
    printf("Tomatoes: %d NIS\n", TOMATOES_PRICE);
    printf("Pineapple: %d NIS\n", PINEAPPLE_PRICE);
    printf("\n");

    //dough
    printf("Dough type for basic size pizza: \n");
    printf("Regular: %d NIS\n", REGULAR_PRICE);
    printf("Vegan: %d NIS\n", VEGAN_PRICE);
    printf("Whole wheat: %d NIS\n", WHOLE_WHEAT_PRICE);
    printf("Gluten free: %d NIS\n", GLUTEN_FREE_PRICE);
    printf("\n");
    
}

int getNumOfPizzas()
{
    /*get the number of pizzas the user wants to order
    validate if the number is greater than 0

    Args: none
    return: int numOfPizzas
    
    */
    int numOfPizzas = 0;
    bool validInput = false;
    while (!validInput)
    {
        printf("How many pizzas would you like to order? \n");
        scanf("%d", &numOfPizzas);
        if (numOfPizzas > 0)
            validInput = true;
        else
            printf("Invalid choice! Try again.\n");
    }
    return numOfPizzas;
}

PIZZA getPizza(int pizzaNumber)
{
    /*get single pizza

    get every parameter of the pizza and print it's details
    Args:   
        int pizzaNumber: index of the pizza
    return: none
    */
    PIZZA pizza;
    
    //starter
    printf("*************************************************\n");
    printf("Pizza #%d:\n\n", pizzaNumber);
    
    //order
    pizza = getPizzaDimensions();
    // printf("%d, %d, %d\n", pizza.length, pizza.width, pizza.size);
    pizza = getDoughType(pizza);
    // printf("%c %lf\n", pizza.doughType, pizza.price);
    pizza = getToppings(pizza);
    printPizzaDetails(pizza, pizzaNumber);
    return pizza;
}

PIZZA getPizzaDimensions()
{
    /*get the dimensions of the pizza from the user
    
    add pizza dimension price to pizza price
    Args: none
    return: Pizza pizza: pizza struct with its dimensions
    */
    //initiate pizza
    PIZZA pizza;
    pizza.price = 0;  // price of empty pizza 
    pizza.q1 = BACK_SPACE;
    pizza.q2 = BACK_SPACE;
    pizza.q3 = BACK_SPACE;
    pizza.q4 = BACK_SPACE;

    printf("Please enter your pizza's length (cm): ");
    scanf("%d", &pizza.length);
    while (((pizza.length % 2) != 0) || (pizza.length < 10) || (pizza.length > 40))
    {
        printf("Invalid length! Try again.\n");
        
        printf("Please enter your pizza's length (cm): "); 
        scanf("%d", &pizza.length);
    }
    printf("Please enter your pizza's width (cm): ");
    scanf("%d", &pizza.width);
    while (((pizza.width % 2) != 0) || (pizza.width < 10) || (pizza.width > 80))
    {
        printf("Invalid width! Try again.\n");
        
        printf("Please enter your pizza's width (cm): ");
        scanf("%d", &pizza.width);
    }
    printf("\n");

    pizza.size = pizza.length * pizza.width;
    pizza.price += ((double)pizza.size / BASIC_PIZZA_SIZE) * BASIC_PIZZA_PRICE;
    return pizza;
}

PIZZA getDoughType(PIZZA pizza)
{
    /*gets dough of single pizza from the user

    adds dough value to pizza price
    Args:
        PIZZA pizza: structure of PIZZA
    return: PIZZA pizza
    */
    int doughPrice = 0;
    
    printf("Please enter the pizza's dough type:\n");
    printf("%c - for regular\n", REGULAR_NAME);
    printf("%c - for vegan\n", VEGAN_NAME);
    printf("%c - for whole wheat\n", WHOLE_WHEAT_NAME);
    printf("%c - for gluten-free\n", GLUTEN_FREE_NAME);
    scanf(" %c", &pizza.doughType);
    while ((pizza.doughType != REGULAR_NAME) && (pizza.doughType != VEGAN_NAME) && (pizza.doughType != WHOLE_WHEAT_NAME) && (pizza.doughType != GLUTEN_FREE_NAME))
    {
        printf("Invalid choice! Try again.\n\n");
        printf("Please enter the pizza's dough type:\n");
        printf("%c - for regular\n", REGULAR_NAME);
        printf("%c - for vegan\n", VEGAN_NAME);
        printf("%c - for whole wheat\n", WHOLE_WHEAT_NAME);
        printf("%c - for gluten-free\n", GLUTEN_FREE_NAME);
        scanf(" %c", &pizza.doughType);
    }
    switch (pizza.doughType)
    {
        case REGULAR_NAME:
            doughPrice = REGULAR_PRICE;
            break;
        case VEGAN_NAME:
            doughPrice = VEGAN_PRICE;
            break;
        case WHOLE_WHEAT_NAME:
            doughPrice = WHOLE_WHEAT_PRICE;
            break;
        case GLUTEN_FREE_NAME:
            doughPrice = GLUTEN_FREE_PRICE;
    }
    printf("\n");
    pizza.price += ((double)pizza.size / BASIC_PIZZA_SIZE) * doughPrice;
    return pizza;
}

PIZZA getToppings(PIZZA pizza)
{
    /*gets the toppings of a single pizza

    add toppings price to pizza price
    Args: 
        PIZZA pizza: struct of PIZZA
    return: PIZZA pizza: PIZZA struct with topping part in a pizza
    */

    printf("Please choose the toppings: \n\n");
    printf("Olives (choose 0-3):\n");
    pizza.olives = getToppingPart(NONE);    
    pizza = fillPizzaToppings(pizza, pizza.olives, OLIVES);
    pizza.price += (((double)pizza.size * pizza.olives) / BASIC_PIZZA_SIZE) * OLIVES_PRICE;

    if (pizza.olives < 1)
    {
        printf("Mushrooms (choose 0-3):\n");
        pizza.mushrooms = getToppingPart(pizza.olives);
        pizza = fillPizzaToppings(pizza, pizza.mushrooms, MUSHROOMS);
        pizza.price += (((double)pizza.size * pizza.mushrooms) / BASIC_PIZZA_SIZE) * MUSHROOMS_PRICE;
    }

    if((pizza.olives + pizza.mushrooms) < 1)
    {
        printf("Tomatos (choose 0-3):\n");
        pizza.tomatoes = getToppingPart(pizza.olives + pizza.mushrooms);
        pizza = fillPizzaToppings(pizza, pizza.tomatoes, TOMATOES);
        pizza.price += (((double)pizza.size * pizza.tomatoes) / BASIC_PIZZA_SIZE) * TOMATOES_PRICE;
    }

    if (pizza.olives + pizza.mushrooms + pizza.tomatoes < 1)
    {
        printf("Pineapple (choose 0-3):\n");
        pizza.pineapple = getToppingPart(pizza.olives + pizza.mushrooms + pizza.tomatoes);
        pizza = fillPizzaToppings(pizza, pizza.pineapple, PINEAPPLE);
        pizza.price += (((double)pizza.size * pizza.pineapple) / BASIC_PIZZA_SIZE) * PINEAPPLE_PRICE;
    }
    
    return pizza;
}

double getToppingPart(double occupiedSpace)
{
    /*gets the part of a single topping in a pizza

    checks if there is any place for topping amount,
    if not ask again for smaller part
    Args: 
        PIZZA pizza: struct of PIZZA
    return: PIZZA pizza: PIZZA struct with topping part in a pizza
    */
    int toppingPartIndex;
    double toppingPart;
    bool isValidToppingPart = false;

    while (!isValidToppingPart)
    {
        printf("%d. None\n"
            "%d. Whole pizza\n"
            "%d. Half pizza\n"
            "%d. Quarter pizza\n", NONE_INDEX, WHOLE_INDEX, HALF_INDEX, QUARTER_INDEX);
        scanf("%d", &toppingPartIndex);
        while((toppingPartIndex != WHOLE_INDEX) && (toppingPartIndex != HALF_INDEX) && (toppingPartIndex != QUARTER_INDEX) && (toppingPartIndex != NONE_INDEX))
        {
            printf("Invalid choice! Try again.\n");
            scanf("%d", &toppingPartIndex);
        }
        switch (toppingPartIndex)
        {
            case NONE_INDEX:
                toppingPart = NONE;
                break;
            case WHOLE_INDEX:
                toppingPart = WHOLE;
                break;
            case HALF_INDEX:
                toppingPart = HALF;
                break;
            case QUARTER_INDEX:
                toppingPart = QUARTER;
        }
        if((occupiedSpace + toppingPart) <= 1)
        {
            isValidToppingPart = true;
        }
        else
        {
            printf("You have exceeded the maximum amount of toppings allowed on one pizza! Try again.\n");
        }
    }
    printf("\n");
    return toppingPart;
}

PIZZA fillPizzaToppings(PIZZA pizza, double toppingPart, char toppingSymbol)
{
    /*place topping symbol in every quarter of the pizza if necessary
    
    Args:
        PIZZA pizza: pizza struct
        double toppingPart: the amount of the current topping the user wants on his pizza
        char toppingSymbol: the symbol of current topping to print on the pizza
    return: PIZZA pizza: pizza struct with all the details 
    */
    if (toppingPart){
        if (pizza.q1 == BACK_SPACE){
            pizza.q1 = toppingSymbol;
            toppingPart -= QUARTER;
        }
        if (toppingPart){
            if (pizza.q2 == BACK_SPACE){
                pizza.q2 = toppingSymbol;
                toppingPart -= QUARTER;
            }
            if (toppingPart){
                if (pizza.q3 == BACK_SPACE){
                    pizza.q3 = toppingSymbol;
                    toppingPart -= QUARTER;
                }
                if (toppingPart){
                    if (pizza.q4 == BACK_SPACE){
                        pizza.q4 = toppingSymbol;
                        toppingPart -= QUARTER;
                    }
                }
            }
        }
    }
    return pizza;
}

void printPizzaDetails(PIZZA pizza, int pizzaNumber)
{
    /*print the details of current pizza and its index
    
    Args: 
        PIZZA pizza: pizza struct
        int pizzaNumber: index of current pizza
    return: PIZZA pizza: pizza struct with all the details
    */
    printf("Pizza #%d details:\n", pizzaNumber);
    printf("*******************\n");
    printf("Pizza size: %dx%d\n", pizza.length, pizza.width);
    printf("Pizza price (without tax): %.2f\n", pizza.price);

    printPizza(pizza);
}

void printPizza(PIZZA pizza)    
{
    /*print the pizza with chars, 

    for every (x,y) on the pizza check which char to print and print it
    Args:
        PIZZA pizza: pizza struct
    */
    for (int i = 0; i <  (pizza.width); i++)
        printf("%c", pizza.doughType);
    printf("\n");
    for (int y = 0; y <  pizza.length - 2; y++)
    {
        printf("%c", pizza.doughType);
        for (int x=0; x < pizza.width - 2; x++)
        {
            printf("%c", charToPrint(x, y, pizza));
        }
        printf("%c\n", pizza.doughType);
    }
    for (int i = 0; i <  (pizza.width); i++)
        printf("%c", pizza.doughType);
    printf("\n\n");
}

char charToPrint(int x, int y, PIZZA pizza)
{
    /*return the current topping symbol to print in the pizza
    
    Args:
        int x: current x axis 
        int y: current y axis
        PIZZA pizza: PIZZA struct
    return: char currentSymbol: current topping symbol to print 
    */
    char currentSymbol;
    if (y < ((pizza.length / 2) -1))
    {
        if (x < ((pizza.width / 2)-1))
            currentSymbol = pizza.q4;
        else    
            currentSymbol = pizza.q1;

    }
    else
    {
        if (x < ((pizza.width / 2)-1))
            currentSymbol = pizza.q3;
        else    
            currentSymbol = pizza.q2;
    }
    return currentSymbol;
}

int getDelivery()
{
    /*check if the user wants a delivery or not
    
    return: int delivery: 1 for yes, 0 for no
    */
    int delivery;
    printf("*************************************************\n");
    printf("Do you want delivery for the price of 15 NIS? Enter %d for delivery or %d for pick-up: ", DELIVERY, PICK_UP);
    scanf("%d", &delivery);
    while ((delivery != 0) && (delivery != 1))
    {
        printf("Invalid choice! Try again.\n");
        printf("Do you want delivery for the price of 15 NIS? Enter %d for delivery or %d for pick-up: ", DELIVERY, PICK_UP);
        scanf("%d", &delivery);
    }
    printf("\n");
    return delivery;
}

void getPayment(int totalPrice)
{
    /*get the payment from the user and return him the change
    
    Args:
        int totalPrice: total price in shekels
    return: none
    */
    int currentUserPayment, userPayment = 0, moneyToReturn;
    Money money;

    printf("Please enter your payment: ");
    scanf("%d", &currentUserPayment);
    userPayment = currentUserPayment;
    while((int)userPayment < (int)totalPrice)
    {
        printf("Your remaining balance is: %d\n", (int)(totalPrice - userPayment));
        printf("Please enter your payment: ");
        scanf("%d", &currentUserPayment);
        userPayment += currentUserPayment;
    }
    moneyToReturn = userPayment - (int)totalPrice;
    if ((int)moneyToReturn)
    {
        printf("Your change is %d NIS using: \n", moneyToReturn);
        money.tens = moneyToReturn / 10;
        moneyToReturn %= 10;
        if (money.tens)
            printf("%d coin(s) of ten\n", money.tens);
        money.fives = moneyToReturn / 5;
        moneyToReturn %= 5;
        if (money.fives)
            printf("%d coin(s) of five\n", money.fives);
        money.twos = moneyToReturn / 2;
        moneyToReturn %= 2;
        if (money.twos)
            printf("%d coin(s) of two\n", money.twos);
        money.ones = moneyToReturn / 1;
        if (money.ones)
            printf("%d coin(s) of one\n", money.ones);
    }
}
