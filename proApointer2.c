#include<stdio.h>

int main(void) {
    char *arr[3][3] = {{'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}}
    int i=1, j=1;
    printf("%p", arr+i);      // 13  (첫 주소를 10으로 가정할 때)
    printf("%s", *(arr + i));   //defghi
    printf("%p", arr[i] + j);   // 14
    printf("%c", *(arr[i++] + j));  // e
    printf("%p", *(arr+i) + j);    // 17
    printf("%c", *(*(arr + i) + j));    // h

    char *p[3] = {"software", "center", "highschool"};
    char **ptr = p;
    printf("%s", *(ptr + 1));   // center
    printf("%c", **(ptr + 2));    // h
    printf("%c", *(*(ptr + 1) + 2));    // n



    return 0;
}