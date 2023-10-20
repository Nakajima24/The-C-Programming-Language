//
//  main.c
//  Chapter 1. A Tutorial Introduction
//
//  Created by Brian Chen on 18/10/2023.
//
//Exercise 1-22. Write a program to "fold" long input lines into two or more shorter lines after the last non-blank character that occurs before the n-th column (n is adjustable) of input. Make sure your program does something intelligent with very long lines, and if there are no blanks or tabs before the specified column.

#include <stdio.h>

#define MAXLINE 1000
//#define TAB_WIDTH 8
#define LINE_WIDTH 20

void container(int c, char arr[]);
void fold(char arr[]); //fold it and print

int i, j;

int main(void){
    int c;
    char arr[MAXLINE];
    while((c = getchar()) != '\n'){
        container(c, arr);
    }
    fold(arr);
}
void container(int c, char arr[]){
    arr[i] = c;
    ++i;
}

void fold(char arr[]){
    for(i = 0; arr[i] != '\0'; i++){
        printf("\n");
        for(i = 0 + (LINE_WIDTH * j); i < (LINE_WIDTH * (j+1)); i++){
            printf("%c", arr[i]);
        }
        ++j;
    }
    printf("\n");
}
