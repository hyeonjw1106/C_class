#include<stdio.h>

int arrSum(int a[100][100]);
int n;

int main(void) {
    int arr[100][100], result;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    result = arrSum(arr);
    printf("%d", result);
    


    return 0;

}

int arrSum(int a[100][100]) {
    int sum = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i == j) {
                sum += a[i][j];
            }
        }
    }
    return sum;
}