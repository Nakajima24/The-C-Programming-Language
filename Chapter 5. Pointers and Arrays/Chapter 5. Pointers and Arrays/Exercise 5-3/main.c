//
//  main.c
//  Chapter 5. Pointers and Arrays
//
//  Created by Brian Chen on 07/11/2023.
//
//Exercise 5-3. Write a pointer version of the function strcat that we showed in Chapter 2: strcat(s,t) copies the string t to the end of s.
#include <stdio.h>
#include <stdlib.h>
void str_cat(char *s, char *t){
//    printf("%c\n",*s);
    while(*s++)
        ;
    while(*t != '\0')
        *s++ = *t++;
    *s = '\0';
}
#define size 30
int main(void){
    char s[size] = "welcome ";
    char t[size] = "brian";
    char *x;
    int i = 0;
    x = s;
    str_cat(s, t);
    while(i++ < size)
        printf("%c",*x++);
    printf("\n");
}
