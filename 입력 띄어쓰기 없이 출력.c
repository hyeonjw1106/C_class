#include <stdio.h>
#include <string.h>

int main(void)
{
    char a[100];
    fgets(a, sizeof(a), stdin);

    for(int i = 0; a[i] != '\0'; i++) {
        if(a[i] != ' ') {
            printf("%c", a[i]);
        }
    }

    return 0;
}