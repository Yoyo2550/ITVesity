#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node{
    int value;
    int height;
    Node *left, *right;
}*root = NULL;

Node *newNode(int value){
    Node *curr = (Node*) malloc (sizeof(Node));

    curr->value = value;
    curr->height = 1;
    curr->right = curr->left = NULL;
    return curr;
}

int getHeight(Node *curr){
    if (curr == NULL) return 0;
    else return curr->height;
}

int getMax(int height1, int height2){
    if (height1 > height2) return height1;
    else return height2;
    
}

int balanceFactor(Node *curr){
    if (curr == NULL) return 0;
        return getHeight(curr->left) - getHeight(curr->right);
    }

Node *rightRotaion(Node *curr){
    //Create Wadah
    Node *child = curr->left;
    Node *grandeChild = child->right;

    //Tukar Posisi
    child->right = curr;
    curr->left = grandeChild;

    //Update Height
    curr->height = getMax(getHeight(curr->left),getHeight(curr->right))+1;

    child->height = getMax(getHeight(child->left),getHeight(child->right))+1;

    return child;
}

Node *leftRotaion(Node *curr){
    //Create Wadah
    Node *child = curr->right;
    Node *grandChild = child->left;

    //Tukar Posisi
    child->left = curr;
    curr->right = grandChild;

    //Upadate Height
    curr->height = getMax(getHeight(curr->left),getHeight(curr->right))+1;
    child->height = getMax(getHeight(child->left),getHeight(child->right))+1;

    return child;
}

Node *insertNode(Node *curr, int value){
    //1. Serch node = NULL
    if (curr == NULL){
        curr = newNode(value);
    }else if (value < curr->value){
        curr->left = insertNode(curr->left, value);
    }else if (value > curr->value){
        curr->right = insertNode(curr->right, value);
    }

    //2. Update Hight;
    curr->height = getMax(getHeight(curr->left),getHeight(curr->right))+1;
    
    //3. Check Balance Factor;
    int bf = balanceFactor(curr);

    //4. Rotasi
    if (bf > 1 && value < curr->left->value){ //Case : LL (Berat Kiri Kiri)
        return rightRotaion(curr); //Solve : Rotasi Ke Kanan
    }else if (bf > 1 && value > curr->left->value){ //Case : LR (Berat Kiri Kanan)
        curr->left = leftRotaion(curr->left); //Solve : Rotasi Ke Kiri dulu -> Ke Kanan
        return rightRotaion(curr);
    }else if (bf < -1 && value > curr->right->value){
        return leftRotaion(curr);
    }else if (bf < -1 && value < curr->right->value){
        curr->right = rightRotaion(curr->right);
        return leftRotaion(curr);
    }
    
    return curr;
}

Node *preDecssor(Node *curr){
    curr = curr->left;
    while (curr->right != NULL){
        curr = curr->right;
    }
    return curr;
}

Node *deleteNode(Node *curr, int value){
    if (curr == NULL){
        return NULL;
    }else if (value < curr->value){
        curr->left = deleteNode(curr->left, value);
    }else if (value > curr->value){
        curr->right = deleteNode(curr->right, value);
    }else{    
        if (curr->left == NULL && curr->right == NULL){
            free(curr);
            return NULL;
        }else if (curr->right == NULL){
            Node *temp = curr->left;
            free(curr);
            return temp;
        }else if (curr->left == NULL){
            Node *temp = curr->right;
            free(curr);
            return temp;
        }else{
            Node *temp = preDecssor(curr);
            curr->value = temp->value;
            curr->left = deleteNode(curr->left,temp->value);
        }
    }

    if (curr == NULL) return NULL;
    

    curr->height = getMax(getHeight(curr->left),getHeight(curr->right))+1;

    int bf = balanceFactor(curr);

    if (bf > 1 && balanceFactor(curr->left) >= 0){
        return rightRotaion(curr);
    }else if (bf > 1 && balanceFactor(curr->left) < 0){
        curr->left = leftRotaion(curr->left);
        return rightRotaion(curr);
    }else if (bf < -1 && balanceFactor(curr->right) <= 0){
        return leftRotaion(curr);
    }else if (bf < -1 && balanceFactor(curr->right) > 0){
        curr->right = rightRotaion(curr->right);
        return leftRotaion(curr);
    }
    
    return curr;
}

void preOrder(Node *curr){
    if (curr != NULL){
        printf("%d->",curr->value);
        preOrder(curr->left);
        preOrder(curr->right);
    }
}

void InOrder(Node *curr){
    if (curr != NULL){
        InOrder(curr->left);
        printf("%d->",curr->value);
        InOrder(curr->right);
    }
}

void postOrder(Node *curr){
    if (curr != NULL){
        postOrder(curr->left);
        postOrder(curr->right);
        printf("%d->",curr->value);
    }
}

void view(){
    preOrder(root);
    puts("");
    InOrder(root);
    puts("");
    postOrder(root);
    puts("");
}

int main(){
    int input, value;
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
            scanf("%d", &value);
            root = insertNode(root,value);
            break;

        case 2:
            printf("Number : ");
            scanf("%d", &value);
            root = deleteNode(root,value);
            break;

        default:
            break;
        }
    } while (input != 0);
}
