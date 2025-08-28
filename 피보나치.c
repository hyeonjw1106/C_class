#include<stdio.h>

int fibo(int n);
int fibo_return(int n);

int main(void) {
    int num;
    scanf("%d", &num);
    printf("%d\n", fibo_return(num));

    return 0;
}


int fibo(int n) {
    int a = 0, b = 1;
    for(int i=0; i<n-1; i++) {
        int temp = a+b;
        a = b;
        b = temp;
    }
    return b;
}

int fibo_return(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return fibo_return (n-1) + fibo_return(n-2);
}
