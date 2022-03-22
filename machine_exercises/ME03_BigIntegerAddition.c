#include<stdio.h>
#include<stdlib.h>

typedef struct BigInt {
    int data;
    struct BigInt* llink;
    struct BigInt* rlink;
} BigInt;


// Converts an array of characters (where each character is a digit).
BigInt * char_to_bigint(char *digits, int len) {
    // zeroInteger
    BigInt *longInt = NULL;
    BigInt *tao = (BigInt *) malloc(sizeof(BigInt));
    
    tao -> data = 0;
    tao -> llink = tao;
    tao -> rlink = tao;
    longInt = tao;
    // *zeroInteger

    int nTerms = 0;
    int sign = 1;

    for (int i = 0; i < len; i++) {
        int term = digits[i] - '0';  // Converts [char] digit into [int].

        // insertAtTail
        tao = (BigInt *) malloc(sizeof(BigInt));
        tao -> data = term;
        (longInt -> llink) -> rlink = tao;
        tao -> rlink = longInt;
        tao -> llink = longInt -> llink;
        longInt -> llink = tao;
        // *insertAtTail

        nTerms += 1;
    }
    
    longInt -> data = sign * nTerms;
    return longInt;
}

// Takes as input pointers to list head pointers for the two
// [BigInt]s to add and outputs a pointer to a new [BigInt].
BigInt * add(BigInt **a_ptr, BigInt **b_ptr) {
    BigInt *a = *a_ptr;
    BigInt *b = *b_ptr;

    // zeroInteger
    BigInt *sum = NULL;
    BigInt *tao = (BigInt *) malloc(sizeof(BigInt));
    
    tao -> data = 0;
    tao -> llink = tao;
    tao -> rlink = tao;
    sum = tao;
    // *zeroInteger

    // [k] is number of terms in [sum].
    // [c] is carry.
    int k = 0;
    int c = 0;
    BigInt *alpha = a -> llink;
    BigInt *beta = b -> llink;

    // for (int i = 0; i < 3; i++) {
    //     printf("%d\n", alpha -> data);
    //     alpha = alpha -> rlink;
    // }

    int t = 0;
    while (1) {
        if ((alpha != a) && (beta != b)) {
            t = (alpha -> data) + (beta -> data) + c;
            alpha = alpha -> llink;
            beta = beta -> llink;
        }

        if ((alpha != a) && (beta == b)) {
            t = (alpha -> data) + c;
            alpha = alpha -> llink;
        }

        if ((alpha == a) && (beta != b)) {
            t = (beta -> data) + c;
            beta = beta -> llink;
        }

        if ((alpha == a) && (beta == b)) {
            if (c != 0) {
                // insertAtHead
                BigInt *tao1 = (BigInt *) malloc(sizeof(BigInt));
                tao1 -> data = c;
                tao1 -> rlink = sum -> rlink;
                tao1 -> llink = sum;
                (sum -> rlink) -> llink = tao1;
                sum -> rlink = tao1;
                // *insertAtHead

                k += 1;
            } else {
                // deleteLeadingZeroes
                // *deleteLeadingZeroes
            }

            sum -> data = k;
            break;
        }

        int term = t % 10;
        // insertAtHead
        BigInt *tao2 = (BigInt *) malloc(sizeof(BigInt));
        tao2 -> data = term;
        tao2 -> rlink = sum -> rlink;
        tao2 -> llink = sum;
        (sum -> rlink) -> llink = tao2;
        sum -> rlink = tao2;
        // *insertAtHead

        c = t / 10;
        k += 1;
    }

    return sum;
}


int main() {
    char n1[10] = "12212";
    char n2[10] = "34531";

    BigInt *a = char_to_bigint(n1, 5);
    BigInt *b = char_to_bigint(n2, 5);
    BigInt *sum = add(&a, &b);

    for (int i = 0; i < 20; i++) {
        sum = sum -> rlink;
        printf("%d ", sum -> data);
    }

    return 0;
}
