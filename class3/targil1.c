#include <stdio.h>
#define DEFAULT_INITIAL_LETTER 'a'
#define HEIGHTS_DIFF 3

typedef struct person {
    int age;
    int height;
    char firstLetter;
}Person;

void main()
{
    Person person1, person2;

    printf("Please enter first person details: age, height, Name's first letter (separated by spaces): \n");
    scanf("%d %d %c", &person1.age, &person1.height, &person1.firstLetter);
    if (!((person1.firstLetter >= 'a' && person1.firstLetter <= 'z') || (person1.firstLetter >= 'A' && person1.firstLetter <= 'Z')))
    {
        printf("Name's first latter is invalid (set %c as default)\n", DEFAULT_INITIAL_LETTER);
        person1.firstLetter = DEFAULT_INITIAL_LETTER;
    }

    printf("Please enter second person details: age, height, Name's first letter (separated by spaces): \n");
    scanf("%d %d %c", &person2.age, &person2.height, &person2.firstLetter);
    if (!((person2.firstLetter >= 'a' && person2.firstLetter <= 'z') || (person1.firstLetter >= 'A' && person1.firstLetter <= 'Z')))
    {
        printf("Name's second latter is invalid (set %c as default)\n", DEFAULT_INITIAL_LETTER);
        person1.firstLetter = DEFAULT_INITIAL_LETTER;
    }

    if (person1.age == person2.age)
    {
        printf("Persons are in the same age");
    }
    else
        (person1.age > person2.age) ? printf("First person is older, his name starts at %c\n", person1.firstLetter) : printf("First person2 is older, his name starts at %c\n", person2.firstLetter);

    if (((person1.height - person2.height) < HEIGHTS_DIFF) && ((person2.height - person1.height) < HEIGHTS_DIFF))
    {
        printf("height difference smaller than %d", HEIGHTS_DIFF);
    }
}