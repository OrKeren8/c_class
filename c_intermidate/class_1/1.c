#include <stdio.h>
#include <string.h>

char *token;    
char separators[] = " \\\n\t*";

void splitWordsInString(char *inStr, char *outStr);

int main(){
    char inStr[] = "Hi*\*Is it me*\\** you** \\are looking** for?";
    char outStr[100] = "";
    splitWordsInString(inStr, outStr);
    printf("%s", outStr);
}

void splitWordsInString(char *inStr, char *outStr) 
{
    token = strtok(inStr, separators);
    while(token != NULL){
        strcat(outStr, token);
        strcat(outStr, "\n");
        token = strtok(NULL, separators);
    }
}