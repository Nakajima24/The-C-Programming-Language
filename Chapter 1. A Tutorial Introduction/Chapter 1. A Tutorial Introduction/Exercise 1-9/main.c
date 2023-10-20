//
//  main.c
//  Chapter 1. A Tutorial Introduction
//
//  Created by Brian Chen on 10/10/2023.
//

//Exercise 1-9. Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank.

#include <stdio.h>
int main(void){
    int input;
//    int output;
    while((input = getchar()) != EOF){
        putchar(input);
        printf("|\n");
    }
}
