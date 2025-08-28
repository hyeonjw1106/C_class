#include<stdio.h>

int main(void) {
    int n, di=0, x=0, y=0;
    scanf("%d", &n);
    int a[n][n];
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            a[i][j] = -1;
        }
    }
    for(int i=1; i<n*n+1; i++) {
        if(di == 0) {
            a[y][x] = i;
            x++;
            if(a[y][x] != -1 || x == n) {
                x--;
                y++;
                di = 1;
            }
        }
        
        else if(di == 1) {
            a[y][x] = i;
            y++;
            if(a[y][x] != -1 || y == n) {
                y--;
                x--;
                di = 2;
            }
        }
        
        else if(di == 2) {
            a[y][x] = i;
            x--;
            if(a[y][x] != -1 || x == -1) {
                x++;
                y--;
                di = 3;
            }
        }
        
        else if(di == 3) {
            a[y][x] = i;
            y--;
            if(a[y][x] != -1 || y == -1) {
                y++;
                x++;
                di = 0;
            }
        }
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    
    
    return 0;
}