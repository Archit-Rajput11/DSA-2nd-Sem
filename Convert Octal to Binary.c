//Program to convert Octal to Binary.
#include<stdio.h>
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
int convertdecimaltobinary(int decnum){
    int bin =0 , place=1;
    while(decnum !=0){
        int rem =decnum %2;
        bin += rem*place;
        place *= 10;
        decnum /=2;
    }
    return bin;
}
int main(){
    int num;
    printf("Enetr Octal Number: ");
    scanf("%d",&num);
    int binary = convertdecimaltobinary(convertoctaltodecimal(num));
    printf("Binary of Octal Number %d is %d",num,binary);
    return 0;
}
