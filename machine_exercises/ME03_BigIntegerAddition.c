#include<stdio.h>
#include<stdlib.h>

#define newLine printf("\n");

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

    int t = 0;
    while (1) {
        printf("alpha: %d, beta: %d, c: %d\n", alpha -> data, beta -> data, c);

        if ((alpha != a) && (beta != b)) {
            t = (alpha -> data) + (beta -> data) + c;
            alpha = alpha -> llink;
            beta = beta -> llink;
        } else if ((alpha != a) && (beta == b)) {
            t = (alpha -> data) + c;
            alpha = alpha -> llink;
        } else if ((alpha == a) && (beta != b)) {
            t = (beta -> data) + c;
            beta = beta -> llink;
        } else if ((alpha == a) && (beta == b)) {
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
        printf("terms: %d\n", term);
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

void printElems(BigInt *longInt) {
    int nTerms = longInt -> data;
    printf("nTerms: %d\n", nTerms);

    for (int i = 0; i < nTerms; i++) {
        longInt = longInt -> rlink;
        printf("%d ", longInt -> data);
    }
}

void reversePrintElems(BigInt *longInt) {
    int nTerms = longInt -> data;
    printf("nTerms: %d\n", nTerms);

    for (int i = 0; i < nTerms; i++) {
        longInt = longInt -> llink;
        printf("%d ", longInt -> data);
    }
}


int main() {
    char n1[10] = "52452";
    char n2[10] = "77212";

    char n3[20] = "92498988047678334552";
    char n4[20] = "96817198892297134829";

    BigInt *a = char_to_bigint(n3, 20);
    BigInt *b = char_to_bigint(n4, 20);

    printElems(a);
    newLine;
    printElems(b);
    newLine;

    BigInt *sum = add(&a, &b);
    printElems(sum);
    newLine;
    reversePrintElems(sum);
    newLine;

    return 0;
}


// #include<stdio.h>
// #include<stdlib.h>

// // Converts an array of characters (where each character is a digit).
// BigInt * char_to_bigint(char *digits, int len) {
//     // zeroInteger
//     BigInt *longInt = NULL;
//     BigInt *tao = (BigInt *) malloc(sizeof(BigInt));
    
//     tao -> data = 0;
//     tao -> llink = tao;
//     tao -> rlink = tao;
//     longInt = tao;
//     // *zeroInteger

//     int nTerms = 0;
//     int sign = 1;

//     for (int i = 0; i < len; i++) {
//         int term = digits[i] - '0';  // Converts [char] digit into [int].

//         // insertAtTail
//         tao = (BigInt *) malloc(sizeof(BigInt));
//         tao -> data = term;
//         (longInt -> llink) -> rlink = tao;
//         tao -> rlink = longInt;
//         tao -> llink = longInt -> llink;
//         longInt -> llink = tao;
//         // *insertAtTail

//         nTerms += 1;
//     }
    
//     longInt -> data = sign * nTerms;
//     return longInt;
// }

// // Takes as input pointers to list head pointers for the two
// // [BigInt]s to add and outputs a pointer to a new [BigInt].
// BigInt * add(BigInt **a_ptr, BigInt **b_ptr) {
//     BigInt *a = *a_ptr;
//     BigInt *b = *b_ptr;

//     // zeroInteger
//     BigInt *sum = NULL;
//     BigInt *tao = (BigInt *) malloc(sizeof(BigInt));
    
//     tao -> data = 0;
//     tao -> llink = tao;
//     tao -> rlink = tao;
//     sum = tao;
//     // *zeroInteger

//     // [k] is number of terms in [sum].
//     // [c] is carry.
//     int k = 0;
//     int c = 0;
//     BigInt *alpha = a -> llink;
//     BigInt *beta = b -> llink;

//     int t = 0;
//     while (1) {
//         if ((alpha != a) && (beta != b)) {
//             t = (alpha -> data) + (beta -> data) + c;
//             alpha = alpha -> llink;
//             beta = beta -> llink;
//         } else if ((alpha != a) && (beta == b)) {
//             t = (alpha -> data) + c;
//             alpha = alpha -> llink;
//         } else if ((alpha == a) && (beta != b)) {
//             t = (beta -> data) + c;
//             beta = beta -> llink;
//         } else if ((alpha == a) && (beta == b)) {
//             if (c != 0) {
//                 // insertAtHead
//                 BigInt *tao1 = (BigInt *) malloc(sizeof(BigInt));
//                 tao1 -> data = c;
//                 tao1 -> rlink = sum -> rlink;
//                 tao1 -> llink = sum;
//                 (sum -> rlink) -> llink = tao1;
//                 sum -> rlink = tao1;
//                 // *insertAtHead

//                 k += 1;
//             } else {
//                 // deleteLeadingZeroes
//                 // *deleteLeadingZeroes
//             }

//             sum -> data = k;
//             break;
//         }

//         int term = t % 10;
//         // insertAtHead
//         BigInt *tao2 = (BigInt *) malloc(sizeof(BigInt));
//         tao2 -> data = term;
//         tao2 -> rlink = sum -> rlink;
//         tao2 -> llink = sum;
//         (sum -> rlink) -> llink = tao2;
//         sum -> rlink = tao2;
//         // *insertAtHead

//         c = t / 10;
//         k += 1;
//     }

//     return sum;
// }

// int main() {
//     return 0;
// }
