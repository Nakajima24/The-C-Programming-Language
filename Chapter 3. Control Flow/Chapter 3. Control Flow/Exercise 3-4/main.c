//
//  main.c
//  Chapter 3. Control Flow
//
//  Created by Brian Chen on 28/10/2023.
//
//✰Exercise 3-4. In a two's complement number representation, our version of itoa does not handle the largest negative number, that is, the value of n equal to -2^(wordsize-l).Explain why not. Modify it to print that value correctly, regardless of the machine on which it runs.
//???

#include <stdio.h>
#include <limits.h>
void itoa(int n, char s[]);
void reverse(char s[]);

int main(void){
    char s[32];
    itoa(INT_MAX, s);   //int takes 4 bytes
//    itoa(INT_MIN, s);   //error
}

/* itoa: convert n to characters in s */
void itoa(int n, char s[]){
    int i, sign;
    if ((sign = n) < 0) /*record sign*/
        n = -n; /* make n positive */
    i = 0;
    do{ /* generate digits in reverse order */
        s[i++] = n % 10 + '0'; /* get next digit */
    } while ((n /= 10) > 0); /* delete it */
    if (sign < 0)
        s[i++] = '-';
    s[i] ='\0';
    reverse(s);
}
void reverse(char s[]){
    int i = 0;
    while(s[i] != '\0') i++;
    for(i; i>=0; i--){
        printf("%c", s[i]);
    }
}
