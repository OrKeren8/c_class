#include <stdio.h>
#include <stdlib.h>

void drawPattern(int chessMatrix[CHESS_SIZE][]) {

    for (int i = 0; i < CHESS_SIZE; i++) {
        for (int j = 0; j < CHESS_SIZE; j++)
            printf("#####");            
        printf("#\n#");
        for (int j = 0; j < CHESS_SIZE; j++) { 
            if(chessMatrix[i][j] != 0)
                printf(" %2d #", chessMatrix[i][j]);    
            else
                printf("    #");
        }
        printf("\n");
    }
    for (int j = 0; j < CHESS_SIZE; j++) 
        printf("#####");            
    printf("#\n");
}

int main() {
    drawPattern();

    return 0;
}