#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node {
    char data[MAX];
    struct Node* next;
} Node;

Node* createNode(char str[]) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("메모리 할당 실패\n");
        return 1;
    }
    int i = 0;
    while (str[i] != '\0') {
        newNode->data[i] = str[i];
        i++;
    }
    newNode->next = NULL;
    return newNode;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    int n;

    printf("노드의 개수를 입력하세요 : ");
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++) {
        char str[MAX];
        printf("노드 %d의 문자열을 입력하세요 : ", i + 1);
        fgets(str, MAX, stdin);

        Node* newNode = createNode(str);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    printf("출력 : ");
    Node* current = head;
    while (current != NULL) {
        printf("%s", current->data);
        current = current->next;
    }
    printf("\n");

    current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
