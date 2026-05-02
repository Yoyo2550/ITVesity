#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Node{
    char name[100];
    Node *next, *prev;
}*head, *tail, *curr;

int main(){
    int input;
    char name[50];
    do{
        printf("==== Data ====");
        //view();
        printf("==============");
        printf("1. Insert");
        printf("1. Delete");
        printf("0. Exit");
        printf("Input : ");
        scanf("%d", &input);
        switch (input){
        case 1:
            printf("Name : ");
            scanf("%s", name);
            break;
        
        default:
            break;
        }
    } while (input != 0);
    
}