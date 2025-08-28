#include <stdio.h>

int main(void) {
    char str[100];
    int sum = 0;

    scanf("%s", str);

    for (int i = 0; str[i] != '\0'; i++) {
        sum += str[i] - '0';
    }

    printf("%d\n", sum);

    return 0;
}
