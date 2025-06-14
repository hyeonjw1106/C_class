#include <stdio.h>

int main() {
    int n;

    printf("수를 입력하세요: ");
    scanf("%d", &n);

    if (n < 1) {
        printf("양수를 입력해야 합니다.\n");
        return 1;
    }
    int mid = n / 2;
    for (int i = 0; i < mid + (n % 2); i++) {
        for (int j = 0; j < mid - i; j++) {
            printf(" ");
        }
        for (int j = 0; j < 2 * i + 1; j++) {
            printf("*");
        }
        printf("\n");
    }

    for (int i = mid - 1; i >= 0; i--) {
        for (int j = 0; j < mid - i; j++) {
            printf(" ");
        }
        for (int j = 0; j < 2 * i + 1; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}