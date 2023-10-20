//
//  main.c
//  Chapter 1. A Tutorial Introduction
//
//  Created by Brian Chen on 09/10/2023.
//
//Exercise 1-5. Modify the temperature conversion program to print the table in reverse order, that is, from 300 degrees to 0.

#include <stdio.h>

int main(void) {
    printf("A program print Fahrenheit-Celsius\n");
    float fahr, cels;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;
    printf("Fahr\tCelsius\t\n");
    while(lower <= upper){
        fahr = upper;
        cels = (fahr - 32)/9*5 ;
        printf("%3.0f%11.1f\n",fahr,cels);
        upper -= step;
    }
    return 0;
}
