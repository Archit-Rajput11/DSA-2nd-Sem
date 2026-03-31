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
    if(head == NULL){
        head = newNode;
        newNode->next = head;
    }
    else{
        struct Node* temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }
    printf("Node inserted in beginning!!!\n");
}
void insertNodeAtEnd(int data){
    
}
void insertAtAnyPos(int data, int pos){
    
}
void deleteFromBeg(){
    
}
void deleteFromEnd(){
    
}
void deleteFromAnyPos(int pos){
    
}
void displayList(){
    if(head == NULL)
        printf("List is Empty!!!\n");
    else{
        struct Node* temp = head;
        do{
            printf("%d ",temp->data);
            temp = temp->next;
        }while(temp != head);
        printf("\n");
    }
}
void search(int data){
    
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
                printf("Enter Data: ");
                scanf("%d",&data);
                insertInBeg(data);
                break;
            case 2:
                printf("Enter Data: ");
                scanf("%d",&data);
                insertNodeAtEnd(data);
                break;
            case 3:
                printf("Enter Position: ");
                scanf("%d",&pos);
                printf("Enter Data: ");
                scanf("%d",&data);
                insertAtAnyPos(data,pos);
                break;
            case 4:
                deleteFromBeg();
                break;
            case 5:
                deleteFromEnd();
                break;
            case 6:
                printf("Enter Position: ");
                scanf("%d",&pos);
                deleteFromAnyPos(pos);
                break;
            case 7:
                displayList();
                break;
            case 8:
                printf("Enter data to search: ");
                scanf("%d",&data);
                search(data);
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
