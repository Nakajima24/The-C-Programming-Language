//
//  main.c
//  Chapter 2. Types, Operators, and Expressions
//
//  Created by Brian Chen on 24/10/2023.
//
//Exercise 2-6. Write a function setbits (x,p,n,y) that returns x with the n bits that begin at position p set to the rightmost n bits of y, leaving the other bits unchanged.

#include<stdio.h>
 
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    return (x & ~(~(~0 << n) << (p+1-n))) | (y & ~(~0 << n)) << (p+1-n);
}
 
 
int main(void)
{
    unsigned int x = 73;
    unsigned int y = 23;
    int p = 5;
    int n = 3;
    int r;
    r = setbits(x, p, n, y);
    printf("%d\n", r); //r的结果应为121
    return 0;
}
