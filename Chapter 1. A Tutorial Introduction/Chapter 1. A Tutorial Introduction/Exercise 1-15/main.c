//
//  main.c
//  Chapter 1. A Tutorial Introduction
//
//  Created by Brian Chen on 11/10/2023.
//


//Exercise 1-15. Rewrite the temperature conversion program of Section 1.2 to use a function for conversion.

#include <stdio.h>
int converse(void);

int main(void) {
    printf("A program print Fahrenheit-Celsius\n");
    printf("Fahr\tCelsius\t\n");
    converse();
    return 0;
}

int converse(void){
    float fahr, cels;
    int lower, upper, step;
    lower = 0;
    upper = 300;
    step = 20;
    while(lower <= upper){
        fahr = lower;
        cels = (fahr - 32)/9*5 ;
        printf("%3.0f%11.1f\n",fahr,cels);
        lower += step;
    }
    return 0;
}
