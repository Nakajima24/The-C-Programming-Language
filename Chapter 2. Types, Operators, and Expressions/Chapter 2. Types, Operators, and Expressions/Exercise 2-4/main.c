//
//  main.c
//  Chapter 2. Types, Operators, and Expressions
//
//  Created by Brian Chen on 22/10/2023.
//
//Exercise 2-4. Write an alternate version of squeeze (s1,s2) that deletes each character in s1 that matches any character in the string s2.

/*-----------------------------------
void squeeze(char s[], int c){
    int i, j;
    for (i = j = 0; s[i] !=  '\0'; i++)
        if (s[i] != c)
            s[j++] = s[i];
    s[j] =  '\0';
}
-------------------------------------*/

#include <stdio.h>
#define size 10
void squeeze(char s1[], char s2[], int len1, int len2);

int main(void){
    int len1 = 0, len2 = 0;
    int i = 0, j = 0;
    int c1, c2;
    char s1[size], s2[size];
    printf("\ns1: ");
    while((c1 = getchar()) != '\n'){
        s1[i++] = c1;
        ++len1;
    }
    printf("%s",s1);
//    printf("length 1: %d", len1);
    printf("\ns2: ");
    while((c2 = getchar()) != '\n'){
        s2[j++] = c2;
        ++len2;
    }
    printf("%s",s2);
//    printf("length 2: %d", len2);
    squeeze(s1, s2, len1, len2);
}

void squeeze(char s1[], char s2[], int len1, int len2){
    int i = 0, j = 0;
    while(i < len1){
        if(j >= len2){
            ++i;
            j = 0;
        }
        if(j < len2){
//            printf("\ni: %d ;j: %d",i,j);
            if(s1[i] == s2[j]){
                s1[i] = '\0';
            }
            ++j;
        }
    }
    printf("\n-------\n");
    for(i = 0; i < len1; i++){
        printf("%c", s1[i]);
    }
    printf("\n");
}
