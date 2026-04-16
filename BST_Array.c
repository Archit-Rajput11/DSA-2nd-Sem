#include<stdio.h>
#include<stdlib.h>
#define max 100
int tree[max],idx=0;
void initTree(){
    for(int i =0; i<max; i++){
        tree[i] =-1;
    }
}
void insert(int val){
    
}
void preOrder(int index){
    if(index >= max || tree[index] == -1)
        return;
    printf("%d ",tree[index]);
    preOrder(2*index+1);
    preOrder(2*index+2);
}
void postOrder(int index){
    if(index >= max || tree[index] == -1)
        return;
    postOrder(2*index+1);
    postOrder(2*index+2);
    printf("%d ",tree[index]);
}
void inOrder(int index){
    if(index >= max || tree[index] == -1)
        return;
    inOrder(2*index+1);
    printf("%d ",tree[index]);
    inOrder(2*index+2);
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
