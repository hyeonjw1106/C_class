#include<stdio.h>

int square_check(int n);

int main(void) {
    int a;
    scanf("%d", &a);
    int result = square_check(a);
    printf("%d", result);

    return 0;
}

int square_check(int n) {
    if ((n > 0) && !(n & (n-1))) {
        return 1;
    }
    return 0;
}