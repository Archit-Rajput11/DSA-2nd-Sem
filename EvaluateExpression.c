#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
int operand[100];
char operator[100];
int top1 = -1, top2 = -1;

void doProcess(){
    int x = operand[top1--];
    int y = operand[top2--];
    char op = operator[top2--];
    int z;
    switch(op){
        case '+':
            z= y + x;
            break;
        case '-':
            z= y - x;
            break;
        case '*':
            z= y * x;
            break;
        case '/':
            z = y / x;
            break;
        case '^':
            z = (int)pow(y,x);
            break;
    }
    operand[++top1] -z;
}

int precedance(char op){
    switch (op)
    {
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

int evalInfixExpression(char *exp){
    for(int i = 0; i<strlen(exp); i++){
        char ch = exp[i];
        if(isdigit(ch)){
            int num = 0, x = 1;
            while(isdigit(exp[i])){
                num = num *10 + exp[i]-'0';
                i++;
            }
            i--;
            operand[++top1] = num;
        }
        else if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' ){
            if(top2 == -1)
                operator[++top2] = ch;
            else{
                while(top2 != -1 && precedance(ch) <= precedance(operator[top2])){
                    doProcess();
                }
                operator[++top2] = ch;
            }
        }
        else if(ch == '('){
            operator[++top2] = ch;
        }
        else if(ch == ')'){
            while(operator[top2] != '('){
                doProcess();
            }
            top2--;
        }
    }
    while(top2 != -1){
        doProcess();
    }
    return operand[top1--];
}

int main(){
    char exp[100];
    printf("Enter Expression: ");
    gets(exp);
    int result = evalInfixExpression(exp);
    printf("Result of expression %s = %d\n",exp,result);
    return 0;
}
