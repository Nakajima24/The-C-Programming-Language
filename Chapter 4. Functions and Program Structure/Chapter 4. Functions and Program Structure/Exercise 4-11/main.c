//
//  main.c
//  Chapter 4. Functions and Program Structure
//
//  Created by Brian Chen on 04/11/2023.
//
//Exercise 4-11. Modify getop so that it doesn't need to use ungetch. Hint: use an internal static variable.
#include <stdio.h>
#include <ctype.h>
#define NUMBER '0'
/* getop: get next operator or numeric operand */
int getop(char s[]){
    int i, c;
    static int lastc; // lastc = 0
    while ((s[0] = c = getchar()) == ' ' || c == '\t')
        ;
    if(c == 0)
        c = getchar();
    else{
        c = lastc;
        lastc = 0;
    }
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c; /* not a number */
    i = 0;
    if (isdigit(c)) /*collect integer part*/
        while (isdigit(s[++i] = c = getchar()))
            ;
    if (c == '.') /*collect fraction part*/
        while (isdigit(s[++i] = c = getchar()))
            ;
    s[i] = '\0';
    if (c != EOF)
        lastc = c;
    return NUMBER;
}
int main(void){
    
}

