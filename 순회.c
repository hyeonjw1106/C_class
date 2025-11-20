#include<stdio.h>
#include<string.h>

typedef struct Node {
    char data;
    struct Node *left;
    struct Node *right;
}node;

void preorder(node *node);

int main(void) {

    return 0;
}

void preorder(node *p) {
    if(p == NULL) {
        return;
    }
    printf("%c", p->data);
    preorder(p->left);
    preorder(p->right);
}
