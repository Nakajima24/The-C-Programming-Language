//
//  main2.c
//  Chapter 3. Control Flow
//
//  Created by Brian Chen on 26/10/2023.
//

#include <stdio.h>
#define size 100
void escape(char s[], char t[]);
int main(void){
    int c, i=0;
    char t[size], s[size];
    while((c=getchar())!=EOF){
        s[i++] = c;
    }
    s[i] = '\0';
    escape(s,t);
    printf("%s\n",t);
}

void escape(char s[], char t[]){
    int i = 0, j = 0;
    while(s[i] != '\0'){
        switch(s[i]){
            case '\n':
                t[j++] = '\\';
                t[j++] = 'n';
                i++;    //be aware of this, i always forgot this part
                break;
            case '\t':
                t[j++] = '\\';
                t[j++] = 't';
                i++;
            default:
                t[j++] = s[i++];
                break;
        }
        
    }
}
