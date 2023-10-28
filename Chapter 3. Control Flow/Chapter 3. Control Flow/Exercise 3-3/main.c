//
//  main.c
//  Chapter 3. Control Flow
//
//  Created by Brian Chen on 27/10/2023.
//
//Exercise 3-3. Write a function expand(s1,s2) that expands shorthand notations like a-z in the string s1 into the equivalent complete list abc...xyz in s2. Allow for letters of either case and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing - is taken literally.

#include <stdio.h>
#define size 100

void expand(char s1[], char s2[]);

int main(void){
    while(1){
        int c, i = 0;
        char s1[size], s2[size];
        
        while((c = getchar()) != '\n')
            s1[i++] = c;
        s1[i] = '\0';
        expand(s1, s2);
    }
    return 0;
}


void expand(char s1[], char s2[]){
    int i = 0, j =0;
    int k, bound, lower, upper;
    
    while(s1[i] != '\0'){
        if(  ((s1[i] >= 'a' && s1[i] <= 'z') && (s1[i+2] >= 'a' && s1[i+2] <= 'z'))
           ||((s1[i] >= 'A' && s1[i] <= 'Z') && (s1[i+2] >= 'A' && s1[i+2] <= 'Z'))
           ||((s1[i] >= '0' && s1[i] <= '9') && (s1[i+2] >= '0' && s1[i+2] <= '9'))  ){
            i++;
            if(s1[i] == '-' && s1[i-1] <= s1[i+1]){
                i++;
//                a-b-c-d
                upper = s1[i];
                lower = s1[i-2];
                if(s1[i] >= lower && s1[i] <= upper){
                    bound = s1[i] - s1[i-2];
                    for(k = 0; k < bound; k++){
                        s2[j++] = s1[i-2];
                        s1[i-2]++;
                    }
                    if(s1[i+1] != '-'){
                        s2[j++] = s1[i-2];
                    }
                }
            }
        }
        else{
            i++;
        }
        
    }
    s2[j] = '\0';
    j = 0;
    while(s2[j] != '\0'){
        printf("%c", s2[j]);
        j++;
    }
    printf("\n");
}
