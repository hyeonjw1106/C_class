#include <stdio.h>
#include <stdlib.h>

int contains(int *arr, int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) return 1; 
    }
    return 0;
}

int main(void) {
    int n;
    printf("정수 개수 입력: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("메모리 할당 실패\n");
        return 1;
    }

    printf("%d개 정수 입력 : ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int *uniqueArr = 0;
    int uniqueSize = 0;

    for (int i = 0; i < n; i++) {
        if (!contains(uniqueArr, uniqueSize, arr[i])) {
            int *temp = (int *)realloc(uniqueArr, (uniqueSize + 1) * sizeof(int));
            if (temp == NULL) {
                printf("메모리 재할당 실패\n");
                free(uniqueArr);
                free(arr);
                return 1;
            }
            uniqueArr = temp;
            uniqueArr[uniqueSize] = arr[i];
            uniqueSize++;
        }
    }

    printf("%d\n", uniqueSize);
    for (int i = 0; i < uniqueSize; i++) {
        printf("%d ", uniqueArr[i]);
    }
    printf("\n");
    
    free(arr);
    free(uniqueArr);

    return 0;
}
