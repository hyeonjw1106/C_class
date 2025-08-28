#include <stdio.h>

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    int num = 1;
    int a[101][101];
    for(int i=0; i<=m+n-2; i++) {
        for(int j=0; j<m; j++) {
            int s = i-j;
            if (s>=0 && s<n) {
                a[s][j] = num++;
            }
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
