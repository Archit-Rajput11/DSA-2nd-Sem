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
    } else {
        struct Node* temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }
}
void insertAtEnd(int data){
    struct Node* newNode = createNode(data);

    if(head == NULL){
        head = newNode;
        newNode->next = head;
    } else {
        struct Node* temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}
void insertAtPos(int data, int pos){
    if(pos == 1){
        insertInBeg(data);
        return;
    }
    struct Node* temp = head;
    int i = 1;
    while(i < pos-1 && temp->next != head){
        temp = temp->next;
        i++;
    }
    struct Node* newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
}
void deleteFromBeg(){
    if(head == NULL) return;

    if(head->next == head){
        free(head);
        head = NULL;
    } else {
        struct Node* temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        struct Node* del = head;
        temp->next = head->next;
        head = head->next;
        free(del);
    }
}
void deleteFromEnd(){
    if(head == NULL) return;

    if(head->next == head){
        free(head);
        head = NULL;
    } else {
        struct Node* temp = head;
        while(temp->next->next != head){
            temp = temp->next;
        }
        struct Node* del = temp->next;
        temp->next = head;
        free(del);
    }
}
void deleteByValue(int x){
    if(head == NULL) return;
    struct Node *temp = head, *prev = NULL;
    if(head->data == x){
        deleteFromBeg();
        return;
    }

    do{
        prev = temp;
        temp = temp->next;

        if(temp->data == x){
            prev->next = temp->next;
            free(temp);
            return;
        }
    }while(temp != head);
}
void search(int x){
    if(head == NULL){
        printf("-1\n");
        return;
    }
    struct Node* temp = head;
    int pos = 1;
    do{
        if(temp->data == x){
            printf("%d\n", pos);
            return;
        }
        temp = temp->next;
        pos++;
    }while(temp != head);

    printf("-1\n");
}
void display(){
    if(head == NULL){
        printf("EMPTY\n");
        return;
    }
    struct Node* temp = head;
    do{
        printf("%d ", temp->data);
        temp = temp->next;
    }while(temp != head);
    printf("\n");
}
void countNodes(){
    if(head == NULL){
        printf("0\n");
        return;
    }
    int count = 0;
    struct Node* temp = head;
    do{
        count++;
        temp = temp->next;
    }while(temp != head);
    printf("%d\n", count);
}
int main(){
    int Q;
    scanf("%d", &Q);
    while(Q--){
        int code;
        scanf("%d", &code);

        if(code == 1){
            int x; scanf("%d",&x);
            insertAtEnd(x);
        }
        else if(code == 2){
            int x; scanf("%d",&x);
            insertInBeg(x);
        }
        else if(code == 3){
            int x,p;
            scanf("%d %d",&x,&p);
            insertAtPos(x,p);
        }
        else if(code == 4){
            int x; scanf("%d",&x);
            deleteByValue(x);
        }
        else if(code == 5){
            deleteFromBeg();
        }
        else if(code == 6){
            deleteFromEnd();
        }
        else if(code == 7){
            int x; scanf("%d",&x);
            search(x);
        }
        else if(code == 8){
            display();
        }
        else if(code == 9){
            countNodes();
        }
    }
    return 0;
}
