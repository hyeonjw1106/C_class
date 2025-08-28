#include <stdio.h>

int palin(char a[100]);

int main(void) {
    char n[100];
    scanf("%s", n);
    int result = palin(n);
    printf("%d\n", result);

    return 0;
}

int palin(char a[100]) {
    int len = 0;
    while (a[len] != '\0') {
        len++;
    }

    for (int i = 0; i < len / 2; i++) {
        if (a[i] != a[len - 1 - i]) {
            return -1; 
        }
    }

    return 1; 
}