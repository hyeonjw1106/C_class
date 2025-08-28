#include <stdio.h>

int main(void) {
    char input[1000];    
    char output[1000];
    int i = 0, j = 0;      

    printf("문자열 입력: ");
    scanf("%s", input);

    while (input[i] != '\0') {
        char current = input[i];
        int count = 1;           

        while (input[i] == input[i + 1]) {
            count++;    
            i++;        
        }

        output[j++] = current;
        if (count > 1) {
            if (count >= 10) {
                output[j++] = '0' + (count / 10);
            }

            output[j++] = '0' + (count % 10);
        }

        i++;
    }

    printf("압축 결과: %s\n", output);

    return 0;
}
