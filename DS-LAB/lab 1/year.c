/*WAP to convert number of days into year, week & days [e.g. 375 days mean 1 
year, 1 week and 3 days].*/

#include <stdio.h>
void main() {
    int total_days, years, weeks, remaining_days;

    printf("Enter the number of days: ");
    scanf("%d", &total_days);

    years = total_days / 365;
    weeks = (total_days % 365) / 7;
    remaining_days = (total_days % 365) % 7;

    printf("%d days means %d year, %d week(s) and %d day(s)\n", 
           total_days, years, weeks, remaining_days);
}
