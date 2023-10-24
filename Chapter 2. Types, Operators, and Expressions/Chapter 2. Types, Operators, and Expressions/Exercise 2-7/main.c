//
//  main.c
//  Chapter 2. Types, Operators, and Expressions
//
//  Created by Brian Chen on 24/10/2023.
//

#include <stdio.h>
//Exercise 2-7. Write a function invert(x,p,n) that returns x with then bits that begin at position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.
//assume question asking us count the position from right to left
unsigned invert(unsigned x, int p, int n){
    return (~x&(~(~0<<n)<<(p+1-n))) | (x&~((~(~0 << n)<<(p+1-n))));
}

int main(void){
    unsigned int x = 175;
    int p = 5;
    int n = 3;
    int r;
    r = invert(x,p,n);
    printf("%d\n", r);
}


