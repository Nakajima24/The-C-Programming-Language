//
//  main.c
//  Chapter 1. A Tutorial Introduction
//
//  Created by Brian Chen on 10/10/2023.
//

//Exercise 1-10. Write a program to copy its input to its output, replacing each tab by \t, each backspace by \b, and each backslash by \\. This makes tabs and backspaces visible in an unambiguous way.

#include <stdio.h>
int main(void){
    int input;
    while((input = getchar()) != EOF){
        if(input == '\t') printf("\\t");
        if(input == '\n') printf("\\n");
        if(input == '\b') printf("\\b");
    }
}
