//Zastosowano flagi:  -Wall -pedantic -Wextra -Werror -std=c99
#include <stdio.h>
#include <ctype.h>
#include <string.h>

enum ArgumentType {CHAR, CHARS, INT, DOUBLE};

void printArgumentInTheMiddle(const void*, enum ArgumentType,const unsigned);
void printChar(const void*, const unsigned);
void printChars(const void*, const unsigned);
void printInt(const void*, const unsigned);
void printDouble(const void*, const unsigned);

int main()
{
    const char* a = "testowy napis";
    const char b = 99;
    const int c = 2543733;
    const double d = 210.004;
    const unsigned width = 14;

    const void *argument=&a;
    printArgumentInTheMiddle(argument,CHARS,width);

    argument = &b;
    printArgumentInTheMiddle(argument,CHAR,width);

    argument = &c;
    printArgumentInTheMiddle(argument,INT,width);

    argument = &d;
    printArgumentInTheMiddle(argument,DOUBLE,width);

    return 0;
}

void printArgumentInTheMiddle(const void* argument, enum ArgumentType type,const unsigned width)
{
    if(!argument){
        printf("\n");
    }
    if(type == CHAR){
        printChar(argument, width);
    }
    else if(type == CHARS){
        printChars(argument, width);
    }
    else if(type == INT){
        printInt(argument, width);
    }
    else if(type == DOUBLE){
        printDouble(argument, width);
    }
}

void printChar(const void* argument, const unsigned width)
{
    char argumentToPrint = *(char*)argument;
    if (!(isprint(argumentToPrint))){
        printf("\n");
    }
    else{
        if(width % 2 == 1){
            printf("%*c%c\n", (width-1) / 2, ' ', argumentToPrint);
        }
        else{
            printf("%*c%c\n", (width/2-1), ' ', argumentToPrint);
        }
    }
}

void printChars(const void* argument, const unsigned width)
{
    char* argumentToPrint = *(char**)argument;
    unsigned argumentLength = strlen(argumentToPrint);
    if(argumentLength>=width){
        printf("%s\n",argumentToPrint);
    }
    else if((width-argumentLength)%2 == 1){
        printf("%*c%s\n",(width-argumentLength-1)/2,' ',argumentToPrint);
    }
    else{
        printf("%*c%s\n",((width-argumentLength)/2),' ', argumentToPrint);
    }
}

void printInt(const void* argument, const unsigned width)
{
    int argumentToPrint = *(int*)argument;
    char sArgument[128];
    snprintf(sArgument, 128, "%d", argumentToPrint);
    unsigned argumentLength = strlen(sArgument);
    if(argumentLength >= width){
        printf("%s\n", sArgument);
    }
    else if((width-argumentLength) % 2 == 1){
        printf("%*c%s\n", (width-argumentLength-1)/2, ' ', sArgument);
    }
    else{
        printf("%*c%s\n", ((width-argumentLength) / 2), ' ', sArgument);
    }
}

void printDouble(const void* argument, const unsigned width)
{
    double argumentToPrint = *(double*)argument;
    char sArgument[128];
    snprintf(sArgument,128,"%f",argumentToPrint);
    unsigned argumentLength = strlen(sArgument);
    unsigned decimalPlaces = 2;
    for(unsigned i = 1; i <=argumentLength;++i){
        if(sArgument[i]=='.'){
            argumentLength=i+3;
            if(sArgument[i+1]=='0'){
                if(sArgument[i+2]=='0'){
                    decimalPlaces = 0;
                    argumentLength=i+1;
                }

            }
            else if(sArgument[i+2]=='0'){
                    decimalPlaces = 1;
                    argumentLength=i+2;
                }
            break;
            }
        }
    if(argumentLength>=width){
        printf("%.*f\n",decimalPlaces,argumentToPrint);
    }
    else if((width-argumentLength)%2 == 1){
        printf("%*c%.*f\n",(width-argumentLength-1)/2,' ',decimalPlaces,argumentToPrint);
    }
    else{
        printf("%*c%.*f\n",((width-argumentLength)/2),' ',decimalPlaces,argumentToPrint);
    }
}
