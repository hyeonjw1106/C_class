#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode() {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("메모리 할당 실패\n");
        return 1;
    }
    printf("정수 입력 : ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    return newNode;
}

void printReverse(Node* head) {
    if (!head) return;
    printReverse(head->next);
    printf("%d ", head->data);
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    int n;

    printf("노드의 개수를 입력하세요 : ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        Node* newNode = createNode();
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    printf("\n연결리스트 역순 출력 : \n");
    printReverse(head);
    printf("\n");

    Node* cur = head;
    while (cur != NULL) {
        Node* temp = cur;
        cur = cur->next;
        free(temp);
    }

    return 0;
}
