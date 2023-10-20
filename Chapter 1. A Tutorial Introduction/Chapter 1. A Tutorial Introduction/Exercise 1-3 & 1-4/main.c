//
//  main.c
//  Chapter 1. A Tutorial Introduction
//
//  Created by Brian Chen on 09/10/2023.
//

//Exercise l-3. Modify the temperature conversion program to print a heading above the table.
//Exercise l-4. Write a program to print the corresponding Celsius to Fahrenheit table. 


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
        fahr = lower;
        cels = (fahr - 32)/9*5 ;
        printf("%3.0f%11.1f\n",fahr,cels);
        lower += step;
    }
    return 0;
}
