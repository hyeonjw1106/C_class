#include<stdio.h>

int until_sum(int n);
int until_sum_return(int n);

int main(void) {
    int u;
    scanf("%d", &u);
    int result = until_sum_return(u);
    printf("%d", result);



    return 0;
}

int until_sum(int n) {
    int sum = 0;
    for(int i=1; i<=n; i++) {
        sum += i;
    }
    return sum;
}
int until_sum_return(int n) {
    if (n == 1) {
        return 1;
    }
    return n + until_sum_return(n-1);
}