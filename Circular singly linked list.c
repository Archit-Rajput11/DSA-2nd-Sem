#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node *head = NULL;
struct Node* createNode(int data){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
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
    }
    printf("Node inserted at end!!!\n");
}
void insertAtAnyPos(int data, int pos){
    if(head == NULL){
        printf("List is empty!!!\n");
        return;
    }
    if(pos == 0){
        insertInBeg(data);
        return;
    }
    struct Node* temp = head;
    int i = 0;
    while(i < pos - 1 && temp->next != head){
        temp = temp->next;
        i++;
    }
    if(i != pos - 1){
        printf("Invalid Position!!!\n");
        return;
    }
    struct Node* newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
    printf("Node inserted at position %d successfully!!!\n", pos);
}
void deleteFromBeg(){
    if(head == NULL){
        printf("List is empty!!!\n");
    }
    else if(head->next == head){
        free(head);
        head = NULL;
    }
    else{
        struct Node* temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        struct Node* del = head;
        temp->next = head->next;
        head = head->next;
        free(del);
    }
    printf("Node deleted from beginning!!!\n");
}
void deleteFromEnd(){
    if(head == NULL){
        printf("List is empty!!!\n");
    }
    else if(head->next == head){
        free(head);
        head = NULL;
    }
    else{
        struct Node* temp = head;
        while(temp->next->next != head){
            temp = temp->next;
        }
        struct Node* del = temp->next;
        temp->next = head;
        free(del);
    }
    printf("Node deleted from End!!!\n");
}
void deleteFromAnyPos(int pos){
    if(head == NULL){
        printf("List is Empty!!!\n");
        return;
    }
    if(pos == 0){
        deleteFromBeg();
        return;
    }
    struct Node* temp = head;
    int i = 0;
    while(i < pos - 1 && temp->next != head){
        temp = temp->next;
        i++;
    }
    if(temp->next == head || i != pos - 1){
        printf("Invalid Position!!!\n");
        return;
    }
    struct Node* del = temp->next;
    temp->next = del->next;
    free(del);

    printf("Node deleted from position %d successfully!!!\n", pos);
}
void displayList(){
    if(head == NULL){
        printf("List is Empty!!!\n");
    }
    else{
        struct Node* temp = head;
        do{
            printf("%d ", temp->data);
            temp = temp->next;
        }while(temp != head);
        printf("\n");
    }
}
void search(int data){
    if(head == NULL){
        printf("List is Empty!!!\n");
        return;
    }
    struct Node* temp = head;
    int pos = 1;
    int found = 0;
    do{
        if(temp->data == data){
            printf("Element found at position %d\n", pos);
            found = 1;
            break;
        }
        temp = temp->next;
        pos++;
    }while(temp != head);
    if(!found){
        printf("Element not found in the list\n");
    }
}
int main(){
    while(1){
        int choice, data, pos;
        printf("\n*****Circular Singly Linked List Menu*****\n");
        printf("1. Insert In Beginning\n");
        printf("2. Insert At End\n");
        printf("3. Insert At Any Position\n");
        printf("4. Delete From Beginning\n");
        printf("5. Delete From End\n");
        printf("6. Delete From Given Position\n");
        printf("7. Display List\n");
        printf("8. Search Element In List\n");
        printf("9. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                scanf("%d", &data);
                insertInBeg(data);
                break;
            case 2:
                scanf("%d", &data);
                insertNodeAtEnd(data);
                break;
            case 3:
                scanf("%d %d", &pos, &data);
                insertAtAnyPos(data, pos);
                break;
            case 4:
                deleteFromBeg();
                break;
            case 5:
                deleteFromEnd();
                break;
            case 6:
                scanf("%d", &pos);
                deleteFromAnyPos(pos);
                break;
            case 7:
                displayList();
                break;
            case 8:
                scanf("%d", &data);
                search(data);
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid Choice !!!\n");
        }
    }
}
