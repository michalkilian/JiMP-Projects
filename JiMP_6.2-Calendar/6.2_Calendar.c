#include <stdio.h>
#include <time.h>


int main(void){

    time_t timer;
    struct tm* tm_info;
    char month[3];

    time(&timer);
    tm_info = localtime(&timer);

    strftime(month,3, "%m",tm_info);

    int numberOfDays = 0;

    if(month == "1" || month == "3" || month == "5" || month == "7" || month == "8" || month == "10" || month == "12" || ){
        numberOfDays = 31
    }





    return 0;
}
