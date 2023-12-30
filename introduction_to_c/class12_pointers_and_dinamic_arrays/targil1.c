#include <stdio.h>


#define LETTER_IN_ABC ('z' - 'a' + 1)

typedef struct countLet{
    char let;
    int count;
}COUNT_LET;


COUNT_LET * countStrInStr(char str1[], char str2[], int size);
void checkAllocation(COUNT_LET * arr);

void main()
{
    return;
}

COUNT_LET * countStrInStr(char str1[], char str2[], int size)
{
    COUNT_LET * str1CoutLet = (COUNT_LET*)malloc(LETTER_IN_ABC * sizeof(COUNT_LET));
    void checkAllocation(str1CoutLet);
    COUNT_LET * str2CoutLet = (COUNT_LET*)malloc(LETTER_IN_ABC * sizeof(COUNT_LET));
    void checkAllocation(str2CoutLet);
    int i=0;
    
    for(int m=0; m<LETTER_IN_ABC; m++){
        str1CoutLet[m].let = char('a' + 'm');
        str1CoutLet[m].count = 0;
    }

    for(int m=0; m<LETTER_IN_ABC; m++){
        str2CoutLet[m].let = char('a' + 'm');
        str2CoutLet[m].count = 0;
    }

    while(str1[i] != 0){
        if(str1[i] =< 'z' && str1[i] >= 'a'){

        }
    }
}

void checkAllocation(COUNT_LET * arr){
    if(arr == Null){
        printf("no memory");
        exit(1);
    }
}

void initCountLetArr(COUNT_LET * arr){
    int m;
    for(m=0; m<LETTER_IN_ABC; m++){
        str2CoutLet[m].let = char('a' + 'm');
        str2CoutLet[m].count = 0;
    }
}




