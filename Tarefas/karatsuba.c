#include <stdio.h>

int karatsuba(int x, int y, int n);

int main (){
    int x = 1234;
    int y = 5678;
    int n = 4;

    int result = karatsuba(x, y, n);
    printf("Resultado da multiplicacao: %d\n", result);

    return 0;
}

int karatsuba(int x, int y, int n) {
    if (n = 1) {
        return x*y;
    } else {
        int m = n/2;
        int a = x / (10^m);
        int b = x % (10^m);
        int c = y / (10^m);
        int d = y % (10^m);
        int ac = karatsuba(a, c, m);
        int bd = karatsuba(b, d, m);
        int u = karatsuba((a+b), (c+d), m);
        int xy = 10^n * ac + 10^m * (u - ac - bd) + bd;
        return xy;
    }
}