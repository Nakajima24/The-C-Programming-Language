//
//  main.c
//  Chapter 4. Functions and Program Structure
//
//  Created by Brian Chen on 31/10/2023.
//

//Exercise 4-4. On the basis of ex.4-3, add commands to print the top element of the stack without popping, to duplicate it, and to swap the top two elements. Add a command to clear the stack.
//this calculator only for one operator calculating
//e.g.
//4 3 -
// 3 5 2 * + (error)
#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <math.h> // for fmod
//fmod(5,3) -> 2
#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
int getop(char []);
void push(double);
double copy(void);
void stack_clear(void);
#define MAXVAL 100 /* maximum depth of val stack */
int sp = 0;  /* next free stack position */
int sp_1 = 0;
double val[MAXVAL];  /* value stack */
/* reverse Polish calculator */
int main(void){
    int type;
    double op2;
    char s[MAXOP];
    while ((type = getop(s)) != EOF){
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(copy() + copy());
                break;
            case '*':
                push(copy() * copy());
                break;
            case '-':
                op2 = copy();
                push(copy() - op2);
                break;
            case '/':
                op2 = copy();
                if (op2 != 0.0)
                    push(copy() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '%':
                op2 = copy();
                if(op2 != 0.0)
                    push(fmod(op2, copy()));
                break;
            case 'c':
                stack_clear();
                break;
            case '\n':
                if(sp % 3 != 0){
                    printf("error: this calculator only for one operator calculating\n");
                    stack_clear();
                    break;
                }
                for(int i = 0; i < sp; i++)
                    printf( "\t%.8g", val[i]);
                printf( "\n\t%.8g\n", copy());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
            }
    }
    return 0;
}



/* push: push f onto value stack */
void push(double f){
    if (sp < MAXVAL){
        val[sp++] = f;
        sp_1 = sp;
    }
    else
        printf("error: stack full. can't push %g\n", f);
}
/* copy: copy and return top value from stack */
double copy(void){
    if (sp_1 > 0){
        --sp_1;
        return val[sp_1];
    }
    else{
        printf("error: stack empty\n");
        return 0.0;
    }
}
void stack_clear(void){
    for(int i = 0; i < sp; i++)
        val[i] = '\0';
    sp = 0;
}

#include <ctype.h>
int get_ch(void);
void un_getch(int c);
/* getop: get next operator or numeric operand */
int getop(char s[]){
    int i, c;
    while ((s[0] = c = get_ch()) == ' ' || c == '\t') // use while loop to eliminate space and tab
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
    if (c == 'c') /*input c, clear the stack*/
        while (isdigit(s[++i] = c = get_ch()))
            ;
    s[i] = '\0';
    if (c != EOF)
//        printf("\nin\n");
        un_getch(c);
        ;
    return NUMBER;
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
