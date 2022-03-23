#include<stdio.h>
#include<stdlib.h>

#define newLine printf("\n");

typedef struct BigInt {
    int data;
    struct BigInt* llink;
    struct BigInt* rlink;
} BigInt;

void zeroLongInt(BigInt **longInt) {
    BigInt *tao = (BigInt *) malloc(sizeof(BigInt));

    tao -> data = 0;
    tao -> llink = tao;
    tao -> rlink = tao;

    *longInt = tao;
}

void insertAtHead(BigInt *longInt, int term) {
    BigInt *tao = (BigInt *) malloc(sizeof(BigInt));

    tao -> data = term;
    tao -> rlink = longInt -> rlink;
    tao -> llink = longInt;
    (longInt -> rlink) -> llink = tao;
    longInt -> rlink = tao;
}

// Converts an array of characters (where each character is a digit).
BigInt * char_to_bigint(char *digits, int len) {
    BigInt *longInt;
    zeroLongInt(&longInt);

    int nTerms = 0;
    int sign = 1;

    for (int i = 0; i < len; i++) {
        int term = digits[i] - '0';  // Converts [char] digit into [int].

        // insertAtTail
        BigInt *tao = (BigInt *) malloc(sizeof(BigInt));
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

    BigInt *sum;
    zeroLongInt(&sum);

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
                insertAtHead(sum, c);

                k += 1;
            }

            sum -> data = k;
            break;
        }

        int term = t % 10;
        printf("term: %d\n", term);
        insertAtHead(sum, term);

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

    BigInt *a = char_to_bigint(n1, 5);
    BigInt *b = char_to_bigint(n2, 5);

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

// BigInt * char_to_bigint(char*, int);
// BigInt * add(BigInt **, BigInt **);

// void zeroLongInt(BigInt **);
// void insertAtHead(BigInt *, int);

// int main() {
//     return 0;
// }

// // Converts an array of characters (where each character is a digit).
// BigInt * char_to_bigint(char *digits, int len) {
//     BigInt *longInt;
//     zeroLongInt(&longInt);

//     int nTerms = 0;
//     int sign = 1;

//     for (int i = 0; i < len; i++) {
//         int term = digits[i] - '0';  // Converts [char] digit into [int].

//         // insertAtTail
//         BigInt *tao = (BigInt *) malloc(sizeof(BigInt));
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

//     BigInt *sum;
//     zeroLongInt(&sum);

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
//                 insertAtHead(sum, c);

//                 k += 1;
//             }

//             sum -> data = k;
//             break;
//         }

//         int term = t % 10;
//         insertAtHead(sum, term);

//         c = t / 10;
//         k += 1;
//     }

//     return sum;
// }

// void zeroLongInt(BigInt **longInt) {
//     BigInt *tao = (BigInt *) malloc(sizeof(BigInt));

//     tao -> data = 0;
//     tao -> llink = tao;
//     tao -> rlink = tao;

//     *longInt = tao;
// }

// void insertAtHead(BigInt *longInt, int term) {
//     BigInt *tao = (BigInt *) malloc(sizeof(BigInt));

//     tao -> data = term;
//     tao -> rlink = longInt -> rlink;
//     tao -> llink = longInt;
//     (longInt -> rlink) -> llink = tao;
//     longInt -> rlink = tao;
// }
