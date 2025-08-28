#include<stdio.h>

int main(void) {
    // 1093번 문제
    int arr[24] = {};
    int n, c;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &c);
        arr[c]++;
    }
    for(int i=1; i<=23; i++) {
        printf("%d ", arr[i]);
    }
    
    // 1094번 문제
    int n;
    int arr[10001] = {0};
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    for(int i=n-1; i>=0; i--) {
        printf("%d ", arr[i]);
    }

    // 1095번 문제
    int n, k, i, arr[10000], min=24;
	scanf("%d", &n);
	for (i=0; i<n; i++) {
	    scanf("%d", &k);
	    arr[i] = k;
	}
	
	for (i=0; i<n; i++) {
	    if (arr[i] < min)
	        min = arr[i];
	}
	printf("%d", min);

    // 1096번 문제
    int matrix[20][20] = { 0, };
    int n,x,y;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d %d", &x, &y);
        matrix[x][y] = 1;
    }
    for (int i = 1; i <= 19; i++)
    {
        for (int j = 1; j <= 19; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // 1097번 문제
    int n,i,j,x,y;
    int a[20][20];
    for(i=1; i<=19; i++) {
        for(j=1; j<=19; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        scanf("%d %d", &x, &y);
        for(j=1; j<=19; j++) {
            if(a[x][j] == 0) {
                a[x][j] = 1;
            }else {
                a[x][j] = 0;
            }
        }
        for(j=1; j<=19; j++) {
            if(a[j][y] == 0) {
                a[j][y] = 1;
            }else {
                a[j][y] = 0;
            }
        }
    }
    
    for(i=1; i<=19; i++) {
        for(j=1; j<=19; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    //1098번 문제
    int h,w,n,l,d,x,y;
    
    scanf("%d %d",&h,&w);
    scanf("%d",&n);
    
    for(int i = 1; i <= n; i++){
        scanf("%d %d %d %d",&l,&d,&x,&y);
        if(d == 0){
            for(int j = 0; j<l; j++){
                matrix[x][y+j] = 1;
            }
        }
        else{
            for(int j = 0; j<l; j++){
                matrix[x+j][y] = 1;
            }
        }
    }
    
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // 1099번 문제
    int matrix[11][11] = {};
    for(int j = 1; j<=10; j++ ){
        for(int i = 1; i<=10; i++ ){
            scanf("%d ",&matrix[j][i]);
        }
    }
    int x,y;
    x = 2;
    y = 2;
    
    while(1){
 
        
        if(matrix[x][y] == 0){
            matrix[x][y] = 9;
            y ++;
        }
        if(matrix[x][y] == 1){
            y --;
            x++;
        }
        
        if(matrix[x][y] == 2){
            matrix[x][y] = 9;
            break;
        }
        else if(matrix[x][y+1] == 1 && matrix[x+1][y] == 1){
            if(matrix[x][y] == 0){
                matrix[x][y] = 9;
            }
            break;
        }
        
        
 
        
    }
    
    for(int i = 1; i <= 10; i++){
        for(int j =1; j <= 10; j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}