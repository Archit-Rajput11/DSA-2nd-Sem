#include<stdio.h>
#define MAX 100
struct Queue{
    int data;
    int priority;
};
structQueue pqueue[MAX];
int front = -1, rear = -1;
int isEmpty(){
    return front == -1;
}
int isFull(){
    return front == rear;
}
void enqueue(int data, int priority){
    if(isFull()){
        printf("Queue Overflow!!!\n");
        return;
    }
    rear++;
    pqueue[rear].data = data;
    pqueue[rear].priority = priority;
    if(front == -1)
        front = rear;
    printf("Element inserted in priority queue!!!\n");
}
int getHighestPriority(){
    int max = pqueue[0].priority;
    for(int i=0; i<=rear; i++){
        if(pqueue[i].priority > max){
            max = pqueue[i].priority;
            index = i;
        }
    }
    return index;
}
int dequeue(){
    if(isEmpty()){
        printf("Queue Underflow!!!\n");
        return -1;
    }
    else if(front == rear){
        int val =pqueue[front].data;
        front = rear =-1;
        return val;
    }
    else{
        int index = getHighestPriority();
        int val = pqueue[index].data;
        for(int i = index; i<rear; i++){
            pqueue[i] = pqueue[i+1];
        }
        rear--;
        return val;
    }
}
int peek(){
    if(isEmpty()){
        printf("Queue Underflow!!!\n");
        return -1;
    }
    else{
        int index = getHighestPriority();
        int val = pqueue[index].data;
        return val;
    }
}
void display(){
    if(isEmpty()){
        printf("Queue is Empty!!!\n");
        return;
    }
    for(int i =0; i<= rear; i++){
        printf("Priority =>%d --> %d\n",pqueue[i].priority,pqueue[i].data);
    }
}
int main(){
    int choice, value, priority;
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
                printf("Enter Priority: ");
                scanf("%d",&priority);
                enqueue(value,priority);
                break;
            case 2:
                value = dequeue();
                if(value != -1)
                    printf("%d dequeue from the priority queue\n", value);
                break;
            case 3:
                value = peek();
                if(value != -1)
                    printf("Highest priority element is %d in queue\n", value);
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
    return 0;
}
