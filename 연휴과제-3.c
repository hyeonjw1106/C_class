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

Node* middle(Node* head) {
    if (head == NULL) return NULL;

    Node* slow = head;  
    Node* fast = head;  

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;        
        fast = fast->next->next;  
    }

    return slow;
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

    int choice;
    printf("삽입 위치 선택 (1: 맨 앞, 2: 중간) : ");
    scanf("%d", &choice);

    Node* insertNode = createNode();

    if (choice == 1) {
        insertNode->next = head;
        head = insertNode;
    } else if (choice == 2) {
        Node* mid = middle(head);
        insertNode->next = mid->next;
        mid->next = insertNode;
    } else {
        printf("잘못된 선택입니다. \n");
        free(insertNode);
    }

    printf("\n연결리스트 출력 : \n");
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
