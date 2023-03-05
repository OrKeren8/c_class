//Or Keren
//315155531

#include <stdio.h>
#include <stdbool.h>

//sizes
#define BASIC_PIZZA_LENGTH 40
#define BASIC_PIZZA_WIDTH 40
#define BASIC_PIZZA_SIZE (BASIC_PIZZA_LENGTH * BASIC_PIZZA_WIDTH)

//prices
#define BASIC_PIZZA_PRICE 60.0
#define DELIVERY_PRICE 15
#define TAX 17.0 / 100

//toppings
#define OLIVES_PRICE 10
#define MUSHROOMS_PRICE 12

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

void main()
{
    struct Pizza {
        int length; // pizza length (cm)
        int width; // pizza width (cm)
        int size; // pizza size
        char doughType; // dough type ('r'/'v'/'w'/'f')
        int currentDoughPrice;
        int toppingType;
        double olives; // olives amount (0/1/0.5/0.25)
        double mushrooms; // mushrooms amount (0/1/0.5/0.25)
        double price; // pizza price (without tax)
    }typedef Pizza;

    struct Money{
        int tens;
        int fives;
        int twos;
        int ones;
    }typedef Money;

    //general
    int id;
    int delivery;
    double totalPrice = 0;
    double totalPriceWithTax = 0; 

    //money
    int currentUserPayment;
    int userPayment = 0;
    int moneyToReturn;

    Money money;
    money.tens = 0;
    money.fives = 0;
    money.twos = 0;
    money.ones = 0;
    
    //pizza
    Pizza pizza;
    pizza.price = 0;
    int numberOfPizzas;

    //print pizza
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
    //end

    //get id number
    printf("\nPlease enter your ID number: \n");
    printf("\n");
    scanf("%d", &id);
    //end
    
    //menu
    printf("Our menu:\n");
    printf("*********\n");
    printf("Basic pizza: %4.2f NIS for %dx%d size pizza\n\n", BASIC_PIZZA_PRICE, BASIC_PIZZA_LENGTH, BASIC_PIZZA_WIDTH);
        
        //toppings
        printf("Toppings for basic size pizza:\n");
        printf("Olives: %d NIS\n", OLIVES_PRICE);
        printf("Mushrooms: %d NIS\n", MUSHROOMS_PRICE);
        printf("\n");
        //end

        //dough
        printf("Dough type for basic size pizza: \n");
        printf("Regular: %d NIS\n", REGULAR_PRICE);
        printf("Vegan: %d NIS\n", VEGAN_PRICE);
        printf("Whole wheat: %d NIS\n", WHOLE_WHEAT_PRICE);
        printf("Gluten free: %d NIS\n", GLUTEN_FREE_PRICE);
        printf("\n");
        //end
    
    //end

    //order
    printf("How many pizzas would you like to order? \n\n");
    scanf("%d", &numberOfPizzas);
    if (numberOfPizzas > 0)
    {
        for (int i = 1; i <= numberOfPizzas; i++)
        {
            
            //starter
            printf("*************************************************\n");
            printf("Pizza #%d:\n\n", i);
            //end starter
            
            //get pizza size
            printf("Please enter your pizza's length (cm): \n");
            scanf("%d", &pizza.length);
            if (((pizza.length % 2) != 0) || (pizza.length < 10) || (pizza.length > 40))
            {
                printf("Invalid length! Basic length was chosen as a default.\n");
                pizza.length = BASIC_PIZZA_LENGTH;
            }
            printf("Please enter your pizza's width (cm): \n");
            scanf("%d", &pizza.width);
            if (((pizza.width % 2) != 0) || (pizza.width < 10) || (pizza.width > 80))
            {
                printf("Invalid width! Basic width was chosen as a default.\n");
                pizza.width = BASIC_PIZZA_WIDTH;
            }
            printf("\n");
            pizza.size = pizza.length * pizza.width;
            //end pizza size

            //get dough type
            printf("Please enter the pizza's dough type:\n");
            printf("%c - for regular\n", REGULAR_NAME);
            printf("%c - for vegan\n", VEGAN_NAME);
            printf("%c - for whole wheat\n", WHOLE_WHEAT_NAME);
            printf("%c - for gluten-free\n", GLUTEN_FREE_NAME);
            scanf(" %c", &pizza.doughType);
            if ((pizza.doughType != REGULAR_NAME) && (pizza.doughType != VEGAN_NAME) && (pizza.doughType != WHOLE_WHEAT_NAME) && (pizza.doughType != GLUTEN_FREE_NAME))
            {
                printf("Invalid choice! Regular dough was chosen as a default\n");
                pizza.doughType = REGULAR_NAME;
            }
            switch (pizza.doughType)
            {
                case REGULAR_NAME:
                    pizza.currentDoughPrice = REGULAR_PRICE;
                    break;
                case VEGAN_NAME:
                    pizza.currentDoughPrice = VEGAN_PRICE;
                    break;
                case WHOLE_WHEAT_NAME:
                    pizza.currentDoughPrice = WHOLE_WHEAT_PRICE;
                    break;
                case GLUTEN_FREE_NAME:
                    pizza.currentDoughPrice = GLUTEN_FREE_PRICE;
            }
            printf("\n");
            //end get dough type

            //get toppings
            printf("Please choose the toppings: \n\n");
            
            //olives
            printf("Olives (choose 0-3):\n");
            printf("%d. None\n"
                   "%d. Whole pizza\n"
                   "%d. Half pizza\n"
                   "%d. Quarter pizza\n", NONE_INDEX, WHOLE_INDEX, HALF_INDEX, QUARTER_INDEX);
            scanf("%d", &pizza.toppingType);
            if((pizza.toppingType != WHOLE_INDEX) && (pizza.toppingType != HALF_INDEX) && (pizza.toppingType != QUARTER_INDEX) && (pizza.toppingType != NONE_INDEX))
            {
                printf("Invalid choice! Current topping not added.\n");
                pizza.toppingType = NONE_INDEX;
            }
            switch (pizza.toppingType)
            {
                case NONE_INDEX:
                    pizza.olives = NONE;
                    break;
                case WHOLE_INDEX:
                    pizza.olives = WHOLE;
                    break;
                case HALF_INDEX:
                    pizza.olives = HALF;
                    break;
                case QUARTER_INDEX:
                    pizza.olives = QUARTER;
            }
            printf("\n");
            //end olives

            //mushrooms
            printf("Mushrooms (choose 0-3):\n");
            printf("%d. None\n"
                   "%d. Whole pizza\n"
                   "%d. Half pizza\n"
                   "%d. Quarter pizza\n", NONE_INDEX, WHOLE_INDEX, HALF_INDEX, QUARTER_INDEX);
            scanf("%d", &pizza.toppingType);
            if((pizza.toppingType != WHOLE_INDEX) && (pizza.toppingType != HALF_INDEX) && (pizza.toppingType != QUARTER_INDEX) && (pizza.toppingType != NONE_INDEX))
            {
                printf("Invalid choice! Current topping not added.\n");
                pizza.toppingType = NONE_INDEX;
            }
            switch (pizza.toppingType)
            {
                case NONE_INDEX:
                    pizza.mushrooms = NONE;
                    break;
                case WHOLE_INDEX:
                    pizza.mushrooms = WHOLE;
                    break;
                case HALF_INDEX:
                    pizza.mushrooms = HALF;
                    break;
                case QUARTER_INDEX:
                    pizza.mushrooms = QUARTER;
            }
            if((pizza.olives + pizza.mushrooms) > 1)
            {
                pizza.mushrooms = NONE;
                printf("You have exceeded the maximum amount of toppings allowed on one pizza! Current topping not added.\n");
            }
            printf("\n");
            //end mushrooms
            //end get toppings

            //print current pizza price
            pizza.price = 0;
            pizza.price += ((double)pizza.size / BASIC_PIZZA_SIZE) * BASIC_PIZZA_PRICE;
            pizza.price += (((double)pizza.size * pizza.olives) / BASIC_PIZZA_SIZE) * OLIVES_PRICE;
            pizza.price += (((double)pizza.size * pizza.mushrooms) / BASIC_PIZZA_SIZE) * MUSHROOMS_PRICE;
            pizza.price += ((double)pizza.size / BASIC_PIZZA_SIZE) * pizza.currentDoughPrice;
            totalPrice += pizza.price;
            printf("Pizza #%d details:\n", i);
            printf("*******************\n");
            printf("Pizza size: %dx%d\n", pizza.length, pizza.width);
            printf("Pizza price (without tax): %.2f\n\n", pizza.price);
        }

        //ask for delivery
        printf("*************************************************\n");
        printf("Do you want delivery for the price of 15 NIS? Enter %d for delivery or %d for pick-up: \n", DELIVERY, PICK_UP);
        scanf("%d", &delivery);
        if ((delivery != 0) && (delivery != 1))
        {
            printf("invalid choice! Pick-up was chosen as a default.\n");
            delivery = 0;
        }
        printf("\n");
        //end delivery 

        //calculate total price
        totalPrice += delivery * DELIVERY_PRICE;
        totalPriceWithTax = totalPrice + totalPrice * TAX;
        //end calculate total price

        //order summery
        printf("Your order details:\n");
        printf("*******************\n");
        printf("ID number: %09d\n", id);
        printf("Number of pizzas: %d\n", numberOfPizzas);
        printf("Total price: %.2f\n", totalPrice);
        printf("Total price with tax (rounded down): %d \n\n", (int)totalPriceWithTax);
        //end order summery

        //payment
        printf("Please enter your payment: \n");
        scanf("%d", &currentUserPayment);
        userPayment = currentUserPayment;
        while((int)userPayment < (int)totalPriceWithTax)
        {
            printf("your remaining balance is: %d\n", (int)(totalPriceWithTax - userPayment));
            printf("Please enter your payment: \n");
            scanf("%d", &currentUserPayment);
            userPayment += currentUserPayment;
        }
        moneyToReturn = userPayment - (int)totalPriceWithTax;
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
        //end payment

        printf("Thank you for your order!");

    }
    //end order
    else
    {
        printf("Thank you and goodbye.\n");       
    }  
}