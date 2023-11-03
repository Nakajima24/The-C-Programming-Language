//
//  main.c
//  Chapter 4. Functions and Program Structure
//
//  Created by Brian Chen on 30/10/2023.
//
//Exercise 4-2. Extend atof to handle scientific notation of the form 123.45e-6 where a floating-point number may be followed by e or E and an optionally signed exponent.
//123.45e-6 = 123.45 * 10^(-6)

#include <stdio.h>
#include <ctype.h>
#include <math.h>
#define size 10
double a_tof(char s[]);
int main(void){
    double num;
    char s[] = {"123.45e-6"};
    num = a_tof(s);
    printf("%.10f", num);
}

double a_tof(char s[]){
    double val, power, sci_n, result;
    int i, sign;
    for (i = 0; isspace(s[i]); i++) /*skip white space*/
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if(s[i] == 1 || s[i] == -1)
        i++;
    for(val = 0.0; isdigit(s[i]) ; i++)
        val = val*10.0 + (s[i] - '0');
    if(s[i] == '.')
        i++;
    for(power = 1.0; isdigit(s[i]) ; i++){
        val = val * 10.0 + (s[i] - '0');
        power /= 10;
    }
    if(s[i++] == 'e' || s[i++] == 'E'){
        if(s[i] == '-'){ // e-62
            i++;
            for(sci_n = 0.0; isdigit(s[i]); i++)
                sci_n = sci_n*10 + (s[i] - '0');
            sci_n = pow(10,-sci_n);
            result = sign * val * power * sci_n;
        }
        else{
            for(sci_n = 0.0; isdigit(s[i]); i++)
                sci_n = sci_n*10 + (s[i] - '0');
            sci_n = pow(10, sci_n);
            result = sign * val * power * sci_n;
        }
    }
    return result;
}
