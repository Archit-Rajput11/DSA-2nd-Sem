#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node *head = NULL;
struct Node* createNode(int data){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data =data;
    temp->next = NULL;
    return temp;
}
void insertInBeg(int data){
    struct Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
    printf("Node insertes in Beginning!!!\n");
}
void insertNodeAtEnd(int data){
    struct Node* newNode = createNode(data);
    if(head == NULL)
        head = newNode;
    else{
        struct Node* temp= head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next= newNode;
    }
    printf("Node Inserted In End!!!\n");
}
void insertAtAnyPos(int data, int pos){
    if(head == NULL)
        printf("List is empty!!!\n");
    else if(pos ==0)
        insertInBeg(data);
    else{
        struct Node* temp =head;
        int i=0;
        while(temp!=NULL){
            if(i == pos-1)
                break;
            temp = temp->next;
        }
        
    }
}
int main(){
    while(1){
            int choice , data , pos;
        printf("\n*****Singly Linked List Menu*****\n");
        printf("1. Insert In Beginning\n");
        printf("2. Insert At End\n");
        printf("3. Insert At Any Position\n");
        printf("4. Delete From Beginning\n");
        printf("5. Delete From End\n");
        printf("6. Delete From Given Posiion\n");
        printf("7. Display List\n");
        printf("8. Search Element In List\n");
        printf("9. Exit\n");
        printf("Enter Choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                exit(0);
                break;
            default:
                printf("Invalid Choice !!!\n");
        }
        printf("\n\n");
    }
    return 0;
}
