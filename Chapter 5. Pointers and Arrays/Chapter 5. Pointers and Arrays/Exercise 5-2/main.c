//
//  main.c
//  Chapter 5. Pointers and Arrays
//
//  Created by Brian Chen on 07/11/2023.
//
//Exercise 5-2. Write getfloat, the floating-point analog of getint. What type does getfloat return as its function value?

//as shown below, it return double value

#include <ctype.h>
#include <stdio.h>
#include <math.h>
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
double getfloat(double *pn){
    double c, sign;
    static double sign_last = 1;
    while (isspace(c = getch())) /* skip white space */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
        un_getch(c); /* it's not a number*/
        return 0.0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') //receive the sign
        c = getch();
    for (*pn = 0; isdigit(c); c = getch()){
        *pn = 10 * *pn + (c - '0');
//        printf("*pn:%g\n",*pn);
    }
    int digit;
    double frac;
    if(c == '.')
        c = getch();
    for (frac = 0, digit = 1; isdigit(c); c = getch(), digit++){
        frac = frac + pow(0.1,digit) * (c - '0');
//        printf("*pn:%f\n",frac);
    }
    
    *pn = (*pn + frac) * sign * sign_last;
    printf("*pn:%g\n",*pn);
    if(*pn == 0.0)
        sign_last = sign;
    else
        sign_last = 1.0;
    if (c != EOF)
        un_getch (c);
    return c; //c = -1 program ended
}
#define SIZE 100
int main(void){
    int n;
    double array[SIZE], getfloat(double *), result = 0.0;
    for (n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++)
        if(array[n] == 0)
            n--;
    printf("\n");
    for(int i = 0; i < n; i++){
        if(i == 0 && array[0] > 0)
            printf(" ");
        else if(array[i] > 0)
            printf("+");
        printf("%g\n", array[i]);
        result += array[i];
    }
    printf("------------\n%g",result);
    printf("\n");
}
