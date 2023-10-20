//
//  main.c
//  Chapter 1. A Tutorial Introduction
//
//  Created by Brian Chen on 10/10/2023.
//

//Exercise 1-8. Write a program to count blanks, tabs, and newlines.
#include <stdio.h>

/* count blanks, tabs, and newlines. */
int main(void){
    int store, blanks = 0, newlines = 0, tabs = 0;
    while((store = getchar()) != EOF){
        if(putchar(store) == ' ')   ++blanks;
        if(putchar(store) == '\n')  ++newlines;
        if(putchar(store) == '\t')  ++tabs;
    }
    printf("blanks: %d\n",blanks);
    printf("tabs: %d\n",tabs);
    printf("newlines: %d\n",newlines);
}

