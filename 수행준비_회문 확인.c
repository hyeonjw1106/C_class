#include<stdio.h>

int palin(char a[100]);

int main(void) {
    char n[100];
    scanf("%s", n[100]);
    int result = palin(n);
    printf("%d", result);

    return 0;
}

int palin(char a[100]) {
    int f = 0;
    int b = -1;
    for(int i=f; i<-b; i++) {
        if (a[f] != a[b]) {
            return -1;
        }
    }
    return 1;
}