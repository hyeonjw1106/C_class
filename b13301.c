#include<stdio.h>

int num;
int a = 0, b = 1;
int i, j;

int main() {
    scanf("%d", &num);
    
    for (i = 0; i < num; i++) {
        int tmp = a + b;
        a = b;
        b = tmp;
    }
    printf("%d\n", (a + b) * 2);
    
    return 0;
}