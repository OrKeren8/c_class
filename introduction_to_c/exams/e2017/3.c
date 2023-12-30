#include <stdio.h>
#include <stdbool.h>

bool commonPl(char str1[], char str2[]){
    
    if((strlen(str1) == 1) || (strlen(str2) == 1)){
        return (str1[0] == str2[0]);
    }
    
    if(str1[0] == str2[0]){
        return true;
    }
    else{
        return commonPl(str1+1, str2+1);
    }
}

void findDivisors(int data[], int size, int n1, int n2){

    bool n1Dev = false, n2Dev = false;

    if(size>0){
        if(data[0]%n1 == 0){
            n1Dev = true;
        }

        findDivisors(data+1, size-1, )

        if(data[size-1]%n2 == 0){
            n2Dev=true;
        }
    }
    printf("%d")

}

void main(){
    bool res;


    res = commonPl("abc", "bba");
    printf("%d\n", res);
}