#include <stdio.h>

int list[10] = {1,3,4,2,6,5,7,9,6,10};

int serch(int num){
    for (int i = 0; i < 10; i++){
        if (num == list[i]){
            return i;
        }
    }
    return -1;
}

int main(){
    int input;
    printf("Number : ");
    scanf("%d", &input);

    int num = serch(input);
    printf("Number is idex: %d", num);
    
}