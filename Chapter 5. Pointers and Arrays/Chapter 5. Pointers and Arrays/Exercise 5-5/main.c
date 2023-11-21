//
//  main.c
//  Chapter 5. Pointers and Arrays
//
//  Created by Brian Chen on 09/11/2023.
//
//Exercise 5-5. Write versions of the library functions strncpy, strncat, and strncmp; which operate on at most the first n characters of their argument strings. For example, strncpy (s, t, n) copies at most n characters of t to s. Full descriptions are in Appendix B.
#include <stdio.h>
#define size 30
//#include <string.h>
//strncpy (str2, str1, n) copy the str1 to str2 with n character. If length of str1 < n, fill the rest of it with 'space'
void strn_cpy(char *str2, char *str1, size_t n){
    while(*str2++)
        ;
    for(int i = 0; i < n; i++)
        if(*str1 == '\0')
            *str2++ = ' ';
        else
            *str2++ = *str1++;
}
//strncat(str2, str1, n) append str1 to the end of str2 with n character
void strn_cat(char *str2, char *str1, size_t n){
    while(*str2++)
        ;
    for(int i = 0; i < n; i++)
        *str2++ = *str1++;
}
//strncmp
//r = strncmp(str2, str1, n)
//if str2 > str1: r > 0
//if str2 == str1: r = 0
//else r < 0
int strn_cmp(char *str2, char *str1, size_t n){
    int v2 = 0;
    int v1 = 0;
    for(int i = 0; i < n; i++, *str2++, *str1++){
        if(*str2 > *str1)
            v2 += 1;
        else if(*str2 < *str1)
            v1 += 1;
    }
    if(v1 < v2)
        return 1;
    else if(v1 > v2)
        return -1;
    else
        return 0;
}


int main(void){
    char str1[size] = "a";
    char str2[size] = "ABC";
    //strncpy
    strn_cpy(str2, str1, 6);
    for(int i = 0; i < 20; i ++)
        printf("%c", str2[i]);
    printf("\n----------------\n");
    //strncat
    char str3[size] = "ABC";
    char str4[size] = "DEF";
    strn_cat(str3, str4, 5);
    for(int i = 0; i < 20; i ++)
        printf("%c", str3[i]);
    printf("\n----------------\n");
    //strncmp
    char str5[size] = "abc";
    char str6[size] = "ABC";
    int r_cmp;
    r_cmp = strn_cmp(str5, str6, 3);
    if(r_cmp > 0)
        printf("str2 > str1");
    else if(r_cmp < 0)
        printf("str2 < str1");
    else if (r_cmp == 0)
        printf("str2 = str1");
    printf("\n----------------\n");
}

