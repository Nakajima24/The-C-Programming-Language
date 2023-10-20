//
//  main.c
//  Chapter 1. A Tutorial Introduction
//
//  Created by Brian Chen on 12/10/2023.
//

//Exercise 1-17. Write a program to print all input lines that are longer than 8 characters.
//print the result at a time


#include <stdio.h>

#define space 1000 // create a space for array, 1000 rooms for the array
#define certified 8

int cur_line(char cache[], int space_limi);
int classify(int len, char container[], char cache[], int pointer);

int main(void){
    int len, pointer;
    char container[space]; // contain the sentence more than certified character
    char cache[space];
    
    pointer = 0;
    while((len = cur_line(cache, space)) > 0){
        classify(len, container, cache, pointer);
        if(len > certified) pointer += len;
//        printf("\npointer: %i\n", pointer);

    }
    printf("%s", container);
}
int cur_line(char cache[], int space_limi){
    int c, i;
    for(i = 0; i < space_limi && (c = getchar()) != EOF && c != '\n'; i++ ){
        cache[i] = c;
    }
    if(c == '\n'){
        cache[i] = c;
        ++i;
    }
    return i;
}

int classify(int len, char container[] ,char cache[], int pointer){
    int k;
    if(len > certified){
        
        for(k = 0; k < len; k++){
            container[k + pointer] = cache[k];
        }
        printf("len: %d\n", len);
    }
    return pointer;
}
