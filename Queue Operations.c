#include<stdio.h>
#define MAX 100
int queue[MAX], front = -1, rear = -1;
int isFull(){
    return rear == MAX-1;
}
int isEmpty(){
    return front == -1;
}
void Enqueue(int data){
    if(isFull()){
        printf("Queue Overflow!!!\n");
        return;
    }
    queue[++rear] = data;

    if(front == -1)
        front = rear;

    printf("%d inserted in queue\n", data);
}
int dequeue(){
    if(isEmpty()){
        printf("Queue Underflow!!!\n");
        return -1;
    }
    int val = queue[front++];
    if(front > rear)
        front = rear = -1;

    return val;
}
int peek(){
    if(isEmpty()){
        printf("Queue is empty!!!\n");
        return -1;
    }

    return queue[front];
}
void display(){
    if(isEmpty()){
        printf("Queue is empty!!!\n");
        return;
    }
    printf("Queue elements: ");
    for(int i = front; i <= rear; i++){
        printf("%d ", queue[i]);
    }
    printf("\n");
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
