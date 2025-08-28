#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);

    int a[10001]; 
    a[1] = 1;
    a[2] = 2;

    for (int i = 3; i <= n; i++) {
        a[i] = (a[i - 1] + a[i - 2]) % 100000007;
    }

    printf("%d\n", a[n]);
    return 0;
}