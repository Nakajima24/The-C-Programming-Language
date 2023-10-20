//
//  main.c
//  Chapter 1. A Tutorial Introduction
//
//  Created by Brian Chen on 12/10/2023.
//

//Exercise 1-16. Revise the main routine of the longest-line program so it will correctly print the length of arbitrarily long input lines, and as much as possible of the text.

#include <stdio.h>
#define MAXLINE 1000   /* maximum input line length */

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

/* print the longest input line */
int main(void)
{
   int len;            /* current line length */
   int max;            /* maximum length seen so far */
   char line[MAXLINE];    /* current input line */
   char longest[MAXLINE]; /* longest line saved here */
   max = 0;
    printf("caution: changing the line is considered to have 1 more character\n");
   while ((len = get_line(line, MAXLINE)) > 0)
       if (len > max) {
           max = len;
           copy(longest, line); //from current input line copy to longest line
       }
   if (max > 0)  /* there was a line */
       printf("max : %d\n", max);
   return 0;
}

/* getline:  read a line into s, return length  */
int get_line(char s[], int lim)
{
   int c, i;
   for (i = 0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
                //lim - 1 is MAXLINE - 1
       s[i] = c; //c = getchar()
   if (c == '\n') {
       s[i] = c;
       ++i;
   }
   s[i] = '\0'; // 字符串数组结尾就是'\0'，表示这串字符到结尾了
   return i;
}

/* copy:  copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
   int i;
   i = 0;
   while ((to[i] = from[i]) != '\0')
       ++i;
}
