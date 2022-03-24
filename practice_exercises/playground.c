#include<stdio.h>
#include<stdlib.h>

typedef struct BInt {
    int d;
    struct BInt* ll;
    struct BInt* rl;
} BInt;

BInt * ctb(char *digits, int len) {
    BInt *longInt = NULL;
    BInt *tao = (BInt *) malloc(sizeof(BInt));
    
    tao -> d = 0;
    tao -> ll = tao;
    tao -> rl = tao;
    longInt = tao;

    int nTerms = 0;
    int sign = 1;

    for (int i = 0; i < len; i++) {
        int term = digits[i] - '0';

        tao = (BInt *) malloc(sizeof(BInt));
        tao -> d = term;
        (longInt -> ll) -> rl = tao;
        tao -> rl = longInt;
        tao -> ll = longInt -> ll;
        longInt -> ll = tao;

        nTerms += 1;
    }
    
    longInt -> d = sign * nTerms;
    return longInt;
}

BInt * add(BInt **a_ptr, BInt **b_ptr) {
    BInt *a = *a_ptr;
    BInt *b = *b_ptr;

    BInt *sum = NULL;
    BInt *tao = (BInt *) malloc(sizeof(BInt));
    
    tao -> d = 0;
    tao -> ll = tao;
    tao -> rl = tao;
    sum = tao;

    int k = 0;
    int c = 0;
    BInt *alp = a -> ll;
    BInt *beta = b -> ll;

    int t = 0;
    while (1) {
        if ((alp != a) && (beta != b)) {
            t = (alp -> d) + (beta -> d) + c;
            alp = alp -> ll;
            beta = beta -> ll;
        }

        if ((alp != a) && (beta == b)) {
            t = (alp -> d) + c;
            alp = alp -> ll;
        }

        if ((alp == a) && (beta != b)) {
            t = (beta -> d) + c;
            beta = beta -> ll;
        }

        if ((alp == a) && (beta == b)) {
            if (c != 0) {
                tao = (BInt *) malloc(sizeof(BInt));
                tao -> d = c;
                tao -> rl = sum -> rl;
                tao -> ll = sum;
                (sum -> rl) -> ll = tao;
                sum -> rl = tao;

                k += 1;
            } else {
                //
            }

            sum -> d = k;
            break;
        }

        int term = t % 10;
        tao = (BInt *) malloc(sizeof(BInt));
        tao -> d = term;
        tao -> rl = sum -> rl;
        tao -> ll = sum;
        (sum -> rl) -> ll = tao;
        sum -> rl = tao;

        c = t / 10;
        k += 1;
    }

    return sum;
}

int main() {
    char n1[10] = "123";
    char n2[10] = "245";

    BInt *a = ctb(n1, 2);
    BInt *b = ctb(n2, 2);
    BInt *sum = add(&a, &b);

    for (int i = 0; i < 2; i++) {
        sum = sum -> rl;
        printf("%d ", sum -> d);
    }

    return 0;
}
