#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int value); 
Node* insert_first(Node* head, int value);
Node* insert_mid(Node* head, int pos, int value);
Node* insert_last(Node* head, int value);

Node* delete_first(Node* head);
Node* delete_mid(Node* head, int pos);
Node* delete_last(Node* head);

void freeList(Node* head);
void printList(Node* head);

int main(void) {
    int n1, value, pos, choice;
    Node* head = NULL;
    Node* tail = NULL;

    printf("기존 노드 개수: ");
    scanf("%d", &n1);

    for(int i = 0; i < n1; i++) {
        printf("노드 %d 값 입력: ", i+1);
        scanf("%d", &value);

        Node* newNode = createNode(value);
        if(head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    while (1) {
        printList(head);
        printf("\n메뉴 선택:\n");
        printf("1. 첫번째 삽입\n");
        printf("2. 중간 삽입\n");
        printf("3. 마지막 삽입\n");
        printf("4. 첫번째 삭제\n");
        printf("5. 중간 삭제\n");
        printf("6. 마지막 삭제\n");
        printf("7. 종료\n");
        printf("선택: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("삽입할 값 입력: ");
                scanf("%d", &value);
                head = insert_first(head, value);
                break;
            case 2:
                printf("삽입 위치 입력: ");
                scanf("%d", &pos);
                printf("삽입할 값 입력: ");
                scanf("%d", &value);
                head = insert_mid(head, pos, value);
                break;
            case 3:
                printf("삽입할 값 입력: ");
                scanf("%d", &value);
                head = insert_last(head, value);
                break;
            case 4:
                head = delete_first(head);
                break;
            case 5:
                printf("삭제 위치 입력: ");
                scanf("%d", &pos);
                head = delete_mid(head, pos);
                break;
            case 6:
                head = delete_last(head);
                break;
            case 7:
                printf("프로그램을 종료합니다.\n");
                freeList(head);
                return 0;
            default:
                printf("잘못된 선택입니다.\n");
        }
    }
    return 0;
}



Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

Node* insert_first(Node* head, int value) {
    Node* newNode = createNode(value);
    newNode->next = head;
    return newNode;
}

Node* insert_mid(Node* head, int pos, int value) {
    if(pos == 1) return insert_first(head, value);

    Node* newNode = createNode(value);
    Node* cur = head;

    for(int i = 1; i < pos-1; i++) {
        if(cur->next == NULL) break;
        cur = cur->next;
    }

    newNode->next = cur->next;
    cur->next = newNode;
    return head;
}

Node* insert_last(Node* head, int value) {
    Node* newNode = createNode(value);
    if(head == NULL) return newNode;

    Node* cur = head;
    while(cur->next != NULL) cur = cur->next;

    cur->next = newNode;
    return head;
}

Node* delete_first(Node* head) {
    if(head == NULL) return NULL;

    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

Node* delete_mid(Node* head, int pos) {
    if(head == NULL || pos <= 1) return delete_first(head);

    Node* cur = head;
    for(int i = 1; i < pos-1; i++) {
        if(cur->next == NULL) return head;
        cur = cur->next;
    }

    Node* remove = cur->next;
    if(remove == NULL) return head;

    cur->next = remove->next;
    free(remove);
    return head;
}

Node* delete_last(Node* head) {
    if(head == NULL) return NULL;
    if(head->next == NULL) {
        free(head);
        return NULL;
    }

    Node* cur = head;
    while(cur->next->next != NULL) cur = cur->next;

    Node* remove = cur->next;
    cur->next = NULL;
    free(remove);

    return head;
}

void printList(Node* head) {
    Node* cur = head;
    printf("\n현재 리스트: ");
    while(cur != NULL) {
        printf("%d -> ", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}

void freeList(Node* head) {
    Node* cur = head;
    while(cur != NULL) {
        Node* temp = cur;
        cur = cur->next;
        free(temp);
    }
}
