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
    int i, value, sum=0;

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

        sum += value;
    }

    double avg = sum / 4;
    printf("\n입력한 데이터의 평균값: %.2f\n", avg);

    tail = head;
    while (tail != NULL) {
        Node *tmp = tail;
        tail = tail->next;
        free(tmp);
    }

    return 0;
}