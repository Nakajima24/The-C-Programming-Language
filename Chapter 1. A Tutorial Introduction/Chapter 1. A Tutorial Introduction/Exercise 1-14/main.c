//
//  main.c
//  Chapter 1. A Tutorial Introduction
//
//  Created by Brian Chen on 11/10/2023.
//


//Exercise l-14. Write a program to print a histogram of the frequencies of different characters in its input.

#include <stdio.h>

int c, i, count = 0;
char arr[1024] = {0};

void A_Z_check(void);
void a_z_check(void);
void histogram(char A_a);


int main(void){
    while((c = getchar()) != EOF){
        ++count;
        if(count == 1) printf("\n");
        A_Z_check();
        a_z_check();
    }
    for(i = 0; i < count; i++) printf("-");
    printf("\n");
    histogram('A');
    histogram('a');
}


void A_Z_check(void){
    if(c >= 'A' && c <= 'Z'){
        for(i = 0; i < 26; i++){
            if(c == 'A' + i){
                ++arr[i];
            }
        }
    }
}

void a_z_check(void){
    if(c >= 'a' && c <= 'z'){
        for(i = 26; i < 52; i++){
            if(c == 'a' + i){
                ++arr[i];
            }
        }
    }
}
void histogram(char A_a){
    
    for(i = 0; i < 26; i++){
        if(arr[i] != 0) putchar(A_a + i);
        for(int j = 0; j < arr[i] ; j++){
            printf("|");
        }
        if(arr[i] != 0) printf("\n");
    }
}
