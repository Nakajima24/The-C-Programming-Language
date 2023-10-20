//
//  main.c
//  Chapter 1. A Tutorial Introduction
//
//  Created by Brian Chen on 17/10/2023.
//

//Exercise 1-19. Write a function reverse (s} that reverses the character string s. Use it to write a program that reverses its input a line at a time.

#include <stdio.h>
#define max 100

int main(void){
    int c, i, j, k, m;
    char arr[max];
    i = 0;
    while ((c = getchar()) != '\n'){
        arr[i] = c;
        i++;
//        printf("\n%d", i);
    }
    k = i + 1;
    for(j = i; j >= 0; j--){
        arr[k] = arr[j];
        ++k;
//        printf("\n%d", k);
    }
    for(m = i; m<k+1; m++)
        if(m == i) printf("\n");
        else printf("%c", arr[m]);
    printf("\n");
    return 0;
}
