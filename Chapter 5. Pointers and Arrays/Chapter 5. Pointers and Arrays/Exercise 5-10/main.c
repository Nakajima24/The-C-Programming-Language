//
//  main.c
//  Chapter 5. Pointers and Arrays
//
//  Created by Brian Chen on 14/11/2023.
//

//Exercise 5-10. Write the program expr, which evaluates a reverse Polish expression from the command line, where each operator or operand is a separate argument. For example:
        // expr 21 3 4 + * evaluates 2 x (3+4)
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define size 20
void operator(char **p, int n[]);
static int i = 0;
int main(int argc, char *argv[]){
    int expr_check = 1;
    int num[size];
    expr_check = strcmp(*++argv, "expr"); //if string of (*++argv) == expr, then return 0
    if(expr_check == 0){
        **++argv;
        while(--argc > 1){
            int a = 0;
            if(isdigit(*argv[0])){
                while(isdigit(*argv[0]))
                    a = a * 10 + (int)(*argv[0]++ - '0');
                num[i] = a;
                i++;
            }
            operator(&argv[0], num);
            **++argv;
        }
        printf("\n%d\n", num[0]);
    }
}

void operator(char **p, int n[]){
    switch (**p){
        case '+':
//            printf("n[i-2]:%d n[i-1]:%d \n", n[i-2], n[i-1]);
            n[i-2] = n[i-2] + n[i-1];
            i --;
            break;
        case '*':
//            printf("n[i-2]:%d n[i-1]:%d \n", n[i-2], n[i-1]);
            n[i-2] = n[i-1] * n[i-2];
            i --;
            break;
        case '-':
//            printf("n[i-2]:%d n[i-1]:%d \n", n[i-2], n[i-1]);
            n[i-2] = n[i-2] - n[i-1];
            i --;
            break;
        case '/':
//            printf("n[i-2]:%d n[i-1]:%d \n", n[i-2], n[i-1]);
            n[i-2] = n[i-2] / n[i-1];
            i --;
            break;
    }
}
