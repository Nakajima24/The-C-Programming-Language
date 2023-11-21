//
//  main.c
//  Chapter 5. Pointers and Arrays
//
//  Created by Brian Chen on 10/11/2023.
//

#include <stdio.h>
static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},//non leap year
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} //leap year
};
/* day_of_year: set day of year from month & day */
void day_of_year_check(int month, int day, int leap){
    if(month <= 0 || month > 12)
        printf("month out of range");
    else if(month == 2){
        if(leap == 0 && (day <= 0 || day > 28))
            printf("day out of range");
        else if(leap == 0 && (day <= 0 || day > 28))
            printf("day out of range");
    }
    else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
        if(day <= 0 || day > 31)
            printf("day out of range");
    }
    else{
        if(day <= 0 || day > 30)
            printf("day out of range");
    }
}
int day_of_year(int year, int month, int day){
    int i, leap;
    leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;
    day_of_year_check(month, day, leap);
    for (i = 1; i < month; i++)
        day += daytab[leap][i];
    return day;
}
/* month_day: set month, day from day of year */
void month_day_check(int yearday, int leap){
    if(((yearday <= 0 || yearday > 365) && leap == 0 )||((yearday <= 0 || yearday > 366) && leap == 1 )){
        printf("yearday out of range");
    }
}
void month_day(int year, int yearday, int *pmonth, int *pday){
    
    int i, leap;
    leap = (year%4 == 0 && year%100 != 0) || year%400 ==  0;
    month_day_check(yearday, leap);
    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;
    printf("\nmonth/day: %d/%d\n", *pmonth, *pday);
    
}

int main(void){
    int m, d;
    printf("day:%d\n", day_of_year(2024, 11, 3));
    month_day(2024, 308, &m, &d);
}
