//
//  main.c
//  Chapter 1. A Tutorial Introduction
//
//  Created by Brian Chen on 09/10/2023.
//

//Exercise 1-2. Experiment to find out what happens when
//printf’s argument string contains '\c, where c is some character not listed above.
#include <stdio.h>
int main(void){
    printf("hello\c");
    return 0;
}

//output: helloc
