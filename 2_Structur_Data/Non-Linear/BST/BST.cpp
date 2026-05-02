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
    }else if (num < node->num){
        node->left = insert(node->left, num);
    }else if (num > node->num){
        node->right = insert(node->right, num);
    }
    return node;
}

void push(int num){
    root = insert(root,num);
}

void preOrder(Data *node){
    if (root == NULL){
        printf("NULL");    
    }else{
        if (node == NULL) return;
        
        printf("%d -> ", node->num);
        preOrder(node->left);
        preOrder(node->right);
    }    
}

void inOrder(Data *node){
    if (root == NULL){
        printf("NULL");    
    }else{
        if (node == NULL) return;
        
        inOrder(node->left);
        printf("%d -> ", node->num);
        inOrder(node->right);
    }    
}

void postOrder(Data *node){
    if (root == NULL){
        printf("NULL");    
    }else{
        if (node == NULL) return;
        
        postOrder(node->left);
        postOrder(node->right);
        printf("%d -> ", node->num);
    }    
}

void view(){
    printf("Preorder  : ");
    preOrder(root);
    puts("");
    printf("Inorder   : ");
    inOrder(root);
    puts("");
    printf("Postorder : ");
    postOrder(root);
    puts("");
}

int main(){
    int input, num;
    do{
        system("cls");
        printf("==== Data ====\n");
        view();
        printf("==============\n");
        printf("1. Insert\n");
        printf("1. Delete\n");
        printf("0. Exit\n");
        printf("Input : ");
        scanf("%d",&input);
        switch (input)
        {
        case 1:
            printf("Number : ");
            scanf("%d", &num);
            push(num);
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
