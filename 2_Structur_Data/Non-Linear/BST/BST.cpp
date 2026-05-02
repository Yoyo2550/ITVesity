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

Data *findMid(Data *node){
    while (node->left != NULL){
        node = node->left;
    }
    return node;
}

Data *delt(Data *node, int num){
    if (node == NULL){
        return NULL;
    }

    if (num < node->num){
        node->left = delt(node->left, num);
    }else if (num > node->num){
        node->right = delt(node->right, num);
    }else{
        if (node->right == NULL && node->left == NULL){
            free(node);
            return NULL;
        }else if (node->right == NULL){
            Data *temp = node->left;
            free(node);
            return temp;
        }else if (node->left == NULL){
            Data *temp = node->right;
            free(node);
            return temp;
        }else{
            Data *temp = findMid(node->right);
            node->num = temp->num;
            node->right = delt(node->right, temp->num);
        }
    }
    return node;
}

void pop(int num){
    root = delt(root,num);
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
        printf("2. Delete\n");
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
            pop(num);
            break;

        default:
            break;
        }
    } while (input != 0);
}
