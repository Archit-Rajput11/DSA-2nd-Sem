#include<stdio.h>
#include<stdlib.h>
struct Node{
    struct Node* prev;
    int data;
    struct Node* next;
};
struct Node* head = NULL;
struct Node* createNode(int data){
    struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=data;
    temp->prev=NULL;
    temp->next=NULL;
    return temp;
}
void insertInBeg(int data){
    struct Node* newNode=createNode(data);
    if(head==NULL){
        head=newNode;
        printf("Node inserted in beginning\n");
        return;
    }
    newNode->next=head;
    head->prev=newNode;
    head=newNode;
    printf("Node inserted in beginning\n");
}
void insertNodeAtEnd(int data){
    struct Node* newNode=createNode(data);
    if(head==NULL){
        head=newNode;
        printf("Node inserted at end\n");
        return;
    }
    struct Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->prev=temp;
    printf("Node inserted at end\n");
}
void insertAtAnyPos(int data, int pos){
    if(head == NULL)
        printf("List is empty !!!!\n");
    else if(pos == 1){
        insertInBeg(data);
    }
    else{
        struct Node* temp = head;
        int i = 0;
        while(temp != NULL){
            if(i == pos)
                break;
            temp = temp->next;
            i++;
        }
        if(temp == NULL)
            printf("Invalid position !!!!\n");
        else{
            struct Node* newNode = createNode(data);
            temp->next = newNode;
            newNode->prev = temp;
            printf("Node inserted at position %d\n", pos);
        }
    }    
}
void deleteFromBeg(){
    if(head == NULL)
        printf("List is empty !!!!\n");
    else{
        head = head->next;
        head->prev = NULL;
        printf("Node deleted from beginning\n");
    }

}
void deleteFromEnd(){
    if(head == NULL)
        printf("List is empty !!!!\n");
    else if(head->next == NULL){
        free(head);
        head = NULL;
        printf("Node deleted from end\n");
    }
    else{
        struct Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->prev->next = NULL;
        free(temp);
        printf("Node deleted from end\n");
    }     

}
void deleteFromAnyPos(int pos){
    if(head == NULL)
        printf("List is empty !!!!\n");
    else if(pos == 0){
        deleteFromBeg();
    }
    else{
        struct Node* temp = head;
        int i = 0;
        while(temp != NULL){
            if(i == pos)
                break;
            temp = temp->next;
            i++;
        }
        if (temp == NULL)
            printf("Invalid position !!!!\n");
        else{
            temp->prev->next = temp->next;
            if(temp->next != NULL)
                temp->next->prev = temp->prev;
            free(temp);
            printf("Node deleted from position %d\n", pos);
        }
    }    


}
void displayList(){
    if(head == NULL)
        printf("List is empty !!!!\n");
    else{
        struct Node* temp = head;
        printf("List elements are: ");
        while(temp != NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
void search(int data){
    if(head == NULL)
        printf("List is empty !!!!\n");
    else{
        struct Node* temp = head;
        int pos = 1;
        while(temp != NULL){
            if(temp->data == data){
                printf("Element found at position %d\n", pos);
                return;
            }
            temp = temp->next;
            pos++;
        }
        printf("Element not found in the list\n");
    }
}
    
int main(){
    while(1){
        int choice , data , pos;
        printf("\n*****Doubly Linked List Menu*****\n");
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
