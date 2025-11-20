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

int main(void) {
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

    int pos;
    printf("삭제할 노드 위치 입력 : ");
    scanf("%d", &pos);

    if (pos < 1) {
        printf("잘못된 위치입니다.\n");
    } else if (pos == 1) {
        Node* temp = head;
        if (head) {
            head = head->next;
            free(temp);
        } else {
            printf("삭제할 노드가 없습니다.\n");
        }
    } else {
        Node* prev = head;
        for (int i = 1; i < pos - 1 && prev != NULL; i++) {
            prev = prev->next;
        }

        if (!prev || !prev->next) {
            printf("삭제할 위치가 연결리스트 길이보다 큽니다.\n");
        } else {
            Node* temp = prev->next;
            prev->next = temp->next;
            free(temp);
        }
    }

    printf("\n삭제 후 연결리스트 출력 : \n");
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
