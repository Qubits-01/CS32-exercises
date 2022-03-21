#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct BigInt {
    int data;
    struct BigInt* llink;
    struct BigInt* rlink;
} BigInt;

BigInt* char_to_bigint(char *digits, int len) {
    // 
}

BigInt* add(BigInt **a_ptr, BigInt **b_prt) {
    //
}

int main() {
    BigInt bigint;
    bigint.data = 12;

    printf("%d", bigint.data);

    return 0;
}
