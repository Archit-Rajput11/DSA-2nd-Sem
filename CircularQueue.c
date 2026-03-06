#include<stdio.h>
#define MAX 100
int queue[MAX],front = -1, rear = -1;
int isFull(){
    return (rear + 1) % MAX == front;
}
int isEmpty(){
    return front == -1;
}
void enqueue(int data){
    if(isFull()){
        printf("Queue Overflow!!!\n");
        return;
    }
    if(isEmpty())
        front =rear =0;
    else if(rear == MAX -1 && front != 0)
        rear = 0;
    else
        rear = (rear +1 ) % MAX;
    queue[rear] = data;
    printf("%d inserted in circular queue!!!\n",data);
}
int dequeue(){
    if(isEmpty()){
        printf("Queue Underflow!!!\n");
        return -1;
    }
    int val = queue[front];
    if(front == rear)
        front = rear = -1;
    else if(front == MAX-1)
        front = 0;
    else
        front++;
    return val;
}
int peek(){
    if(isEmpty()){
        printf("Queue Underflow!!!\n");
        return -1;
    }
    return queue[front];
}
int display(){
    int i;

    if(isEmpty()){
        printf("Queue is Empty!!!\n");
        return -1;
    }
    printf("Circular Queue Elements: ");
    if(front <= rear){
        for(i = front; i <= rear; i++)
            printf("%d ", queue[i]);
    }
    else{
        for(i = front; i < MAX; i++)
            printf("%d ", queue[i]);
        for(i = 0; i <= rear; i++)
            printf("%d ", queue[i]);
    }

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
                    printf("%d dequeue from the circular queue!!!\n", value);
                break;
            case 3:
                value = peek();
                if(value != -1)
                    printf("%d peek from the circular queue!!!\n", value);
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
