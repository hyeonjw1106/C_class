#include<stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    int a[101][101];
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
}