//
//  main.c
//  Chapter 2. Types, Operators, and Expressions
//
//  Created by Brian Chen on 24/10/2023.
//
//Exercise 2-8. Write a function rightrot(x,n) that returns the value of the integer x rotated to the right by n bit positions.
//e.g. x=1011 001 -> rightrot(x,3) -> 001 1011
#import <stdio.h>
int bits;


unsigned rightrot(unsigned x, int n){
    return (x&~(~0<<n))<<(bits-n) | x>>n;
}
//test 1
//10110111111 = 1471
//11110110111 ->1975
//test 2
//101011 = 43
//011000 (x&~(~0<<n))<<(new_bits-n)
//000101 (x>>n)
//
//011101 ->29 

int main(void){
    unsigned int x = 43;
    int n = 3;
    int r;
    float count=0;
    unsigned  var = (x < 0) ? -x : x;
    /*
     var = (x < 0) ? -x : x
        equal
     if((x < 0) == TRUE)    var = -x; check the input is positive numbe
     else   val = x;
     */
    for(bits = 0; var != 0; ++bits) {
        var >>= 1;  //var = var >> 1
        // let x = 24   enter the loop->11000->01100->00110->00011->00001->out of loop
    }
    r = rightrot(x,n);
    printf("%d\n",r);
    
}
  
