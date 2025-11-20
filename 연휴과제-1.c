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

void printList(Node* head) {
    Node* current = head;
    int pos = 1;
    while (current != NULL) {
        printf("노드 %d: %d\n", pos, current->data);
        current = current->next;
        pos++;
    }
}

void findValue(Node* head, int value) {
    Node* current = head;
    int pos = 1;
    int found = 0;
    while (current != NULL) {
        if (current->data == value) {
            printf("%d는 %d에 있습니다.\n", value, pos);
            found = 1;
            break;
        }
        current = current->next;
        pos++;
    }
    if (!found) {
        printf("%d는 리스트에 없습니다.\n", value);
    }
}

int main(void) {
    Node* head = NULL;
    Node* tail = NULL;
    int n, value;

    printf("노드의 개수를 입력하세요 : ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("노드 %d의 데이터 입력 : ", i + 1);
        scanf("%d", &value);
        Node* newNode = createNode(value);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    printf("\n찾고 싶은 정수를 입력하세요 : ");
    scanf("%d", &value);
    findValue(head, value);

    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
