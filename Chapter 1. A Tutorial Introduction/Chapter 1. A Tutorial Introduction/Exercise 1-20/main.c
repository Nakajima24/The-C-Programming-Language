//
//  main.c
//  Chapter 1. A Tutorial Introduction
//
//  Created by Brian Chen on 18/10/2023.
//

//Exercise 1-20. Write a program 「detab」 that replaces tabs in the input with the proper number of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns. Should n be a variable or a symbolic parameter?

#include <stdio.h>

#define MAXLINE 1000
#define TAB_WIDTH 4

int main(void){
    int c, i, j;
    char line[MAXLINE];
    printf("we use character '.' to represent space\n");
    printf("please innput any sentence with the 'tab' then press enter and it will turn it into '.'\n");
    printf("example: Hello    world -> Hello....world\n");
    i =0;
    while((c = getchar()) != '\n'){
        line[i] = c;
        if(c == '\t'){
            for(j = 0; j < TAB_WIDTH; j++){
                line[i] = '.';
                ++i;
            }
        }
        ++i;
    }
    for(i = 0; i < 20; i++)
        printf("%c", line[i]);
    printf("\n");
    return 0;
}

