// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>

// #define newLine printf("\n")

// typedef struct Node {
//     int expo[3];
//     int coeff;
//     struct Node *link;
// } Node;

// typedef struct Poly {
//     Node *l;
//     int name;
// } Poly;

// void initPoly(Poly *myPoly) {
//     myPoly -> l = NULL;
//     myPoly -> name = 0;
// }

// void setExpo(Node *myNode, int x, int y, int z) {
//     (myNode -> expo)[0] = x;
//     (myNode -> expo)[1] = y;
//     (myNode -> expo)[2] = z;
// }

// void zeroPoly(Poly *myPoly, int name) {
//     Node *tao = (Node *) malloc(sizeof(Node));
//     myPoly -> l = tao;
//     myPoly -> name = name;
//     setExpo(tao, 0, 0, 1);
//     tao -> link = tao;
//     tao -> coeff = -1;
// }

// bool isGreater(Node *termA, Node *termB) {
//     int x[2];
//     int y[2];
//     int z[2];

//     x[0] = (termA -> expo)[0];
//     x[1] = (termB -> expo)[0];
//     y[0] = (termA -> expo)[1];
//     y[1] = (termB -> expo)[1];
//     z[0] = (termA -> expo)[2];
//     z[1] = (termB -> expo)[2];

//     if (x[0] > x[1]) {
//         return true;
//     } else if (x[0] == x[1]) {
//         if (y[0] > y[1]) {
//             return true;
//         } else if (y[0] == y[1]) {
//             if (z[0] > z[1]) {
//                 return true;
//             } else {
//                 return false;
//             }
//         } else {
//             return false;
//         }
//     } else {
//         return false;
//     }
// }

// bool isEqual(Node *termA, Node *termB) {
//     int x[2];
//     int y[2];
//     int z[2];

//     x[0] = (termA -> expo)[0];
//     x[1] = (termB -> expo)[0];
//     y[0] = (termA -> expo)[1];
//     y[1] = (termB -> expo)[1];
//     z[0] = (termA -> expo)[2];
//     z[1] = (termB -> expo)[2];

//     bool isXsame = x[0] == x[1];
//     bool isYsame = y[0] == y[1];
//     bool isZsame = z[0] == z[1];

//     if (isXsame && isYsame && isZsame) {
//         return true;
//     } else {
//         return false;
//     }
// }

// bool isLess(Node *termA, Node *termB) {
//     return !(isGreater(termA, termB)) && !(isEqual(termA, termB));
// }

// void copyExpo(Node *termA, Node *termB) {
//     int x = (termB -> expo)[0];
//     int y = (termB -> expo)[1];
//     int z = (termB -> expo)[2];

//     setExpo(termA, x, y, z);
// }

// void readPoly(Poly *myPoly, int name, int nTerms) {
//     zeroPoly(myPoly, name);

//     int x;
//     int y;
//     int z;
//     int coeff;

//     for (int i = 0; i < nTerms; i++) {
//         if (scanf("%d %d %d %d", &x, &y, &z, &coeff)) {}
//         Node *v = (Node *) malloc(sizeof(Node));
//         setExpo(v, x, y, z);
//         v -> coeff = coeff;

//         Node *beta = myPoly -> l;
//         Node *alpha = beta -> link;

//         while (isGreater(alpha, v)) {
//             beta = alpha;
//             alpha = alpha -> link;
//         }
        
//         beta -> link = v;
//         v -> link = alpha;

//         // printf("x: %d, y: %d, z: %d, coeff: %d\n", x, y, z, coeff);
//     }

// }

// void displayPoly(Poly *myPoly) {
//     Node *head = myPoly -> l;
//     int coeff;
//     int x;
//     int y;
//     int z;

//     while (true) {
//         coeff = head -> coeff;
//         x = (head -> expo)[0];
//         y = (head -> expo)[1];
//         z = (head -> expo)[2]; 

//         printf("x%dy%dz%d(%d) ", x, y, z, coeff);

//         head = head -> link;
//         if (head == (myPoly -> l)) break;
//     }
//     newLine;
// }

// void displayOutput(Poly *myPoly) {
//     Node *head = myPoly -> l;
//     double coeff;
//     int x;
//     int y;
//     int z;

//     while (true) {
//         head = head -> link;
//         if (head == (myPoly -> l)) break;

//         coeff = head -> coeff;
//         x = (head -> expo)[0];
//         y = (head -> expo)[1];
//         z = (head -> expo)[2]; 

//         printf("%d %d %d %.3lf\n", x, y, z, coeff);
//     }
// }

// int main() {
//     int nTerms1 = 3;
//     Poly myPoly1;
//     initPoly(&myPoly1);
//     readPoly(&myPoly1, 1, nTerms1);
//     displayPoly(&myPoly1);

//     int nTerms2 = 5;
//     Poly myPoly2;
//     initPoly(&myPoly2);
//     readPoly(&myPoly2, 2, nTerms2);
//     displayPoly(&myPoly2);

//     Node *alpha = myPoly1.l -> link;
//     Node *beta = myPoly2.l -> link;
//     Node *sigma = myPoly2.l;

//     while (true) {
//         printf("0\n");
//         if (isLess(alpha, beta)) {
//             printf("0\n");
//             sigma = beta;
//             beta = beta -> link;
//         } else if (isEqual(alpha, beta)) {
//             printf("1\n");
//             if (alpha == (myPoly1.l)) {
//                 myPoly2.name = 0;
//                 break;
//             }
            
//             beta -> coeff = (beta -> coeff) + (alpha -> coeff);
//             if ((beta -> coeff) == 0) {
//                 Node *tao = beta;
//                 sigma -> link = beta -> link;
//                 beta = beta -> link;
//                 free(tao);
//             } else {
//                 sigma = beta;
//                 beta = beta -> link;
//             }
//             alpha = alpha -> link;
//         } else if (isGreater(alpha, beta)) {
//             printf("2\n");
//             Node *tao = (Node *) malloc(sizeof(Node));
//             tao -> coeff = alpha -> coeff;
//             copyExpo(tao, alpha);
//             sigma -> link = tao;
//             tao -> link = beta;
//             sigma = tao;
//             alpha = alpha -> link;
//         }
//     }

//     displayOutput(&myPoly2);

//     return 0;
// }


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int expo[3];
    int coeff;
    struct Node *link;
} Node;

typedef struct Poly {
    Node *l;
    int name;
} Poly;

void initPoly(Poly *myPoly) {
    myPoly -> l = NULL;
    myPoly -> name = 0;
}

void setExpo(Node *myNode, int x, int y, int z) {
    (myNode -> expo)[0] = x;
    (myNode -> expo)[1] = y;
    (myNode -> expo)[2] = z;
}

void zeroPoly(Poly *myPoly, int name) {
    Node *tao = (Node *) malloc(sizeof(Node));
    myPoly -> l = tao;
    myPoly -> name = name;
    setExpo(tao, 0, 0, 1);
    tao -> link = tao;
    tao -> coeff = -1;
}

bool isGreater(Node *termA, Node *termB) {
    int x[2];
    int y[2];
    int z[2];

    x[0] = (termA -> expo)[0];
    x[1] = (termB -> expo)[0];
    y[0] = (termA -> expo)[1];
    y[1] = (termB -> expo)[1];
    z[0] = (termA -> expo)[2];
    z[1] = (termB -> expo)[2];

    if (x[0] > x[1]) {
        return true;
    } else if (x[0] == x[1]) {
        if (y[0] > y[1]) {
            return true;
        } else if (y[0] == y[1]) {
            if (z[0] > z[1]) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    } else {
        return false;
    }
}

bool isEqual(Node *termA, Node *termB) {
    int x[2];
    int y[2];
    int z[2];

    x[0] = (termA -> expo)[0];
    x[1] = (termB -> expo)[0];
    y[0] = (termA -> expo)[1];
    y[1] = (termB -> expo)[1];
    z[0] = (termA -> expo)[2];
    z[1] = (termB -> expo)[2];

    bool isXsame = x[0] == x[1];
    bool isYsame = y[0] == y[1];
    bool isZsame = z[0] == z[1];

    if (isXsame && isYsame && isZsame) {
        return true;
    } else {
        return false;
    }
}

bool isLess(Node *termA, Node *termB) {
    return !(isGreater(termA, termB)) && !(isEqual(termA, termB));
}

void copyExpo(Node *termA, Node *termB) {
    int x = (termB -> expo)[0];
    int y = (termB -> expo)[1];
    int z = (termB -> expo)[2];

    setExpo(termA, x, y, z);
}

void readPoly(Poly *myPoly, int name, int nTerms) {
    zeroPoly(myPoly, name);

    int x;
    int y;
    int z;
    int coeff;

    for (int i = 0; i < nTerms; i++) {
        if (scanf("%d %d %d %d", &x, &y, &z, &coeff)) {}
        Node *v = (Node *) malloc(sizeof(Node));
        setExpo(v, x, y, z);
        v -> coeff = coeff;

        Node *beta = myPoly -> l;
        Node *alpha = beta -> link;

        while (isGreater(alpha, v)) {
            beta = alpha;
            alpha = alpha -> link;
        }
        
        beta -> link = v;
        v -> link = alpha;
    }

}

void displayOutput(Poly *myPoly) {
    Node *head = myPoly -> l;
    double coeff;
    int x;
    int y;
    int z;

    while (true) {
        head = head -> link;
        if (head == (myPoly -> l)) break;

        coeff = head -> coeff;
        x = (head -> expo)[0];
        y = (head -> expo)[1];
        z = (head -> expo)[2]; 

        printf("%d %d %d %.3lf\n", x, y, z, coeff);
    }
}

int main() {
    int nTerms1;
    if (scanf("%d", &nTerms1)) {}
    Poly myPoly1;
    initPoly(&myPoly1);
    readPoly(&myPoly1, 1, nTerms1);

    int nTerms2;
    if (scanf("%d", &nTerms2)) {}
    Poly myPoly2;
    initPoly(&myPoly2);
    readPoly(&myPoly2, 2, nTerms2);

    Node *alpha = myPoly1.l -> link;
    Node *beta = myPoly2.l -> link;
    Node *sigma = myPoly2.l;

    while (true) {
        if (isLess(alpha, beta)) {
            sigma = beta;
            beta = beta -> link;
        } else if (isEqual(alpha, beta)) {
            if (alpha == (myPoly1.l)) {
                myPoly2.name = 3;
                break;
            }
            
            beta -> coeff = (beta -> coeff) + (alpha -> coeff);
            if ((beta -> coeff) == 0) {
                Node *tao = beta;
                sigma -> link = beta -> link;
                beta = beta -> link;
                free(tao);
            } else {
                sigma = beta;
                beta = beta -> link;
            }
            alpha = alpha -> link;
        } else if (isGreater(alpha, beta)) {
            Node *tao = (Node *) malloc(sizeof(Node));
            tao -> coeff = alpha -> coeff;
            copyExpo(tao, alpha);
            sigma -> link = tao;
            tao -> link = beta;
            sigma = tao;
            alpha = alpha -> link;
        }
    }

    displayOutput(&myPoly2);

    return 0;
}
