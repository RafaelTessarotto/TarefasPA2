#include <stdio.h>
#include <stdbool.h>

bool divisorGame(int n) {
    return n % 2 == 0;
}

int main() {
    printf("Alice vence (n=2)? %s\n", divisorGame(2) ? "verdadeiro" : "falso");
    printf("Alice vence (n=3)? %s\n", divisorGame(3) ? "verdadeiro" : "falso");

    return 0;
}