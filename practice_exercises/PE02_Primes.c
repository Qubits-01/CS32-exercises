#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int a, b;
    bool isPrime, noPrime = true;

    if (scanf("%d", &a));
    if (scanf("%d", &b));

    for (int i = a; i <= b; i++) {
        if (i == 0 || i == 1) continue;

        isPrime = true;
        for (int j = 2; j <= i / 2; ++j) {
            if ((i % j) == 0) {
                isPrime = false;
            }
        }

        if (isPrime) {
            noPrime = false;
            printf("%d ", i);
        };
    }

    if (noPrime) printf("None");

    return 0;
}
