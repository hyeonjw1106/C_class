#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 문자열 입력받고 동적 할당 후 가장 긴 문자열 찾아 출력
#define MAX_STRINGS 10
#define MAX_LENGTH 1000

int main() {
    char *strings[MAX_STRINGS];
    char buffer[MAX_LENGTH];
    int count = 0; 
    int longest_index = 0;      
    int max_length = 0;      
    
    printf("최대 %d개의 문자열을 입력하세요 (빈 줄로 입력 종료):\n", MAX_STRINGS);
    
    while (count < MAX_STRINGS) {
        printf("문자열 %d: ", count + 1);
        
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            break;
        }
        

        buffer[strcspn(buffer, "\n")] = '\0';

        if (strlen(buffer) == 0) {
            break;
        }
        
        int len = strlen(buffer);
        strings[count] = (char *)malloc((len + 1) * sizeof(char));
        
        if (strings[count] == NULL) {
            printf("메모리 할당 실패!\n");
            for (int i = 0; i < count; i++) {
                free(strings[i]);
            }
            return 1;
        }
        
        strcpy(strings[count], buffer);
        
        if (len > max_length) {
            max_length = len;
            longest_index = count;
        }
        
        count++;
    }
    
    if (count > 0) {
        printf("입력된 문자열들:\n");
        for (int i = 0; i < count; i++) {
            printf("%d. \"%s\" (길이: %lu)\n", i + 1, strings[i], strlen(strings[i]));
        }
        
        printf("\n가장 긴 문자열: \"%s\"\n", strings[longest_index]);
        printf("길이: %d문자\n", max_length);
        
    } else {
        printf("입력된 문자열이 없습니다.\n");
    }
    
    for (int i = 0; i < count; i++) {
        free(strings[i]);
        strings[i] = NULL;
    }
    
    return 0;
}
