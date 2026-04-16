#include<stdio.h>
#include<stdlib.h>
struct Node{
    struct Node* left;
    int data;
    struct Node* right;
};
struct Node* createNode(int data){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
struct Node* insert(struct Node* root, int data){
    if(root == NULL)
        return createNode(data);
    else{
        struct Node* queue[100];
        int front =-1, rear =-1;
        queue[++rear] = root;
        front++;
        while(front <=rear){
            struct Node* temp = queue[front++];
            if(temp->left == NULL){
                temp->left = createNode(data);
                break;
            }
            else if(temp->right == NULL){
                temp->right = createNode(data);
                break;
            }
            else{
                queue[++rear] = temp->left;
                queue[++rear] = temp->right;
            }
        }
        return root;
    }
}
void preOrder(struct Node* root){
    if(root == NULL)
        return;
    printf("%d ",root->data);
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(struct Node* root){
    if(root == NULL)
        return;
    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);
}
void postOrder(struct Node* root){
    if(root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ",root->data);
}
int main(){
    int choice,value;
    initTree();
    while(1){
        printf("\n*****Binary Tree Menu*****\n");
        printf("1. Insert\n");
        printf("2. Pre-Order Traversal\n");
        printf("3. In-Order Traversal\n");
        printf("4. Post-Order Traversal\n");
        printf("5. Exit\n");
        printf("Enter Choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter value: ");
                scanf("%d",&value);
                insert(value);
                break;
            case 2:
                preOrder(0);
                break;
            case 3:
                inOrder(0);
                break;
            case 4:
                postOrder(0);
                break;
            case 5:
                exit(0);
            default:
                printf("invalid Choice!!!\n");
        }
    }
    return 0;
}
