#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Node{
    char name[100];
    Node *next;
}*head, *tail, *curr;

void view(){
    int no = 0;
    curr = head;
    while (curr != NULL){
        printf("%d | %s\n", no+1, curr->name);
        curr = curr->next;
        no++;
    }
}

void push(char name[]){
    curr = (Node*) malloc (sizeof(Node));
    
    strcpy(curr->name, name);

    curr->next = NULL;

    if (head == NULL){
        head = tail = curr;
    }else{
        tail->next = curr;
        tail = curr;
    }
}

void pop(char name[]){
    if (head != NULL){
        if (head == tail){
            head = tail = NULL;
        }else{
            if (strcmp(name, head->name) == 0){
                curr = head;
                free(curr);
                head = head->next;
            }else if (strcmp(name, tail->name) == 0){
                Node *temp;

                curr = head;
                while (curr->next != tail){
                    curr = curr->next;
                }
                temp = curr->next;
                curr->next = tail->next;
                free(temp);
                tail = curr;
            }else{
                Node *temp;

                curr = head;
                while (curr->next != NULL && strcmp(name, curr->next->name) != 0){
                    curr = curr->next;
                }

                temp = curr->next;
                curr->next = temp->next;
                free(temp);
            }
        }
    }
}
    

int main(){
    int input;
    char name[50];

    do{
        system("cls");        
        printf("===== Data =====\n");
        // view();
        printf("================\n");
        printf("1. Insert\n");
        printf("2. Delet\n");
        printf("0. Exit\n");
        printf("Input : ");
        scanf("%d", &input);
        switch (input)
        {
            case 1:
            printf("Name : ");
            scanf("%s", name);
            push(name);
            break;
            
            case 2:
            printf("Name : ");
            scanf("%s", name);
            pop(name);
            break;
            
            default:
            break;
        }
    } while (input != 0);
}