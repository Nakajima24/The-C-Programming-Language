//
//  main.c
//  Chapter 5. Pointers and Arrays
//
//  Created by Brian Chen on 12/11/2023.
//
//Exercise5-9. Rewrite the routines day_of_year and month_day with pointers instead of indexing
#include <stdio.h>
static int daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},//non leap year
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} //leap year
};
static int (*p)[13];
void pointer_conver(void){
    p = daytab;
}
/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day){
    int i, leap;
    leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;
    for (i = 1; i < month; i++)
        day += p[leap][i];
    return day;
}
/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday){
    
    int i, leap;
    leap = (year%4 == 0 && year%100 != 0) || year%400 ==  0;
    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= p[leap][i];
    *pmonth = i;
    *pday = yearday;
    printf("\nmonth/day: %d/%d\n", *pmonth, *pday);
    
}

int main(void){
    int m, d;
    pointer_conver();
    printf("\n");
    printf("day:%d\n", day_of_year(2024, 11, 3));
    month_day(2024, 308, &m, &d);
}
