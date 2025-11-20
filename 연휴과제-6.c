#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("메모리 할당 실패\n");
        return 1;
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        }
    return prev;
}

int main(void) {
    Node* head = NULL;
    Node* tail = NULL;
    int n;

    printf("노드의 개수를 입력하세요 : ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int value;
        printf("노드 %d의 값 입력 : ", i + 1);
        scanf("%d", &value);

        Node* newNode = createNode(value);

        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    head = reverseList(head);

    printf("\n역순으로 연결리스트 출력 : \n");
    Node* cur = head;
    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");

    cur = head;
    while (cur != NULL) {
        Node* temp = cur;
        cur = cur->next;
        free(temp);
    }

    return 0;
}
