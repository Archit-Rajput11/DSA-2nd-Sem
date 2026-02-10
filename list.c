//Implement List Using Array.
#include<stdio.h>
#define MAX 100 
int list[MAX];
int n=0;
void insertInBeg(int value){
    if(n == MAX){
        printf("List is full !!!\n");
        return;
    }
    for(int i = n-1; i>=0; i--){
        list[i+1] = list[i];
    }
    list[0] = value;
    n++;
    printf("Element Inserted !!!\n");
}
void insertAtEnd(int value){
    if(n == MAX){
        printf("List is full !!!\n");
        return;
    }
    list[n++] = value;
    printf("Element Inserted !!!\n");
}
void insertAtPosition( int pos, int value){
    if(n == MAX){
        printf("List is full !!!\n");
    }
    else if(pos < 0 || pos >= n){
        printf("Position is invalid !!!\n");
    }
    else{
        for(int i = n-1; i>=pos; i--){
            list[i+1] = list[i];
        }
        list[pos] = value;
        n++;
        printf("Element Inserted !!!\n");
    }
}
void deleteFromBeginning(){
    if(n == 0){
        printf("List is empty !!!\n");
        return;
    }
    for(int i=0; i<n-1; i++){
        list[i] = list[i+1];
    }
    n--;
    printf("Element Deleted !!!\n");
}
void deleteFromEnd(){
    if(n == 0){
        printf("List is empty !!!\n");
        return;
    }
    n--;
    printf("Element is Deleted !!!\n");
}
void deleteFromGivenPos(int pos){
    if(n == 0){
        printf("List is empty !!!\n");
    }
    else if(pos < 0 || pos >= n) {
        printf("Invalid Position\n");
    }
    else{
        for( int i = pos; i < n-1 ; i++) {
            list[i] = list[i+1];
        }
        n--;
        printf("Element Deleted !!!\n"); 
    }
}

void displaylist(){
    if(n == 0){
        printf("List is empty !!!\n");
        return;
    }
    for(int i=0; i<n; i++){
        printf("%d\t", list[i]);
    }
    printf("\n");
}
int main(){
    while(1){
        printf("1. Insert In Beginning\n");
        printf("2. Insert At End\n");
        printf("3. Insert At Any Position\n");
        printf("4. Delete From Beginning\n");
        printf("5. Delete From End\n");
        printf("6. Delete From Given Posiion\n");
        printf("7. Display List\n");
        printf("8. Search Element In List\n");
        printf("9. Update Element In List\n");
        printf("10. Sort Elements of List \n");
        printf("11. Exit\n");
        int choice , data , pos;
        printf("Enter Choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter Data: ");
                scanf("%d",&data);
                insertInBeg(data);
                break;
            case 2:
                printf("Enter Data: ");
                scanf("%d",&data);
                insertAtEnd(data);
                break;
            case 3:
                printf("Enter Position: ");
                scanf("%d",&pos);
                printf("Enter Data: ");
                scanf("%d", &data);
                insertAtPosition(pos,data);
                break;
            case 4:
                deleteFromBeginning();
                break;
            case 5:
                deleteFromEnd();
                break;
            case 6:
                printf("Enter Position: ");
                scanf("%d",&pos);
                deleteFromGivenPos(pos);
                break;
            case 7:
                displaylist();
                break;
            case 8:
                break;
            case 9:
                break;
            case 10:
                break;
            case 11:
                break;
            default:
                printf("Invalid Choice !!!\n");
            
        }
    }
    return 0;
}
