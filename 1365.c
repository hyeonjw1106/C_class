#include<stdio.h>

int main(void) {
    int a;
    scanf("%d", &a);
    for(int i=0; i<a; i++) {
        for (int j=0; j<a; j++) {
            if ((i == 0) || (j == 0) || (i == a-1) || (j == a-1) || (i == j) || (i+j == a-1)) {
                printf("*");
            }else {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}