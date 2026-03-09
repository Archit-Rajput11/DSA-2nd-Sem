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
        return val;
    }
}
void peek(){
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
    
}
int main(){
    int choice, value;
    while(1){

    }
}
