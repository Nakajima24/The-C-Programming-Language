//
//  main.c
//  Chapter 4. Functions and Program Structure
//
//  Created by Brian Chen on 04/11/2023.
//
//Exercise 4-12. Adapt the ideas of printd to write a recursive version of itoa; that is, convert an integer into a string by calling a recursive routine.
#include <stdio.h>
char arr[];
int i;
void itoa(int n){  //recursion version
    if (n / 10)
        itoa(n / 10);
    arr[i++] = n % 10 + '0';
}

int main(void){
    itoa(54052349);
    printf("%s\n", arr);
}
