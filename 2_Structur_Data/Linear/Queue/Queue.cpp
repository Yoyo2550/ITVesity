#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Node{
    char name[100];
    Node *next, *prev;
}*head, *tail, *curr;

void view(){
    curr = head;
    while (curr != NULL){
        printf("%s\n", curr->name);
        curr = curr->next;
    }
}

Node *insert(char name[]){
    curr = (Node*) malloc (sizeof(Node));

    strcpy(curr->name, name);

    curr->next = curr->prev = NULL;

    return curr;
}

void push(char name[]){
    curr = insert(name);
    
    if (head == NULL)
    {
        head = tail = curr;
    }else{
        tail->next = curr;
        curr->prev = tail;
        tail = curr;
    }
}

void pop(){
    if (head == tail){
        head = tail = NULL;
    }else{
        curr = head;
        head = head->next;
        free(curr);
        head->prev = NULL;
    }
}

int main(){
    int input;
    char name[50];
    do{
        system("cls");
        printf("==== Data ====\n");
        view();
        printf("==============\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("0. Exit\n");
        printf("Input : ");
        scanf("%d", &input);
        switch (input){
        case 1:
            printf("Name : ");
            scanf("%s", name);
            push(name);
            break;
        
        case 2:
            pop();
            break;

        default:
            break;
        }
    } while (input != 0);
    
}