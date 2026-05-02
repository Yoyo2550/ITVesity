#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Data
{
    int num;
    Data *right, *left;
}*root = NULL;

Data *insert(Data *node, int num){
    if (node == NULL){
        Data *curr = (Data*) malloc (sizeof(Data));
        
        curr->num = num;
        
        curr->left = curr->right = NULL;
        return curr;
    }
}

int main(){
    int input, num;
    do{
        printf("==== Data ====");
        //view();
        printf("==============");
        printf("1. Insert");
        printf("1. Delete");
        printf("0. Exit");
        printf("Input : ");
        scanf("%d",&input);
        switch (input)
        {
        case 1:
            printf("Number : ");
            scanf("%d", &num);
            //push(num);
            break;

        case 2:
            printf("Number : ");
            scanf("%d", &num);
            break;

        default:
            break;
        }
    } while (input != 0);
    
}
