//
//  main.c
//  Chapter 2. Types, Operators, and Expressions
//
//  Created by Brian Chen on 22/10/2023.
//
//Exercise 2-5. Write the function any(s1,s2), which returns the first location in the string s1 where any character from the string s2 occurs, or -1 if s1 contains no characters from s2. (The standard library function strpbrk does the same job but returns a pointer to the location.)

#include <stdio.h>
#define size 100

void any(char s1[],char s2[]);
int len1, len2;
int main(void){
    int c1, c2;
    char arr1[size], arr2[size];
    printf("s1: ");
    while((c1 = getchar()) != '\n'){
        arr1[len1] = c1;
        ++len1;
    }
    printf("s2: ");
    while((c2 = getchar()) != '\n'){
        arr2[len2] = c2;
        ++len2;
    }
    any(arr1,arr2);
}


void any(char s1[],char s2[]){
    int i = 0, j=0, smallest = -1;;
    while(i < len1){
        if(j >= len2){
            j = 0;
            i++;
        }
        else if(j < len2){
            if(s1[i] == s2[j++]){
//                printf("\ni: %d",j);
                if(smallest == -1 || (i+1) < smallest){
                    smallest = i;
                }
                
            }
        }
    }
    if(smallest == -1){
        printf("no character from the s2 occurs in s1\n");
    }
    else if(smallest != -1){
        printf("first location in the s1 where any character from the s2 occurs: %d\n", smallest);
        printf("Noted: location count from 0 not 1");
    }
}
