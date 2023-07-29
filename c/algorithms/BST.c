

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct BST {
    int data;
    struct BST* left;
    struct BST* right;
};

struct BST *CreateNode() {
    struct BST* new = (struct BST*) malloc(sizeof(struct BST));
    new->left = NULL;
    new->right = NULL;
    return new; 
};

void Insert(struct BST** RootPtr, int value) {
    struct BST* temp = *RootPtr;
    if (temp == NULL) { /*When list is empty*/
        struct BST* NewNode = CreateNode();
        NewNode->data = value;
        *RootPtr = NewNode;
    } else if (value <= temp->data) { /*If user value is less then current node value insert in left of the node...*/
        struct BST* NewNode = CreateNode();
        NewNode->data = value;
        temp->left = NewNode;
    } else { /*If user value is greater then current node value insert at right of the node*/
        struct BST* NewNode = CreateNode();
        NewNode->data = value;
        temp->right = NewNode;
    }
}

int Search(struct BST* RootPtr, int item) { /*Implemented search using recursion*/
    if(RootPtr == NULL) {
        return 0; /*Returns 0 if list is empty*/
    } else if(item == RootPtr->data) {
        return 1; /*Returns 1 when element found*/
    } else if(item < RootPtr->data) {
        Search(RootPtr->left, item); /*Otherwise search in left side of binary tree if searching value is less then the current node value*/
    } else {
        Search(RootPtr->right, item); /*Otherwise search in right side of binary tree if searching value is greater then the current node value*/
    }
}

void main() {
    struct BST* RootPtr = NULL;
    int item, cont, key;
    do {
        printf("Enter item: ");
        scanf("%d",&item);
        Insert(&RootPtr, item);

        printf("\n1 to keep inserting/ 0 to Exit: ");
        scanf("%d",&cont);
    } while(cont == 1);

    printf("\nEnter element to search: ");
    scanf("%d",&key);

    if(Search(RootPtr, key) == 0) {
        printf("\nFound\n");
    } else {
        printf("\nNot Found\n");
    }
}

// Unit Test Cases
void test_CreateNode() {
    struct BST* node = CreateNode();
    assert(node != NULL);
    assert(node->left == NULL);
    assert(node->right == NULL);
}

void test_Insert() {
    struct BST* root = NULL;
    Insert(&root, 10);
    assert(root != NULL);
    assert(root->data == 10);
    assert(root->left == NULL);
    assert(root->right == NULL);
}

void test_Search() {
    struct BST* root = NULL;
    Insert(&root, 10);
    Insert(&root, 5);
    Insert(&root, 15);
    Insert(&root, 3);
    Insert(&root, 7);
    Insert(&root, 12);
    Insert(&root, 17);
    assert(Search(root, 10) == 1);
    assert(Search(root, 5) == 1);
    assert(Search(root, 15) == 1);
    assert(Search(root, 3) == 1);
    assert(Search(root, 7) == 1);
    assert(Search(root, 12) == 1);
    assert(Search(root, 17) == 1);
    assert(Search(root, 20) == 0);
}

int main() {
    test_CreateNode();
    test_Insert();
    test_Search();
    return 0;
}