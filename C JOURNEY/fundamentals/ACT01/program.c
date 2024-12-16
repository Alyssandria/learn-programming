// HELLO [WORLD]!
#include <stdio.h>

int main(){
    char name[50];
    printf("Hello, World!\n");
    printf("What is your name? ");
    scanf("%s", &name);
    printf("Hello, %s!\n", name);
    return 0;
}