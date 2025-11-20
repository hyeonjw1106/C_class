#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

int main(void) {
    Node *head = NULL;
    Node *tail = NULL;
    Node *newNode;
    int i, value;

    for (i = 0; i < 4; i++) {
        newNode = (Node *)malloc(sizeof(Node));
        if (newNode == NULL) {
            printf("메모리 할당 실패\n");
            return 1;
        }

        printf("노드 %d의 값을 입력하세요: ", i + 1);
        scanf("%d", &value);

        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = head;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    printf("\n연결리스트의 모든 데이터:\n");
    tail = head;
    i = 1;
    while (tail != NULL) {
        printf("노드 %d: %d\n", i, tail->data);
        tail = tail->next;
        i++;
    }

    tail = head;
    while (tail != NULL) {
        Node *tmp = tail;
        tail = tail->next;
        free(tmp);
    }

    return 0;
}
