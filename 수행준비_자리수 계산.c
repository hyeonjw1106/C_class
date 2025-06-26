#include<stdio.h>

int length(char a[100]);

int main(void) {

    char arr[100];
    scanf("%s", arr);
    int result = length(arr);
    printf("%d", result);

    return 0;
}

int length(char a[100]) {
    int len = 0;
    for(int i=0; i<100; i++) {
        if(a[i] != '\0') {
            len += 1;
        }else {
            break;
        }
    }
    return len;
}