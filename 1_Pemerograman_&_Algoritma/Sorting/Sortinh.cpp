#include <stdio.h>

int main(){
    int arry[10] = {10,2,4,5,1,3,6,8,7,9,};
    
    int size = 10;

    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            if (arry[j] > arry[j+1]){
                int temp = arry[j];
                arry[j] = arry[j+1];
                arry[j+1] = temp;
            }
        }
    }


    for (int k = 0; k < size; k++){
        printf("%d ", arry[k]);
    }
    printf("\n%d", size);
    return 0;
}