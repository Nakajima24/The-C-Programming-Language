//
//  main.c
//  Chapter 3. Control Flow
//
//  Created by Brian Chen on 25/10/2023.
//
//Exercise 3-1. Our binary search makes two tests inside the loop, when one would suffice (at the price of more tests outside). Write a version with only one test inside the loop and measure the difference in run-time.
#include <time.h>
#include <stdio.h>

int binsearch(int x, int v [], int n);
int ordersearch(int x, int v[], int n);

int main(void){
    int r1, r2;
    int v[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17};
    //---------------------------------------------------------------
    //two test inside the loop
    clock_t begin_1 = clock();
    //r is the position of x occurs in v[]. Position count from 0 not 1
    r1 = binsearch(2, v , 17);
    printf("r1: %d\n", r1);
    clock_t end_1 = clock();
    double time_spent_1 = (double)(end_1 - begin_1) / CLOCKS_PER_SEC;
    printf("bin:%f\n", time_spent_1);
    //---------------------------------------------------------------
    //one test inside the loop
    clock_t begin_2 = clock();
    //r is the position of x occurs in v[]. Position count from 0 not 1
    r2 = ordersearch(2, v , 17);
    printf("r2: %d\n", r2);
    clock_t end_2 = clock();
    double time_spent_2 = (double)(end_2 - begin_2) / CLOCKS_PER_SEC;
    printf("order:%f\n", time_spent_2);
    if(time_spent_1 > time_spent_2) printf("ordersearch faster\n");
    else if(time_spent_1 < time_spent_2) printf("binsearch faster\n");
    
}

//two test inside the loop
/* binsearch: find x in v [0] <= v [1] <= … <= v [n−1] */
int binsearch(int x, int v [], int n){
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low+high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else /* found match */
            return mid;
    }
    return -1; /* no match */
}

//one test inside the loop
int ordersearch(int x, int v[], int n){
    int low, high, pos = -1;
    low = 0;
    high = n - 1;
    while(low <= high){
        if(x == v[high]){
            pos = high;
            return pos;
        }
        else --high;
    }
    return pos; //pos = -1
}
