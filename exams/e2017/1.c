#include <stdio.h>
#include <stdbool.h>

bool isArmstrong(int num){
    int i, sum=0, temp=num;

    for (i=0; i<3; i++){
        sum += (int)pow(temp%10, 3);
        temp /= 10;
    }
    if(sum == num){
        return true;
    }
    return false;
}

void main(){
    int i;

    for(i=100; i<1000; i++){
        if(isArmstrong(i)){
            printf("%d\n", i);
        }
    }
}