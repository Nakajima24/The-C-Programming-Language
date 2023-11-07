//
//  main.c
//  Chapter 4. Functions and Program Structure
//
//  Created by Brian Chen on 05/11/2023.
//
//Exercise 5-l. As written, getint treats a + or - not followed by a digit as a valid representation of zero. Fix it to push such a character back on the input.
#include <ctype.h>
#include <stdio.h>
#define BUFSIZE 100
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */
int getch(void){ /* get a (possibly pushed back) character */
 return (bufp > 0) ? buf[--bufp] : getchar();
}
void un_getch(int c){ /* push character back on input */
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
/* getint: get next integer from input into *pn */
int getint(int *pn){
    int c, sign;
    static int sign_last;
    while (isspace(c = getch())) /* skip white space */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        un_getch(c); /* it's not a number*/
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-'){ //receive the sign
        c = getch();
    }
    for (*pn = 0; isdigit(c); c = getch()){

        *pn = 10 * *pn + (c - '0');
    }
    
    *pn *= sign * sign_last;
    printf("*pn:%d\n",*pn);
    if(*pn == 0)
        sign_last = sign;
    else
        sign_last = 1;
    
    if (c != EOF)
        un_getch (c);
    return c; //c = -1 program ended
}
#define SIZE 100
int main(void){
    int n, array[SIZE], getint(int *);
    for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
        if(array[n] == 0)
            n--;
    printf("\n");
    for(int i = 0; i < n; i++){
//        printf("\ni:%d\n",i);
        printf("%d", array[i]);
    }
    printf("\n");
}
