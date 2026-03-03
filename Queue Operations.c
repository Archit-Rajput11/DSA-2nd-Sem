#include<stdio.h>
#define MAX 100
int queue[MAX],front = -1, rear = -1;

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
    printf("\n%d inserted in queue\n",data);
}

int dequeue(){
    if(isFull()){
        printf("\nQueue Underflow!!1\n");
        return -1;
    }
    int val = queue[front++];
    if(front > rear)
        front = rear =- 1;
    return val;

}

int peek(){
    if(isFull()){
        printf("\nQueue is empty!!!\n");
        return -1;
    }
    return queue[front];
}

void display(){
    if(isFull()){
        printf("\nQueue is empty!!1\n");
        return -1;
    }
    for(int i = front;i <= rear;i++){
        printf("%d", queue[i]);
    }
    printf("\n");
}
int main(){
    int choice, value;
    while(1){
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
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
            default:
        }
    }
}
