//
//  main.c
//  Chapter 2. Types, Operators, and Expressions
//
//  Created by Brian Chen on 25/10/2023.
//
//Exercise 2-9. In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit in x. Explain why. Use this observation to write a faster version of bitcount.

//bitcount only count 1, not 0

#include <stdio.h>
int main(void){
    int x = 1234;
    int i;
    for(i = 0; x!=0; i++){
        x &= (x-1);
    }
    printf("%d", i);
}
