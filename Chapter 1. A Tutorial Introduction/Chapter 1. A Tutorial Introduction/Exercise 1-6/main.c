//
//  main.c
//  Chapter 1. A Tutorial Introduction
//
//  Created by Brian Chen on 09/10/2023.
//

//Exercise 1-6. Verify that the expression getchar( ) != EOF is 0 or 1.

#include <stdio.h>
int main(void)
{
   char value;
   value = ((getchar()) != EOF);
   printf("%i\n", value);
   return 0;
}
