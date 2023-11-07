//
//  main.c
//  Chapter 4. Functions and Program Structure
//
//  Created by Brian Chen on 04/11/2023.
//
//Exercise 4-13. Write a recursive version of the function reverse(s), which reverses the string s in place./
#include <stdio.h>
int size;
void reverse(char s[]){
    if(size > 0){
        size--;
        printf("%c",s[size]);
        reverse(s);
    }
}
int main(void){
    char s[] = "hello brian this is a test";
    printf("%s\n", s);
    size = sizeof(s) / sizeof(s[0]);
    reverse(s);
    printf("\n");
}
