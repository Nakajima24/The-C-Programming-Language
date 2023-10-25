//
//  main.c
//  Chapter 2. Types, Operators, and Expressions
//
//  Created by Brian Chen on 25/10/2023.
//
//Exercise 2-10. Rewrite the function lower, which converts upper case letters to lower case, with a conditional expression instead of if-else.
#include <stdio.h>
#define size 100

int main(void){
    int c, i=0;
    char s[size];
    printf("Input upper case letters: ");
    while((c = getchar()) != '\n'){
        s[i++] = (c>='A' && c<='Z') ? (c-'A'+'a') : '\0';
    }
    printf("%s", s);
    
}
