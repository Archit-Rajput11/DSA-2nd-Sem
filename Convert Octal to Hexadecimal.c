//Program to convert Octal to Hexa-Decimal.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int convertoctaltodecimal(int octalnum){
int decnum = 0, base =1;
    while(octalnum != 0){
        int rem = octalnum % 10;
        decnum += rem * base;
        base *= 8;
        octalnum /=10;
    }
    return decnum;
}
char* convertdecimaltohexadecimal(int decnum ){
    int n;
    char *hexa = (char*)calloc(100,1);
    while(decnum!=0){
        int rem = decnum%16;
        char str[2];
        if(rem>=0 && rem<=9)
            sprintf(str,"%d",rem);
        else if(rem==10)
            str[0]='A';
        else if(rem==11)
            str[0]='B';
        else if(rem==12)
            str[0]='C';
        else if(rem==13)
            str[0]='D';
        else if(rem==14)
            str[0]='E';
        else if(rem==15)
            str[0]='F';
        else
            str[0]='F';
        str[1]= '\0';
        strcat(hexa,str);
        decnum =decnum/16;
    }
    strrev(hexa);
    return hexa;
}
int main(){
    int num;
    printf("Enter Octal Number: ");
    scanf("%d",&num);
    char *hex =convertdecimaltohexadecimal(convertoctaltodecimal(num));
    printf("Hexa-Decimal of Octal %d is %s",num,hex);
    return 0;
}

