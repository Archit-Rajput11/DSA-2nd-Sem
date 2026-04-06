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
        else
            rear->next = newNode;
        if(front == NULL)
            front =rear;
        printf("Element added in queue\n");
    }
}
int dequeue(){
    
}
int peek(){

}
void display(){

}
int main(){
    int choice, value;
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
                printf("Enter value: ");
                scanf("%d",&value);
                Enqueue(value);
                break;
            case 2:
                value = dequeue();
                if(value != -1)
                    printf("Deleted element: %d\n", value);
                break;
            case 3:
                value = peek();
                if(value != -1)
                    printf("Front element: %d\n", value);
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
