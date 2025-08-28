#include<stdio.h>

int case_changer(char c);

int main(void) {
    char i, result;
    scanf("%c", &i);
    result = case_changer(i);
    printf("%c", result);
}

int case_changer(char c) {
    if (97 <= c)
        return c - 32;
    else
        return c + 32;
}