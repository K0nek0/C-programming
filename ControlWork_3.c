#include <stdio.h>

int main(){
    int sample[8] ={-1413863686, -1146374827, -1162027246, -1442185216, 184549376, 11534336, 655360, 179026592};
//    int sample[8] ={-1430650880, -1157627904, 3145728, -1442185216, 184549376, 11534336, 655360, 3840};
    char mas[8][8];
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            int num = ((sample[i] >> (32-((j+1)*4))) & 0xF);
            if (num < 10){
                mas[i][j] = num-'0';
                printf("%d", num);
            }
            else{
                if (num == 10){
                    mas[i][j] = 'A';
                    printf("A");
                }
                if (num == 11){
                    mas[i][j] = 'B';
                    printf("B");
                }
                if (num == 12){
                    mas[i][j] = 'C';
                    printf("C");
                }
                if (num == 13){
                    mas[i][j] = 'D';
                    printf("D");
                }
                if (num == 14){
                    mas[i][j] = 'E';
                    printf("E");
                }
                if (num == 15){
                    mas[i][j] = 'F';
                    printf("F");
                }
            }
        }
        printf("\n");
    }
    printf("\n");

    int count = 0;
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            if (mas[i][j] == 'A'){
                if ((mas[i][j+1] == 'B') && ((j+1)<8)){
                    if ((mas[i][j+2] == 'B') && ((j+2)<8)){
                        if ((mas[i][j+3] == 'A') && ((j+3)<8)){
                            count++;
                        }
                        if ((mas[i+1][j+2] == 'A') && ((i+1)<8) && ((j+2)<8)){
                            count++;
                        }
                    }
                    if ((mas[i+1][j+1] == 'B') && ((i+1)<8) && ((j+1)<8)){
                        if ((mas[i+2][j+1] == 'A') && ((i+2)<8) && ((j-1)<8)){
                            count++;
                        }
                        if ((mas[i+1][j+2] == 'A') && ((i+1)<8) && ((j-2)<8)){
                            count++;
                        }
                    }
                }
                if ((mas[i+1][j] == 'B') && ((j+1)<8)){
                    if ((mas[i+2][j] == 'B') && ((j+2)<8)){
                        if ((mas[i+3][j] == 'A') && ((j+3)<8)){
                            count++;
                        }
                        if ((mas[i+2][j+1] == 'A') && ((i-2)<8) && ((j+1)<8)){
                            count++;
                        }
                    }
                    if ((mas[i+1][j+1] == 'B') && ((i+1)<8) && ((j+1)<8)){
                        if ((mas[i+1][j+2] == 'A') && ((i-1)<8) && ((j+2)<8)){
                            count++;
                        }
                        if ((mas[i+2][j+1] == 'A') && ((i-2)<8) && ((j+1)<8)){
                            count++;
                        }
                        if ((mas[i][j+1] == 'A') && ((j+1)<8)){
                            count++;
                        }
                    }
                }
            }
        }
    }
    printf("%d", count);
}
