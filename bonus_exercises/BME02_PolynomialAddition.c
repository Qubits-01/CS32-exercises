#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define newLine printf("\n")

typedef struct Node {
    int expo[4];
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

void setExpo(Node *myNode, int sign, int x, int y, int z) {
    (myNode -> expo)[0] = sign;
    (myNode -> expo)[1] = x;
    (myNode -> expo)[2] = y;
    (myNode -> expo)[3] = z;
}

void zeroPoly(Poly *myPoly, int name) {
    Node *tao = (Node *) malloc(sizeof(Node));
    myPoly -> l = tao;
    myPoly -> name = name;
    setExpo(tao, -1, 0, 0, 1);
    tao -> link = tao;
    tao -> coeff = 0;
}

bool isGreater(Node *termA, Node *termB) {
    int x[2];
    int y[2];
    int z[2];

    x[0] = (termA -> expo)[1];
    x[1] = (termB -> expo)[1];
    y[0] = (termA -> expo)[2];
    y[1] = (termB -> expo)[2];
    z[0] = (termA -> expo)[3];
    z[1] = (termB -> expo)[3];

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

void displayPoly(Poly *myPoly) {
    Node *head = myPoly -> l;
    int sign;
    int coeff;
    int x;
    int y;
    int z;

    while (true) {
        sign = (head -> expo)[0];
        coeff = head -> coeff;
        x = (head -> expo)[1];
        y = (head -> expo)[2];
        z = (head -> expo)[3]; 

        printf("(%d)%dx%dy%dz%d ", sign, coeff, x, y, z);

        head = head -> link;
        if (head == (myPoly -> l)) break;
    }
    newLine;
}

int main() {
    int nTerms = 3;
    Poly myPoly;
    initPoly(&myPoly);

    // *zeroPoly
    zeroPoly(&myPoly, 0);
    // *zeroPoly

    int x;
    int y;
    int z;
    int coeff;
    int sign;

    for (int i = 0; i < nTerms; i++) {
        if (scanf("%d %d %d %d", &x, &y, &z, &coeff)) {}
        if (coeff < 0) {
            sign = -1;
            coeff *= -1;
        } else {
            sign = 1;
        }

        Node *v = (Node *) malloc(sizeof(Node));
        setExpo(v, sign, x, y, z);
        v -> coeff = coeff;

        Node *beta = myPoly.l;
        Node *alpha = beta -> link;

        while (isGreater(alpha, v)) {
            beta = alpha;
            alpha = alpha -> link;
        }
        
        beta -> link = v;
        v -> link = alpha;

        // printf("x: %d, y: %d, z: %d, coeff: %d\n", x, y, z, coeff);
    }

    displayPoly(&myPoly);


    return 0;
}
