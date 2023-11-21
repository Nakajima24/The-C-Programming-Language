//
//  main.c
//  Chapter 5. Pointers and Arrays
//
//  Created by Brian Chen on 16/11/2023.
//
//Exercise 5-13. Write the program t a i l , which prints the last n lines of its input. By default, n is 1, let us say, but it can be changed by an optional argument, so that
    //tail *-n*
#include <stdio.h>
#include <stdlib.h>
#define size 10

int main(int argc, char *argv[]){
    int *dynArr, c;
    static int n = 0;
    static int i = 0;
    // I wrote the 'tail program' right inside the main function. lol ~
    dynArr = malloc(size * sizeof(int));
    printf("n:");
    while((c = getchar()) != '\n')
        dynArr[i++] = c;
    dynArr[i] = '\n';
    if(dynArr[0] == '\n'){
        printf("By default, n = 1. Print the lastest line\n");
        while(--argc > 1)
            *++argv;
        printf("\n%s\n",*++argv);
        free(dynArr);
    }
    else if(dynArr[0] >= '0' && dynArr[0] <= '9'){
        printf("\n");
        int j = 0;
        while(i-- > 0){
            n = n * 10 + (dynArr[j++] - '0');
        }
        if(n >= 1 && n < argc){
            while((argc-n) > 1){
                *++argv;
                argc--;
            }
            while(n > 0){
                printf("%s\n", *++argv);
                n--;
            }
        }
        else{
            printf("error: n out of range\n");
        }
        free(dynArr);
    }
    printf("\n");
}
