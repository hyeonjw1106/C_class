#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    printf("정수 개수 입력 (최대 15): ");
    scanf("%d", &n);

    if (n < 1 || n > 15) {
        printf("1~15 사이의 정수만 입력 가능합니다.\n");
        return 1;
    }

    int numbers[15];
    printf("%d개 정수 입력: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    int *evenArr = 0;
    int evenSize = 0;

    for (int i = 0; i < n; i++) {
        if (numbers[i] % 2 == 0) {
            int *temp = (int *)realloc(evenArr, (evenSize + 1) * sizeof(int));
            if (temp == NULL) {
                printf("메모리 재할당 실패\n");
                free(evenArr);
                return 1;
            }
            evenArr = temp;
            evenArr[evenSize] = numbers[i];
            evenSize++;
        }
    }

    for (int i = 0; i < evenSize; i++) {
        printf("%d ", evenArr[i]);
    }
    printf("\n");

    free(evenArr);
    return 0;
}
