#include<stdio.h>
int fact(int n);
int fact_return(int n);


int main(void) {
    int u;
    scanf("%d", &u);
    printf("%d\n", fact_return(u));


    return 0;

}

int fact(int n) {
    int result = 1;
    for(int i=n; i>0; i--) {
        result = result * i;
    }
    return result;
}

int fact_return(int n) {
    if (n == 1) {
        return 1;
    }
    return n * fact_return(n-1);
}
