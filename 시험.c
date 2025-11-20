#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("메모리 할당 실패\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* findMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* findOneThird(Node* head) {
    Node* slow = head;
    Node* fast = head;
    int step = 0;

    while (fast != NULL && fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;             // 1칸
        fast = fast->next->next->next; // 3칸
        step++;
    }
    return slow;
}

// 노드 삽입 (target 뒤에 새 노드 추가)
void insertAfter(Node* target, int data) {
    if (target == NULL) return;
    Node* newNode = createNode(data);
    newNode->next = target->next;
    target->next = newNode;
}
1 
// 노드 삭제 (target 다음 노드를 삭제)
void deleteNext(Node* target) {
    if (target == NULL || target->next == NULL) return;
    Node* temp = target->next;
    target->next = target->next->next;
    free(temp);
}

int main(void) {
    Node* head = NULL;
    Node* tail = NULL;
    int N;

    printf("노드의 개수를 입력하세요: ");
    scanf("%d", &N);

    // N개 노드 입력 및 생성
    for (int i = 0; i < N; i++) {
        int data;
        printf("%d번째 데이터 입력: ", i + 1);
        scanf("%d", &data);

        Node* newNode = createNode(data);

        if (!head)
            head = tail = newNode;
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // 1/2 위치 찾고 그 뒤에 노드 삽입
    Node* mid = findMiddle(head);
    if (mid) {
        int insertData;
        printf("\n1/2 위치 노드(%d) 뒤에 삽입할 값 입력: ", mid->data);
        scanf("%d", &insertData);
        insertAfter(mid, insertData);
    }

    // 1/3 위치 찾고 그 위치의 다음 노드를 2번 삭제
    Node* oneThird = findOneThird(head);
    if (oneThird) {
        printf("\n1/3 위치 노드(%d) 다음 노드를 2번 삭제합니다.\n", oneThird->data);
        deleteNext(oneThird);
        deleteNext(oneThird);
    }

    // 메모리 해제
    Node* cur = head;
    while (cur != NULL) {
        Node* temp = cur;
        cur = cur->next;
        free(temp);
    }

    return 0;
}
