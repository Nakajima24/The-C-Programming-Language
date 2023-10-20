//
//  main.c
//  Chapter 1. A Tutorial Introduction
//
//  Created by Brian Chen on 11/10/2023.
//

//Exercise l-13. Write a program to print a histogram of the lengths of words in its input. It is easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.
#include <stdio.h>
int main(void){
    int c,i,  count = 0;
    while((c = getchar()) != EOF)   ++count;
    //    this is horizontal histogram
    for(i = 0; i< count; i++)   printf("_");
    printf("\n");
    for(i = 0; i< count-1; i++)   printf(" ");
    printf("|\n");
    for(i = 0; i< count; i++)   printf("-");
    printf("\n\n");
    //    this is horizontal histogram
    printf("|-|");
    for(i = 0; i< count-1; i++){
        printf("\n| |");
    }
    printf("\n---\n");
}
