#include <stdio.h>
#include <stdlib.h>

int main() {
    char characterName[] = "John";
    int characterAge = 12;

    printf("Hello %s\n", characterName);
    printf("His age is %d\n", characterAge);

    characterAge = 21;
    
    printf("Hello %s\n", characterName);
    printf("His age is %d\n", characterAge);

    return 0;
}