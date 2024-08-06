#include <stdio.h>
#include <stdlib.h>

struct tree {
    int data;
    struct tree *left;
    struct tree *right;
};

struct tree *createnode(int value) {
    struct tree *n = (struct tree *)malloc(sizeof(struct tree));
    n->data = value;
    n->left = NULL;
    n->right = NULL;
    return n;  // Make sure to return the created node
}

void preorder(struct tree *root) {
    if (root != NULL) {
        printf("%d\t", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct tree *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t", root->data);
    }
}

void inorder(struct tree *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
}

void invertTree(struct tree *root) {
    if (root == NULL) {
        return;
    }
    
    // Swap the left and right children
    struct tree *temp = root->left;
    root->left = root->right;
    root->right = temp;
    
    // Recur for left and right subtrees
    invertTree(root->left);
    invertTree(root->right);
}

int main() {
    struct tree *p = createnode(10);
    struct tree *p1 = createnode(3);
    struct tree *p2 = createnode(13);
    struct tree *p3 = createnode(1);
    struct tree *p4 = createnode(5);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    printf("Preorder traversal of the original tree:\n");
    preorder(p);
    printf("\n");

    printf("Postorder traversal of the original tree:\n");
    postorder(p);
    printf("\n");

    printf("Inorder traversal of the original tree:\n");
    inorder(p);
    printf("\n");

    // Invert the binary tree
    invertTree(p);

    printf("\nPreorder traversal of the inverted tree:\n");
    preorder(p);
    printf("\n");

    printf("Postorder traversal of the inverted tree:\n");
    postorder(p);
    printf("\n");

    printf("Inorder traversal of the inverted tree:\n");
    inorder(p);
    printf("\n");

    return 0;
}
