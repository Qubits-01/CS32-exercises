#include <stdio.h>
#include <stdlib.h>

struct Fraction {
        int numerator;
        int denominator;
    };

int getGCD(int a, int b);

struct Fraction toLowestTerm(struct Fraction fraction) {
    int gcd = getGCD(fraction.numerator, fraction.denominator);

    fraction.numerator = fraction.numerator / gcd;
    fraction.denominator = fraction.denominator / gcd;

    return fraction;
}

int getGCD(int a, int b) {
    if (b == 0) {
        return a;
    }
    
    int r = a % b;

    return getGCD(b, r);
}

int main() {
    struct Fraction fraction;

    printf("numerator: ");
    // (void) scanf("%d", &fraction.numerator);
    if(scanf("%d", &fraction.numerator))  // to ignore unused warning

    printf("denominator: ");
    // (void) scanf("%d", &fraction.denominator);
    if(scanf("%d", &fraction.denominator));  // to ignore unused warning

    fraction = toLowestTerm(fraction);

    printf("\n[Lowest Term]\n");
    printf("Numerator: %d\n", fraction.numerator);
    printf("Denominator: %d", fraction.denominator);

    return 0;
}

// #include <stdio.h>
// #include <stdlib.h>

// struct Fraction {
//         int numerator;
//         int denominator;
//     };

// int getGCD(int a, int b);

// struct Fraction toLowestTerm(struct Fraction fraction) {
//     int gcd = getGCD(fraction.numerator, fraction.denominator);

//     fraction.numerator = fraction.numerator / gcd;
//     fraction.denominator = fraction.denominator / gcd;

//     return fraction;
// }

// int getGCD(int a, int b) {
//     if (b == 0) {
//         return a;
//     }
    
//     int r = a % b;

//     return getGCD(b, r);
// }

// int main() {
//     struct Fraction fraction;
//     if (scanf("%d", &fraction.numerator));
//     if (scanf("%d", &fraction.denominator));

//     fraction = toLowestTerm(fraction);
//     printf("%d\n", fraction.numerator);
//     printf("%d", fraction.denominator);
    
//     return 0;
// }
