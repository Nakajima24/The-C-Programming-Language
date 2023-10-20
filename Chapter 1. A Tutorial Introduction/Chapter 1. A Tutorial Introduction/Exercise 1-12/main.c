//
//  main.c
//  Chapter 1. A Tutorial Introduction
//
//  Created by Brian Chen on 10/10/2023.
//

//Exercise 1-12. Write a program that prints its input one word per line.
//eg. 123456
//  ->123
//    456
#include <stdio.h>

int main(void) {
    // your code goes here
    int input;
    while((input = getchar()) != EOF){
        if(input == ' '){
            printf("\n");
            putchar(input);
        }
        else{
            putchar(input);
        }
    }
    
}
