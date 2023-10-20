//
//  main.c
//  Chapter 1. A Tutorial Introduction
//
//  Created by Brian Chen on 17/10/2023.
//

//Exercise 1-18. Write a program to remove trailing blanks and tabs from each line of input, and to delete entirely blank lines.

#include <stdio.h>
#define max_char 50

int cur_line(char line[], int limi);
//void output(int len, char container[]);
int pointer;

int main(void){
    int len;
    pointer = 0;
    char container[max_char];
    while(cur_line(container, max_char) > 0 ){
    }
    printf("\n%s\n", container);
    return 0;
}
          

int cur_line(char container[], int limi){
    int i, c;
    for(i = 0; i < max_char - 1 && (c = getchar()) != EOF ; i++){
        if(c != ' '){  
            container[i + pointer] = c;
        }
        else if(c == ' '){
            --i;
            continue;
        }
        //printf("c:%c  i:%d\n",c,i);
    }
    pointer += i;
    //printf("pointer: %d",pointer);
    return i;
}
