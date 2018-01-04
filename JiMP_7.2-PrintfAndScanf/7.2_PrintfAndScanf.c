#include <stdio.h>
#include <stdarg.h>
#include <string.h>

void printfAndScanf(char*,...);

int main(void){

    printfAndScanf("testowy napis");
    int a = 2;
    int b = 0;
    printfAndScanf("Podaj krotszy bok prostokata: %dteraz podaj dluzszy: %d",&a,&b);
    printf("%d %d",a,b);

    return 0;
}

void printfAndScanf(char* sentence, ...){

    int lenght = strlen(sentence);

    va_list v1;
    va_start(v1,sentence);
    int* val;

    for(int i = 0; i <lenght;++i){
        if(sentence[i]=='%' && sentence[i+1]=='d'){
            i++;
            val = va_arg(v1,int*);
            scanf("%d",val);
        }
        else{
            printf("%c",sentence[i]);
        }
    }
    va_end (v1);
    printf("\n");
}
