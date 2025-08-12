#include <stdio.h>
#include <stdlib.h>

struct AVLNode {
    int data;
    struct AVLNode *left;
    struct AVLNode *right;
    int height;
};

struct AVLNode *root = NULL;

int height(struct AVLNode *N) {
    return (N == NULL) ? 0 : N->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

struct AVLNode *newNode(int key) {
    struct AVLNode *node = (struct AVLNode *)malloc(sizeof(struct AVLNode));
    node->data = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

struct AVLNode *rightRotate(struct AVLNode *y) {
    struct AVLNode *x = y->left;
    struct AVLNode *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

struct AVLNode *leftRotate(struct AVLNode *x) {
    struct AVLNode *y = x->right;
    struct AVLNode *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int getBalance(struct AVLNode *N) {
    return (N == NULL) ? 0 : height(N->left) - height(N->right);
}

struct AVLNode *insert(struct AVLNode *node, int key) {
    if (node == NULL)
        return newNode(key);

    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->data)
        return rightRotate(node);

    if (balance < -1 && key > node->right->data)
        return leftRotate(node);

    if (balance > 1 && key > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

struct AVLNode *minValueNode(struct AVLNode *node) {
    struct AVLNode *current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

struct AVLNode *deleteNode(struct AVLNode *node, int key) {
    if (node == NULL)
        return node;

    if (key < node->data)
        node->left = deleteNode(node->left, key);
    else if (key > node->data)
        node->right = deleteNode(node->right, key);
    else {
        if ((node->left == NULL) || (node->right == NULL)) {
            struct AVLNode *temp = node->left ? node->left : node->right;

            if (temp == NULL) {
                free(node);
                return NULL;
            } else {
                struct AVLNode *toFree = node;
                node = temp;
                free(toFree);
            }
        } else {
            struct AVLNode *temp = minValueNode(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
    }

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && getBalance(node->left) >= 0)
        return rightRotate(node);

    if (balance > 1 && getBalance(node->left) < 0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && getBalance(node->right) <= 0)
        return leftRotate(node);

    if (balance < -1 && getBalance(node->right) > 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void inorder(struct AVLNode *node) {
    if (node != NULL) {
        inorder(node->left);
        printf("%d ", node->data);
        inorder(node->right);
    }
}

int countNodes(struct AVLNode *node) {
    return (node == NULL) ? 0 : 1 + countNodes(node->left) + countNodes(node->right);
}

void search(struct AVLNode *node, int key) {
    if (node == NULL) {
        printf("Element not found.\n");
        return;
    }
    if (key < node->data)
        search(node->left, key);
    else if (key > node->data)
        search(node->right, key);
    else
        printf("Element found: %d\n", node->data);
}

int main() {
    int choice, data;
    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Display (Inorder)\n4. Search\n5. Count Nodes\n6. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                break;
            case 3:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 4:
                printf("Enter data to search: ");
                scanf("%d", &data);
                search(root, data);
                break;
            case 5:
                printf("Total nodes: %d\n", countNodes(root));
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
