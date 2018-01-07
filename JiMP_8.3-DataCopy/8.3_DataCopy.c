//Zastosowano flagi:  -Wall -pedantic -Wextra -Werror -std=c99

#include <stdio.h>
#include <string.h>

long long copyArgumentAndPrintCharByCharReturningSumOfArguments(void*,size_t);

int main(){

    char a[8] = "acfilotv";
    printf("%x\n",copyArgumentAndPrintCharByCharReturningSumOfArguments(&a,sizeof a));
    char b = 79;
    printf("%x\n",copyArgumentAndPrintCharByCharReturningSumOfArguments(&b,sizeof b));
    int c = 7;
    printf("%x\n",copyArgumentAndPrintCharByCharReturningSumOfArguments(&c,sizeof c));
    float d = 7.5;
    printf("%x",copyArgumentAndPrintCharByCharReturningSumOfArguments(&d,sizeof d));
    return 0;
}

long long copyArgumentAndPrintCharByCharReturningSumOfArguments(void* data, size_t sizeOfData){
    long long sum = 0;
    unsigned char dataCopy[128] = {0};
    memcpy(dataCopy,data,sizeOfData);
    int numberOfElements = sizeOfData/sizeof(dataCopy[0]);
    for(int i = 0; i < numberOfElements;++i){
        printf("%x ",(unsigned char)dataCopy[i]);
        sum+=(unsigned char)dataCopy[i];
    }
    printf("\n");
    return sum;
}
