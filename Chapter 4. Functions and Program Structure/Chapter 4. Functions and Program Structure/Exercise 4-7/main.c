//
//  main.c
//  Chapter 4. Functions and Program Structure
//
//  Created by Brian Chen on 02/11/2023.
//

//Exercise 4-7. Write a routine ungets(s) that will push back an entire string onto the input. Should ungets know about buf and bufp, or should it just use ungetch?
//ans: ungetss doesn't mneed to know about buf and bufp
#include <stdio.h>
#define size 50
void ungets(char s[]);
int i;
int main(void){
    char str[size];
    while(i >= -1){
        i = 0;
        while((str[i++] = getchar()) != '\n')
            ;
        ungets(str);
        
    }
}

void ungets(char s[]){
    while(i >= 0){
        printf("%c ", s[i--]);
    }
    printf("\n");
}
