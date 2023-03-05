#include <stdio.h>

void main()
{
    int max_num, min_num, n, current_num;

    printf("Please enter positive number: ");
    scanf("%d", &n);

    if (n < 0)
        printf("number is not positive! \n");
    
    printf("Please enter %d integers: ", n);
    scanf("%d", &current_num);
    max_num = current_num;
    min_num = current_num;
    for (int i = 1; i < n; i++)
    {
        scanf("%d", &current_num);
        if (current_num > max_num)
        {
            max_num = current_num;
        }
        else if (current_num < min_num)
        {
            min_num = current_num;
        }
    }
    
    printf("the max difference between any pair of numbers is: %d\n", max_num - min_num);
    
}