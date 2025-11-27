#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int key) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

Node* insert(Node* root, int key) {
    if (root == NULL)
        return createNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);

    return root;
}

Node* findMin(Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (root == NULL) return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        Node* temp = findMin(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

int height(Node* root) {
    if (root == NULL) return -1;

    int lh = height(root->left);
    int rh = height(root->right);
    if (lh > rh) return lh+1;
    else return rh+1;
    
}

Node* LCA(Node* root, int a, int b) {
    if (root == NULL) return NULL;

    if (a < root->key && b < root->key)
        return LCA(root->left, a, b);
    if (a > root->key && b > root->key)
        return LCA(root->right, a, b);

    return root;
}


int main(void) {
    Node* root = NULL;
    int choice, value, a, b;

    while (1) {
        printf("1. 삽입\n");
        printf("2. 삭제\n");
        printf("3. 트리 높이 출력\n");
        printf("4. 최저 공통 조상(LCA) 찾기\n");
        printf("5. 종료\n");
        printf("선택 : ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("삽입할 값 : ");
            scanf("%d", &value);
            root = insert(root, value);
        }
        else if (choice == 2) {
            printf("삭제할 값 : ");
            scanf("%d", &value);
            root = deleteNode(root, value);
        }
        else if (choice == 3) {
            printf("트리 높이: %d\n", height(root));
        }
        else if (choice == 4) {
            printf("노드 A 입력 : ");
            scanf("%d", &a);
            printf("노드 B 입력 : ");
            scanf("%d", &b);
            Node* lca = LCA(root, a, b);
            if (lca)
                printf("LCA(%d, %d) = %d\n", a, b, lca->key);
            else
                printf("LCA를 찾을 수 없습니다.\n");
        }
        else if (choice == 5) {
            break;
        }
        else {
            printf("잘못된 입력입니다.\n");
        }
    }

    return 0;
}
