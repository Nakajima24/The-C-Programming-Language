//
//  main.c
//  Chapter 4. Functions and Program Structure
//
//  Created by Brian Chen on 01/11/2023.
//

//Exercise 4-6. Add commands for handling variables. (It's easy to provide twenty-six variables with single-letter names.) Add a variable for the most recently printed value.

#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <math.h>
#include <ctype.h>
#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
int getop(char []);
void push(double);
double pop(void);
void duplicate(double);
void stack_clear(void);
void print(void);
void swap(void);
/* reverse Polish calculator */
int main(void){
    int type, l=0;
    double x, y;
    double op2;
    char s[MAXOP];
    char vari[MAXOP];
    printf("x:");
    while (isdigit(vari[l++] = getchar()))
        ;
    x = atof(vari);
    for(int p=0; p < l; p++){
        vari[p] = '\0';
        l = 0;
    }
    printf("y:");
    while (isdigit(vari[l++] = getchar()))
        ;
    y = atof(vari);
    printf("\n");
    while ((type = getop(s)) != EOF){
        switch (type) {
            case 'x':
                push(x);
                break;
            case 'y':
                push(y);
                break;
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case 'c':
                stack_clear();
                break;
            case '\n':
                print();
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
            }
    }
    return 0;
}


#define MAXVAL 100 /* maximum depth of val stack */
int sp = 0;  /* next free stack position */
int sp2 = 0;
double val[MAXVAL];  /* value stack */
double val2[MAXVAL]; /* new value stack */
/* push: push f onto value stack */
void push(double f){
    if (sp < MAXVAL){
        val[sp++] = f;
        duplicate(f);
    }
    else
        printf("error: stack full. can't push %g\n", f);
}
/* pop: pop and return top value from stack */
double pop(void){
    if (sp > 0)
        return val[--sp];
    else{
        printf("error: stack empty\n");
        return 0.0;
    }
}
void duplicate(double f){
    val2[sp2++] = f;
}
void swap(void){
    double temp;
    temp = val2[sp2-1];
    val2[sp2-1] = val2[sp2-2];
    val2[sp2-2] = temp;
}
void print(void){
    printf("non-swap:");
    for(int i = 0; i < sp2; i++){
        printf("\t%.8g", val2[i]);
    }
    printf("\nswap:\t"); // swap top 2
    swap();
    for(int i = 0; i < sp2; i++){
        printf("\t%.8g", val2[i]);
    }
    swap(); // after display it swap back
    printf("\n");
    printf(">>> %.8g\n\n", pop());
}



int get_ch(void);
void un_getch(int c);
/* getop: get next operator or numeric operand */
int getop(char s[]){
    int i, c;
    while ((s[0] = c = get_ch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c; /* not a number */
    i = 0;
    if (isdigit(c)) /*collect integer part*/
        while (isdigit(s[++i] = c = get_ch()))
            ;
    if (c == '.') /*collect fraction part*/
        while (isdigit(s[++i] = c = get_ch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        un_getch(c);
    return NUMBER;
}
void stack_clear(void){
    for(int i = 0; i < sp2; i++){
        val2[i] = '\0';
    }
    sp2 = 0;
}

#define BUFSIZE 100
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp =0; /* next free position in buf */
int get_ch(void){ /* get a (possibly pushed back) character */
 return (bufp > 0) ? buf[--bufp] : getchar();
}
void un_getch(int c){ /* push character back on input */
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
