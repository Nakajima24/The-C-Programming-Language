//
//  main.c
//  Chapter 2. Types, Operators, and Expressions
//
//  Created by Brian Chen on 21/10/2023.
//
//Exercise 2-3. Write the function htoi(s), which converts a string of hexadecimal digits (including an optional Ox or ox) into its equivalent integer value. The allowable digits are 0 through 9, a through f, and A through F.
#include <stdio.h>
#include <math.h>
#define size 100

void htoi(char s[], int length);

int main(void){
    int a, i= 0, length = 0;
    char hex[size] = {0};
    printf("enter arbitrary hexadecimal value:\n");
    while((a = getchar()) != '\n'){
        //check the value is eligible
        ++length;
        if((a>='0'&&a<='9')||(a>='A'&&a<='Z')||(a>='a'&&a<='z')){
            hex[i] = a;
            ++i;
        }
        else{
            printf("please type the value that is hexadecimal");
        }
        
    }
    htoi(hex, length);

}

void htoi(char s[], int length){
    int j;
    int decimal = 0;
    for(j = 0; j< length; j++){
        if(s[j]>='0'&&s[j]<='9'){
            decimal += (s[j] - '0')*pow(16,length-1-j);
        }
        else if(s[j]>='A'&&s[j]<='Z'){
            decimal += (s[j] - 'A' + 10)*pow(16,length-1-j);
        }
        else if(s[j]>='a'&&s[j]<='z'){
            decimal += (s[j] - 'a' + 10)*pow(16,length-1-j);
            
        }
        else continue;
    }
    printf("\n------------\n");
    printf("decimal: %d\n", decimal);
    
}
