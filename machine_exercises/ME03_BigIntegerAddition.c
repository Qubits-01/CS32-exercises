#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct BigInt {
    int data;
    struct BigInt* llink;
    struct BigInt* rlink;
} BigInt;

int main() {
    BigInt bigint;
    bigint.data = 12;

    printf("%d", bigint.data);

    return 0;
}
