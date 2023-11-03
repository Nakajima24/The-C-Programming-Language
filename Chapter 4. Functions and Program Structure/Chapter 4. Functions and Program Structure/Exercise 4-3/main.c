
//Exercise 4-3. Given the basic framework, it's straightforward to extend the calculator. Add the modulus (%) operator and provisions for negative numbers.

#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <math.h> // for fmod
//fmod(5,3) -> 2
#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
int getop(char []);
void push(double);
double pop(void);
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
            case '%':
                op2 = pop();
                if(op2 != 0.0)
                    push(fmod(pop(), op2));
                break;
            case '\n':
                printf( "\t%.8g\n", pop());
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
double val[MAXVAL];  /* value stack */
/* push: push f onto value stack */
void push(double f){
    if (sp < MAXVAL)
        val[sp++] = f;
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
    s[i] = '\0';
    if (c != EOF)
        printf("\nin\n");
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
