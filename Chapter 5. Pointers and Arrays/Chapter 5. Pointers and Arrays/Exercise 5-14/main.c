//
//  main.c
//  Chapter 5. Pointers and Arrays
//
//  Created by Brian Chen on 17/11/2023.
//
//Exercise 5-14. Modify the sort program to handle a -r flag(command-line variable), which indicates sorting in reverse (decreasing) order.
//review how to quicksort the number again

#include <stdio.h>
#include <string.h>

/* swap: interchange v[i] and v[j] */
void swap(char v[], int i, int j){
    char temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
/* qsort: sort v[left] ... v[right] into increasing order */
void q_sort(char v[], int left, int right){
    int last;
    void swap(char v[], int i, int j);
    if(left >= right)
        return;
    swap(v, left, (left+right)/2);
    last = left;
    for(int i = left + 1; i <= right; i++)
        if(v[i] > v[left])
            swap(v, ++last, i);
    swap(v, last, left);
    q_sort(v, left, last-1);
    q_sort(v, last+1, right);
}

int main(int argc, char *argv[]){
    char v[] = "adbej";
    int right = sizeof(v)/sizeof(v[0]);
//    printf("%s", *++argv);
    if(strcmp(*++argv, "-r") == 0)
        q_sort(v, 0, right);
    int i = 0;
    while(i < right)
        printf("%c ", v[i++]);

}
