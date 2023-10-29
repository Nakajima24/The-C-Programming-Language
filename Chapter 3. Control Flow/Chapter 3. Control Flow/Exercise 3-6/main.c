//
//  main.c
//  Chapter 3. Control Flow
//
//  Created by Brian Chen on 29/10/2023.
//
//Exercise 3-6. Write a version of itoa that accepts three arguments instead of two. The third argument is a minimum field width; the converted number must be padded with blanks on the left if necessary to make it wide enough.
#include <stdio.h>
#define size 100
/* itoa: convert n to characters in s. Converted number be padded with 'w' width blanks */
void itoa(int n, char s[], int w);
void reverse(char s[]);

int main(void){
    char s[size];
    itoa(942, s, 20);
}

void itoa(int n, char s[], int w){
    int i, sign, j;
    if ((sign = n) < 0) /*record sign*/
        n = -n; /* make n positive */
    i = 0;
    do{ /* generate digits in reverse order */
            s[i++] = n % 10 + '0'; /* get next digit */
    } while ((n /= 10) > 0); /* delete it */
    if (sign < 0)
        s[i++] = '-';
    j = i;
    while(i < (j+w)) s[i++] = ' ';
    s[i] ='\0';
    reverse(s);
}
void reverse(char s[]){
    int i = 0;
    while(s[i] != '\0') i++;
    for(i; i>=0; i--)   printf("%c", s[i]);
}
