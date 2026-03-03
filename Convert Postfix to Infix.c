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
char* convertPostfixToInfix(char* postfixExp){
    int len = strlen(postfixExp), top = -1;
    char stack[100][100];
    for(int i=0; i<len;i++){
        char ch = postfixExp[i];
        if(isalnum(ch)){
            char str[] = {ch,'\0'};
            strcpy(stack[++top],str);
        }
        else if(ch =='+' || ch =='-' || ch =='*' || ch =='/' || ch =='^' ){
            char *s1 = stack[top--];
            char *s2 = stack[top--];
            char s3[100] = "" ;
            sprintf(s3, "(%s%c%s)",s2,ch,s1);
            strcpy(stack[++top],s3);
        }
    }
    char *infix = (char*) malloc(strlen(stack[top])+1);
    strcpy(infix, stack[top--]);
    return infix;
}
int main(){
    char expr[100];
    gets(expr);
    printf("%s",convertPostfixToInfix(expr));
    return 0;
}
