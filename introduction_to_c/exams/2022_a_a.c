#include <stdbool.h>
#include <stdlib.h>

bool isAlternatingSortedRows(int mat[][COLS], int rows, int cols){
    int lastNum;
    bool isAlt = True;
    for(int r=0; r<rows && isAlt; r++){
        lastNum = mat[r][0];
        for(int c=1; c<cols && isAlt; c++){
            if(r%2 == 1){
                if(mat[r][c] < lastNum){
                    isAlt = false;
                }
            }
            else{
                if(mat[r][c] > lastNum){
                    isAlt = false;
                }
            }
            lastNum = mat[r][c];
        }
    }
    return isAlt;
}

void fun(int arr[], int size, int pl){
    int* tmpArr = (int)malloc((size) * sizeof(int));
    int tmpArrIndex=0;
    int left=0, right=size-1;

    while(left<=pl && right>pl){
        if(arr[left] < arr[right]){
            tmpArr[tmpArrIndex] = arr[left];
            left ++;
        }
        else{
            tmpArr[tmpArrIndex] = arr[right];
            right --;
        }
        tmpArrIndex ++;
    }
    for (int i=left; i<=pl; i++){
        tmpArr[tmpArrIndex] = arr[left];
    }
    for (int i=right; i>pl; i--){
        tmpArr[tmpArrIndex] = arr[right];
    }
    for (int i=0; i<size; i++){
        arr[i] = tmpArr[i];
    }
    free(tmpArr);
}


int sumFirstAndLast(int num){

    if(num<10){
        return num*2;
    }
    return sumFirstAndLast(num/10) - ((num/10)%10) + (num%10);
}

void removePizzas(Order* pOrder, int missingTopping){
    Pizza* tmpPizzas = (Pizza*)malloc((pOrder->numOfPizzas)*sizeof(Pizza));
    if (tmpPizzas == Null){
        printf("allocation error!\n");
        exit(1);
    }

    int pizzasCounter=0;
    for(int i=0; i<(pOrder->numOfPizzas); i++){
        if(pOrder->pizzas[i].toppings[missingTopping] == 0){
            tmpOrder->pizzas[pizzasCounter] = pOrder->pizzas[i];
            pizzasCounter++;
        }
    }
    Pizza* tmpPizzas = (Pizza*)realloc(pizzasCounter*sizeof(Pizza));
    free(pOrder->pizzas);
    porder->pizzas = tmpPizzas;
}