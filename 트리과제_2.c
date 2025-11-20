#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
}Node;

void pre(Node *root);
void in(Node *root);
void post(Node *root);

int main(void) {
    int n;
    printf("노드 개수를 입력하세요: ");
    scanf("%d", &n);

    Node *nodes[n+1];
    for (int i = 1; i <= n; i++) {
        nodes[i] = (Node *)malloc(sizeof(Node));
        if (!nodes[i]) {
            printf("메모리 할당 실패\n");
            return 1;
        }
        printf("%d번째 노드 데이터 입력: ", i);
        scanf("%d", &nodes[i]->data);
        nodes[i]->left = NULL;
        nodes[i]->right = NULL;
    }

    for (int i = 1; i <= n; i++) {
        int left = 2*i;
        int right = 2*i + 1;
        if (left <= n)
            nodes[i]->left = nodes[left];
        if (right <= n)
            nodes[i]->right = nodes[right];
    }

    Node *root = nodes[1];

    int choice;
    printf("\n출력할 순회 방법을 선택하세요:\n");
    printf("1. 전위\n");
    printf("2. 중위\n");
    printf("3. 후위\n");
    printf("번호 입력: ");
    scanf("%d", &choice);

    printf("\n순회 결과\n");

    switch (choice) {
        case 1:
            printf("전위 순회 : ");
            pre(root);
            break;
        case 2:
            printf("중위 순회 : ");
            in(root);
            break;
        case 3:
            printf("후위 순회 : ");
            post(root);
            break;
        default:
            printf("잘못된 번호.\n");
            break;
    }

    printf("\n");

    for (int i = 1; i <= n; i++)
        free(nodes[i]);

    return 0;
}

void pre(Node *root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    pre(root->left);
    pre(root->right);
}

void in(Node *root) {
    if (root == NULL) return;
    in(root->left);
    printf("%d ", root->data);
    in(root->right);
}

void post(Node *root) {
    if (root == NULL) return;
    post(root->left);
    post(root->right);
    printf("%d ", root->data);
}
