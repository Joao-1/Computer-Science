// ! Binary Search Tree

#include <stdio.h>

struct Tree {};

struct Node{
    int value;
    struct Node *Parent;
    struct Node *left;
    struct Node *right;
};

void InorderTreeWalk(struct Node *node) {
    if (node != NULL) {
        InorderTreeWalk(node->left);
        printf("%d\n", node->value);
        InorderTreeWalk(node->right);
    }
}

struct Node *Search(struct Node *root, int value) {
    if (root == NULL || value == root->value) {
        return root;
    }
    if (value < root->value) {
        return Search(root->left, value);
    } else {
        return Search(root->right, value);
    }
}

struct Node *InterativeTreeSearch(struct Node *root, int value) {
    while (root != NULL && value != root->value) {
        if (value < root->value) {
            root = root->left;
        } else {
            root = root->right;
        }
    }

    return root;
}

struct Node *Minimum(struct Node *root) {
    while (root->left != NULL) {
        root = root->left;
    }

    return root;
}

struct Node *Maximum(struct Node *root) {
    while (root->right != NULL) {
        root = root->right;
    }

    return root;
}

int main() {
    struct Node node1;
    struct Node node2;
    struct Node node3;
    struct Node node4;
    struct Node node5;
    struct Node node6;

    node1.value = 6;
    node1.Parent = NULL;
    node1.left  = &node2;
    node1.right = &node3;

    node2.value = 5;
    node2.Parent = &node1;
    node2.left  = &node4;
    node2.right = &node5;

    node4.value = 2;
    node4.Parent = &node2;
    node4.left  = NULL;
    node4.right = NULL;

    node5.value = 5;
    node5.Parent = &node2;
    node5.left  = NULL;
    node5.right = NULL;

    node3.value = 7;
    node3.Parent = &node1;
    node3.left  = NULL;
    node3.right = &node6;

    node6.value = 8;
    node6.Parent = &node3;
    node6.left  = NULL;
    node6.right = NULL;

    InorderTreeWalk(&node1);

    struct Node *searchedNode = Search(&node1, 5);
    printf("Searched node: %d\n", searchedNode->value);

    struct Node *interativeSearchedNode = InterativeTreeSearch(&node1, 5);
    printf("Interative searched node: %d\n", interativeSearchedNode->value);

    struct Node *minimumNode = Minimum(&node1);
    printf("Minimum node: %d\n", minimumNode->value);

    struct Node *maximumNode = Maximum(&node1);
    printf("Maximum node: %d\n", maximumNode->value);   
}