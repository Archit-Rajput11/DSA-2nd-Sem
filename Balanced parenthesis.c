#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
int operand[100];
char operator[100];
int top1 = -1, top2 = -1;
void doProcess(){
    int x = operand[top1--];
    int y = operand[top1--];
    char op = operator[top2--];
    int z;
    switch(op){
        case '+':
            z = y + x;
            break;
        case '-':
            z = y - x;
            break;
        case '*':
            z = y * x;
            break;
        case '/':
            z = y / x;
            break;
        case '^':
            z = (int)round(pow(y, x));
            break;
    }
    operand[++top1] = z;
}
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
int evalInfixExpression(char *exp){
    top1 = -1;
    top2 = -1;

    for(int i = 0; i < strlen(exp); i++){
        char ch = exp[i];

        if(isdigit(ch)){
            int num = 0;
            while(isdigit(exp[i])){
                num = num * 10 + exp[i] - '0';
                i++;
            }
            i--;
            operand[++top1] = num;
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
        else if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^'){
            while(top2 != -1 && precedence(ch) <= precedence(operator[top2])){
                doProcess();
            }
            operator[++top2] = ch;
        }
    }
    while(top2 != -1){
        doProcess();
    }
    return operand[top1];
}
int evalPostfixExpression(char* exp){
    top1 = -1;
    for(int i = 0; i < strlen(exp); i++){
        if(isdigit(exp[i])){
            int num = 0;
            while(isdigit(exp[i])){
                num = num * 10 + exp[i] - '0';
                i++;
            }
            i--;
            operand[++top1] = num;
        }
        else if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' || exp[i] == '^'){
            int x = operand[top1--];
            int y = operand[top1--];
            int z;
            switch(exp[i]){
                case '+':
                    z = y + x;
                    break;
                case '-':
                    z = y - x;
                    break;
                case '*':
                    z = y * x;
                    break;
                case '/':
                    z = y / x;
                    break;
                case '^':
                    z = (int)round(pow(y, x));
                    break;
            }

            operand[++top1] = z;
        }
    }
    return operand[top1];
}
int main(){
    char expr[100];
    int result;
    printf("Enter Infix Expression: ");
    fgets(expr, sizeof(expr), stdin);
    expr[strcspn(expr, "\n")] = 0;  

    result = evalInfixExpression(expr);
    printf("Result of Infix expression %s = %d\n", expr, result);

    printf("Enter Postfix Expression: ");
    fgets(expr, sizeof(expr), stdin);
    expr[strcspn(expr, "\n")] = 0;

    result = evalPostfixExpression(expr);
    printf("Result of Postfix expression %s = %d\n", expr, result);

    return 0;
}
