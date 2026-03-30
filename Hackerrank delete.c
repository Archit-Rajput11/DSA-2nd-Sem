#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* head = NULL;
struct Node* createNode(int data){
    struct Node* temp =(struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}
void insertEnd(int data){
    struct Node* newNode = createNode(data);
    if(head == NULL){
        head = newNode;
    }
    else{
        struct Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void display(){
    if(head==NULL)
        printf("EMPTY");
    else{
        struct Node* temp = head;
        while(temp != NULL){
            printf("%d ",temp->data);
            temp = temp->next;
        }
    }
}
int main() {
    int n,val;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&val);
        insertEnd(val);
    }
    if(n==1)
        head = NULL;
    else{
        int mid =n/2;
        struct Node* temp = head;
        int i=0;
        while(temp != NULL){
            if(i == mid-1)
                break;
            temp = temp ->next;
            i++;
        }
        temp->next = temp->next->next;
    }
    display();
    return 0;
}
