#include<stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);

    if (n % 3 == 0){
        n = n/3;
        int s = 1;
        for (int i=0; i<n; i++) {
            s *= 2;
            s %= 100000007;
        }
        printf("%d", s);
    }else {
        int s = 0;
        printf("%d", s);
    }
    return 0;
}