#include <stdio.h>
#include <string.h>

char names[100][20];
char phones[100][15];
int contact_count = 0;

void add_contact() {
    if(contact_count >= 100) {
        printf("더 이상 추가할 수 없습니다.\n");
        return;
    }

    printf("이름 입력: ");
    scanf("%s", names[contact_count]);

    printf("전화번호 입력: ");
    scanf("%s", phones[contact_count]);

    contact_count++;
    printf("연락처가 추가되었습니다!\n");
}

void search_contact() {
    char search_name[20];
    printf("검색할 이름: ");
    scanf("%s", search_name);

    for(int i = 0; i < contact_count; i++) {
        if(strcmp(names[i], search_name) == 0) {
            printf("이름: %s, 전화번호: %s\n", names[i], phones[i]);
            return;
        }
    }
    printf("해당 이름의 연락처를 찾을 수 없습니다.\n");
}

void print_all_contacts() {
    printf("\n== 연락처 목록 ==\n");
    for(int i = 0; i < contact_count; i++) {
        printf("%d. 이름: %s, 전화번호: %s\n", i + 1, names[i], phones[i]);
    }
}

int main() {
    int choice;

    while(1) {
        printf("\n메뉴:\n1. 추가\n2. 검색\n3. 전체 출력\n4. 종료\n선택: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_contact();
                break;
            case 2:
                search_contact();
                break;
            case 3:
                print_all_contacts();
                break;
            case 4:
                printf("프로그램을 종료합니다.\n");
                return 0;
            default:
                printf("잘못된 선택입니다.\n");
        }
    }

}
