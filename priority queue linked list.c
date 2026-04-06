#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    int priority;
    struct Node* next;
};
struct Node* front = NULL, *rear = NULL;
void Enqueue(int data,int priority){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL)
        printf("Queue Overflow\n");
    else{
        newNode->data = data;
        newNode->priority = priority;
        newNode->next = NULL;
        if(rear == NULL)
            rear = newNode;
        else{
            rear->next = newNode;
            rear = newNode;
        }
        if(front == NULL)
            front =rear;
        printf("Element added in queue\n");
    }
}
struct Node* getHighestPriority(){
    struct Node* curr = front->next , *prev = front, *temp = NULL;
    int max = 0;
    while(curr != NULL){
        if(curr->next->priority > max){
            max = curr->priority;
            temp = prev;

        }
        prev = curr;
        curr = curr->next;
    }
}
int dequeue(){
    if(front == NULL && rear == NULL)
        printf("Queue Underflow!!!\n");
    else if(front == rear){
        int val = front->data;
        front = rear = NULL;
        return val;
    }
    else{
        struct Node* temp = getHighestPriority();
        int val;
        if(temp == NULL){
            val = front->data;
            front = front->next;
        }
        else{
            val = temp->next->data;
            temp->next = temp->next->next;
        }
        return val;
    }
}
int peek(){
    if(front == NULL && rear == NULL){
        printf("Queen Underflow!!!\n");
        return -1;
    }
    else if(front == rear){
        return front->data;
    }
    else{
        struct Node* temp = getHighestPriority();
        int val;
        if(temp == NULL)
            val = front->data;
        else
            val = temp->next->data;
        return val;
    }
}
void display(){
    if(front == NULL && rear ==NULL)
        printf("Queue is empty!!!\n");
    else{
        struct Node* temp = front;
        while(temp != NULL){
            printf("Priority ! %d --> Value : %d\n",temp->priority,temp->data);
            temp = temp->next;
        }
    }
}
int main(){
    int choice , data , priority;
    while(1){
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter Choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter data: ");
                scanf("%d",&data);
                printf("Enter priority: ");
                scanf("%d",&priority);
                Enqueue(data,priority);
                break;
            case 2:
                data = dequeue();
                if(data != -1)
                    printf("Deleted element: %d\n", data);
                break;
            case 3:
                data = peek();
                if(data != -1)
                    printf("Front element: %d\n", data);
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid Choice\n");
        }
    }
}
