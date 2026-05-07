#include <stdio.h>

int main(){
    char character = 'A';
    char word[50] = "Hello World";
    int num = 1;
    float desimal = 2.6;
    bool Answer = false;

    printf("Charcter : %c\n", character);
    printf("Word : %s\n", word);
    printf("Number : %d\n", num);
    printf("karakter : %f\n", desimal);
    printf("Boolean : %s\n", Answer ? "True" : "Flase");

}