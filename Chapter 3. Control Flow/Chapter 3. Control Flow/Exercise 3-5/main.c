//
//  main.c
//  Chapter 3. Control Flow
//
//  Created by Brian Chen on 29/10/2023.
//
//Exercise 3-5. Write the function itob(n, s, b) that converts the integer n into a base b character representation in the string s. In particular, itob(n, s, 16)formats n as a hexadecimal integer in s.
#include <stdio.h>
#define size 100
void itob(int n, char s[], int b);
void reverse(char s[]);

int main(void){
    char s[size];
    itob(1023, s, 8);
}
void itob(int n, char s[], int b){
    int i = 0, num;
    do{
        num = n % b;
        if(num >= 0 && num <= 9){
            s[i] = '0' + num;
        }
        else{
            s[i] = num - 10 + 'A';
        }
        
        i++;
    }while((n /= b) > 0);
    s[i] = '\0';
//    printf("\n%s",s);
    reverse(s);
}
void reverse(char s[]){
    int i = 0;
    while(s[i] != '\0')    i++;
    for(i; i >= 0; i--){
        printf("%c", s[i]);
    }
}
