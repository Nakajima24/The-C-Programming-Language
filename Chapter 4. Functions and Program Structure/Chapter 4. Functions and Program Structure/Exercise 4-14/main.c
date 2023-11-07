//
//  main.c
//  Chapter 4. Functions and Program Structure
//
//  Created by Brian Chen on 05/11/2023.
//
//Exercise 4-14. Define a macro swap(t,x,y) that interchanges two arguments of type t. (Block structure will help.)
#include <stdio.h>
#define swap(t,x,y){\
    t temp;\
    temp = x;\
    x = y;\
    y = temp;}
int main(void){
    int x = 4;
    int y = 7;
    swap(int,x,y);
    printf("x = %d\ny = %d\n",x,y);
}

