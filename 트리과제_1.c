#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
}Node;

int main(void) {
    int n;
    printf("노드 개수를 입력하세요 : ");
    scanf("%d", &n);

    Node *nodes[n+1];

    for (int i = 1; i <= n; i++) {
        nodes[i] = (Node *)malloc(sizeof(Node));
        if (!nodes[i]) {
            printf("메모리 할당 실패\n");
            return 1;
        }
        printf("%d번째 노드 데이터 입력: ", i + 1);
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

    printf("\n트리 생성 완료");

    for (int i = 1; i <= n; i++)
        free(nodes[i]);

    return 0;
}
