#include <stdio.h>

#define MAX_DEGREE 101

typedef struct {
    int degree;
    float coef[MAX_DEGREE];
} polynomial;

polynomial addPoly(polynomial A, polynomial B) {
    polynomial C;
    int Apos = 0, Bpos = 0, Cpos = 0;
    int degree_a = A.degree;
    int degree_b = B.degree;
    C.degree = A.degree > B.degree ? A.degree : B.degree;

    while (Apos <= A.degree && Bpos <= B.degree) {
        if (degree_a > degree_b) {
            C.coef[Cpos++] = A.coef[Apos++];
            degree_a--;
        } else if (degree_a == degree_b) {
            C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];
            degree_a--;
            degree_b--;
        } else {
            C.coef[Cpos++] = B.coef[Bpos++];
            degree_b--;
        }
    }
    return C;
}


void printPoly(polynomial p) {
    for (int i = 0; i <= p.degree; i++) {
        printf("%3.1fx^%d", p.coef[i], p.degree - i);
        if (i < p.degree) printf(" +");
    }
    printf("\n");
}



int main() {
    polynomial a = {5, {3, 6, 0, 0, 0, 10}};
    polynomial b = {4, {7, 0, 5, 0, 1}};
    polynomial c;
    c = addPoly(a, b);

    printf("\n A(x) = ");
    printPoly(a);
    printf("\n B(x) = ");
    printPoly(b);
    printf("\n C(x) = ");
    printPoly(c);
    return 0;
}



