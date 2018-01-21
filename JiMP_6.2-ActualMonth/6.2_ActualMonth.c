//Zastosowano flagi:  -Wall -pedantic -Wextra -Werror -std=c99
#include <stdio.h>
#include <time.h>
#include <string.h>

int calculateDaysInMonth(int,int);
int firstDay(int,int);
void calendarPrinter(int, int);

int main(void)
{
    time_t rawtime;
    struct tm * ptr_time;
    time (&rawtime);
    ptr_time = localtime(&rawtime);

    int month = ptr_time->tm_mon+1;
    int year = ptr_time->tm_year+1900;
    int daysInMonth = calculateDaysInMonth(month,year);
    int dayOfMonth = ptr_time->tm_mday;
    int dayOfWeek = ptr_time->tm_wday;
    int firstDayOfMonth = firstDay(dayOfMonth,dayOfWeek);
    printf("%d.%d.%d", dayOfMonth,month,year);
    calendarPrinter(daysInMonth, firstDayOfMonth);
    return 0;
}

int firstDay(int dayOfMonth,int dayOfWeek)
{
    int firstDay = dayOfWeek;
    for(int i = dayOfMonth; i > 1; --i){
        firstDay--;
        if(firstDay==0){
            firstDay = 7;
        }
    }
    return firstDay;
}

int calculateDaysInMonth(int month,int year)
{
    int calculateDaysInMonth = 0;
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
        calculateDaysInMonth = 31;
    }
    else if( month == 2) {
        if(year % 4 != 0){
            calculateDaysInMonth = 28;
        }
        else if(year % 400 == 100 || year % 400 == 200 || year % 400 == 300){
            calculateDaysInMonth = 28;
        }
        else {
            calculateDaysInMonth = 29;
        }
    }
    else calculateDaysInMonth = 30;
    return calculateDaysInMonth;
}

void calendarPrinter(int calculateDaysInMonth, int firstDayOfMonth)
{
    printf("\nMon Tue Wed Thu Fri Sat Sun\n");
    for(int i = 1; i < firstDayOfMonth; ++i){
        printf("    ");
    }
    for (int i = 1; i <= calculateDaysInMonth; ++i){
        if(i<10){
            printf("0");
        }
        printf("%d  ", i);
        if((i+firstDayOfMonth-1) % 7 == 0) printf("\n");
    }
}
