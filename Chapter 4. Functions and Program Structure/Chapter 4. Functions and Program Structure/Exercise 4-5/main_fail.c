//
//  main.c
//  Chapter 4. Functions and Program Structure
//
//  Created by Brian Chen on 01/11/2023.
//
//Exercise 4-5. On the basis of ex. 4-4, add access to library functions like sin , exp , and pow. See <math.h> in Appendix B, Section 4.


//fail

#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <math.h>
#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
int getop(char [], char math_ch[]);
void push(double);
double pop(void);
void duplicate(double);
void print(void);
void swap(void);
int x;
int y;
/* reverse Polish calculator */
int main(void){
    int type;
    double op2;
    char s[MAXOP];
    char math_ch[MAXOP];
    while ((type = getop(s, math_ch)) != EOF){
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case 's': //put sin in
                push(sin(atof(s)));
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


#include <ctype.h>
int get_ch(void);
void un_getch(int c);
/* getop: get next operator or numeric operand */
int getop(char s[], char math_ch[]){
    int i, c, k;
    while ((s[0] = c = get_ch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    
    if (!isdigit(c) && c != '.')
        return c;
    i = 0;
    if(!isdigit(c) && c != '.' && c != 's' && c != 'i' && c != 'n'){
        k = 0;
        while (!isdigit(s[++i] = c = get_ch()))
            ++k;
        printf("i:%d k:%d\n", i ,k);
        if((s[i - k] == 's' && s[i - k + 1] == 'i'
            && s[i - k + 2] == 'n')){
            for(int j = 0; j < k;j++)
                s[i--] = '\0';
            while (isdigit(s[++i] = c = get_ch()))
                ;
            return 's';
        }
    }
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
