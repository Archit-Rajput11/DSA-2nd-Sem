#include <stdio.h>
#include <string.h>
int main() {
    char str[100];
    printf("Enter Expression: ");
    fgets(str, sizeof(str), stdin);
    int len = strlen(str);
    int top = -1, flag = 0;
    char stack[100];
    for(int i = 0; i < len; i++) {
        char ch = str[i];
        if(ch == '(' || ch == '[' || ch == '{') {
            stack[++top] = ch;
        }
        else if(ch == ')' || ch == ']' || ch == '}') {
            if(top == -1) { 
                flag = 1;
                break;
            }
            if((ch == ')' && stack[top] == '(') ||
               (ch == ']' && stack[top] == '[') ||
               (ch == '}' && stack[top] == '{')) {
                top--; 
            }
            else {
                flag = 1;
                break;
            }
        }
    }
    if(flag == 0 && top == -1)
        printf("Balanced.\n");
    else
        printf("Not Balanced.\n");

    return 0;
}
