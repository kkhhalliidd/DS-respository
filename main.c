#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node*left;
    struct Node*right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return newNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

void inorder(struct Node*root){
    if (root!=NULL){
        inorder(root -> left);
        printf("%d ", root -> data);
        inorder(root -> right);
    }
}

void postorder(struct Node*root){
    if (root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root -> data);
        }
}

void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, data;

    root = insert(root, 50);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 20);

    while (1) {
        printf("\nMenu:\n");
        printf("1. In-order Traversal\n");
        printf("2. Pre-order Traversal\n");
        printf("3. Post-order Traversal\n");
        printf("4. Display Tree (In-order)\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("In-order Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 2:
                printf("Pre-order Traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 3:
                printf("Post-order Traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 4:
                printf("In-order Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
