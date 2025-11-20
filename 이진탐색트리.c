#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    struct Node *left;
    struct Node *right;
} Node;

Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
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

Node* search(Node* root, int key) {
    if (root == NULL)
        return NULL;

    if (root->key == key)
        return root;

    if (key < root->key)
        return search(root->left, key);
    else
        return search(root->right, key);
}

Node* findMin(Node* node) {
    while (node->left != NULL)
        node = node->left;
    return node;
}

Node* deleteNode(Node* root, int key) {
    if (root == NULL)
        return NULL;

    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    }
    else {
        
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        
        else if (root->left == NULL) {
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

Node* findLCA(Node* root, int a, int b) {
    if (root == NULL)
        return NULL;

    if (a < root->key && b < root->key)
        return findLCA(root->left, a, b);

    if (a > root->key && b > root->key)
        return findLCA(root->right, a, b);

    return root;
}

int main(void) {
    Node* root = NULL;
    int n, value, target, del, a, b;

    printf("삽입할 노드 개수 입력: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("%d번째 값 입력: ", i + 1);
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("\n탐색할 값을 입력하세요: ");
    scanf("%d", &target);

    Node* result = search(root, target);
    if (result == NULL)
        printf("%d 값을 찾지 못했습니다.\n", target);
    else
        printf("%d 값을 찾았습니다!\n", result->key);

    printf("\n삭제할 값을 입력하세요: ");
    scanf("%d", &del);
    root = deleteNode(root, del);
    printf("%d 삭제 완료.\n", del);

    printf("\nLCA를 찾을 두 값 입력 (예: 5 15): ");
    scanf("%d %d", &a, &b);

    Node* lca = findLCA(root, a, b);
    if (lca == NULL)
        printf("LCA를 찾지 못했습니다.\n");
    else
        printf("(%d, %d)의 최저공통조상(LCA)은 %d 입니다.\n", a, b, lca->key);

    return 0;
}
