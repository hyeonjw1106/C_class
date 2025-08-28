#include<stdio.h>

int fibo(int a);

int main(void) {
    int n, result;
    scanf("%d", &n);
    result = fibo(n);
    printf("%d", result);

    return 0;
}

int fibo(int a) {
    if(a == 0) return 0;
    if(a == 1) return 1;
    return fibo(a-1) + fibo(a-2);
}