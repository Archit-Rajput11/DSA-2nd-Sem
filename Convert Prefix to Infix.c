#include <stdio.h> 
#include <string.h> 
#include <math.h> 
#include <ctype.h>  
#include <stdlib.h>
int precedence(char op){ 
    switch(op){ 
        case '+': 
        case '-': 
            return 1; 
        case '*': 
        case '/': 
            return 2; 
        case '^': 
            return 3; 
        default: 
        return 0;
    }
} 
char* convertPrefixToInfix(char* prefixExp) {
    int len = strlen(prefixExp), top = -1;
    char stack[100][100];
    for (int i = len - 1; i >= 0; i--) {
        char ch = prefixExp[i];
        if (isalnum(ch)) {
            char str[2];
            str[0] = ch;
            str[1] = '\0';
            strcpy(stack[++top], str);
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
            char s1[100], s2[100];
            strcpy(s1, stack[top--]);
            strcpy(s2, stack[top--]);
            char s3[100]="";
            sprintf(s3, "(%s%c%s)", s1, ch, s2);
            strcpy(stack[++top], s3);
        }
    }
    char* infix = (char*)malloc(strlen(stack[top]) + 1);
    strcpy(infix, stack[top]);
    return infix;
}
int main(){
    char expr[100];
    gets(expr);
    printf("%s",convertPrefixToInfix(expr));
    return 0;
}
