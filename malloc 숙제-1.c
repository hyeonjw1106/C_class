#include <stdio.h>
#include <stdlib.h> 

// 동적 할당해서 입력한 값 합
int main(void) {
    int n;
    printf("정수 개수 입력 : ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("메모리 할당 실패\n");
        return 1;
    }

    int sum = 0;
    printf("%d개 정수 입력:", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    printf("합계 = %d\n", sum);
    free(arr);

    return 0;
}
