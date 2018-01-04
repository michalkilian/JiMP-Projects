//Zastosowano flagi:  -Wall -pedantic -Wextra -Werror -std=c99
#include <stdio.h>
#include <ctype.h>
#include <string.h>

enum ArgumentType {CHAR, CHARS, INT, DOUBLE};

int printArgumentInTheMiddle(void*, enum ArgumentType,unsigned);

int main(){

    char* a = "testowy napis";
    char b = 99;
    int c = 2543733;
    double d = 210.004;
    unsigned width = 14;

    void *argument=&a;
    printArgumentInTheMiddle(argument,CHARS,width);

    argument = &b;
    printArgumentInTheMiddle(argument,CHAR,width);

    argument = &c;
    printArgumentInTheMiddle(argument,INT,width);

    argument = &d;
    printArgumentInTheMiddle(argument,DOUBLE,width);

    return 0;
}

int printArgumentInTheMiddle(void* argument, enum ArgumentType type,unsigned width){
    if(!argument){
        printf("\n");
        return 0;
    }
    unsigned argumentLength = 0;

    if(type == CHAR){
        char argumentToPrint = *(char*)argument;
        if (!(isprint(argumentToPrint))){
            printf("\n");
        }
        else{
            if(width%2 == 1){
                printf("%*c%c\n",(width-1)/2,' ',argumentToPrint);
            }
            else{
                printf("%*c%c\n",(width/2-1),' ', argumentToPrint);
            }
        }
    }
    else if(type == CHARS){
        char* argumentToPrint = *(char**)argument;
        argumentLength = strlen(argumentToPrint);
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
    else if(type == INT){
        int argumentToPrint = *(int*)argument;
        char sArgument[128];
        snprintf(sArgument,128,"%d",argumentToPrint);
        argumentLength = strlen(sArgument);
        if(argumentLength>=width){
            printf("%s\n",sArgument);
        }
        else if((width-argumentLength)%2 == 1){
            printf("%*c%s\n",(width-argumentLength-1)/2,' ',sArgument);
        }
        else{
            printf("%*c%s\n",((width-argumentLength)/2),' ', sArgument);
        }
    }
    else if(type == DOUBLE){
        double argumentToPrint = *(double*)argument;
        char sArgument[128];
        snprintf(sArgument,128,"%f",argumentToPrint);
        argumentLength = strlen(sArgument);
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

    return 0;
}
