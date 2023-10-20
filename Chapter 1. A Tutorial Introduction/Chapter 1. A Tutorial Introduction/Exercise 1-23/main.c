//
//  main.c
//  Chapter 1. A Tutorial Introduction
//
//  Created by Brian Chen on 19/10/2023.
//

//Exercise 1-23. Write a program to remove all comments from a C program. Don't forget to handle quoted strings and character constants properly. C comments do not nest.

/* Test text

 #include <stdio.h> // for printf
 int main(void)
 {
     char s[] = "// hello world!\n"; // this is comment
     printf("%s\n", s);
 
     return 0;
 }
*/
 

#include <stdio.h>
#define limi 1000
int i, count_1, count_2, count_3;
//count_1 is for '\"'
//count_2 is for '\n'
//count_3 is for '/'
void input(int c, char arr[]);
void recompose(char arr[]);

int main(void){
    int c, zero = 0;
    char arr[limi];
    while((c = getchar()) != EOF){
        input(c, arr);
        recompose(arr);
        ++i;
    }
    printf("\n");
    i = 0;
    while(1){
        printf("%c", arr[i]);
        ++i;
        /* if we print whole array at a time then it will show up garbled numbers
         we assume no one will press the space buttom in his/her code more than 50 times. This determine if the code is end.
         */
        //-------------------------------------
        if(arr[i] == '\0') ++zero;
        if (arr[i] == '\n') zero = 0;
        if(zero >= 100)  break;
        //-------------------------------------
        
    }
}

void input(int c, char arr[]){
    arr[i] = c;
//    printf("%d",i);
}
void recompose(char arr[]){
    
    if(arr[i] == '\"'){
        ++count_1; // count_1 == 0,2,4,6,8,10.... means out of the "  "
    }
    if(arr[i] == '/'){ //caution: arr[i] = '//' at this moment
//        printf("%c", arr[i]);
        count_2 = 1;
    }
    if(arr[i] == '\n'){ // detect changing the line
        count_2 = 0;
    }
    if(count_1%2 == 0  && count_2 == 1){ // outside the "  "  && detect the comment sentence started
        arr[i] = ' ';
    }
}
