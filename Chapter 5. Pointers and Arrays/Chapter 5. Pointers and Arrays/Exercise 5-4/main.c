//
//  main.c
//  Chapter 5. Pointers and Arrays
//
//  Created by Brian Chen on 08/11/2023.
//
//Exercise 5-4. Write the function strend (s, t), which returns 1 if the string t occurs at the end of the string s, and zero otherwise.

#include <stdio.h>

int strend(char *s, char *t){
    while(*s++){
        if(*s == *t){
            *t++;
            if(*t == '\0')
                break;
        }
    }
    if(*++s == '\0')
        return 1;
    else
        return 0;
}
#define size 30
int main(void){
    char arr1[size] = "fundation";
    char arr2[size] = "tion";
    int result;
    result = strend(arr1, arr2);
    printf("%d\n", result);
}
