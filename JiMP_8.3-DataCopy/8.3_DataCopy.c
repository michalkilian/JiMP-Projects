//Zastosowano flagi:  -Wall -pedantic -Wextra -Werror -std=c99

#include <stdio.h>
#include <string.h>

long long copyArgumentAndPrintCharByCharReturningSumOfArguments(const void*, size_t);

int main()
{
    const char stringArgument[8] = "acfilotv";
    printf("%x\n",copyArgumentAndPrintCharByCharReturningSumOfArguments(&stringArgument,sizeof stringArgument));

    const char charArgument = 79;
    printf("%x\n",copyArgumentAndPrintCharByCharReturningSumOfArguments(&charArgument,sizeof charArgument));

    const int intArgument = 7;
    printf("%x\n",copyArgumentAndPrintCharByCharReturningSumOfArguments(&intArgument,sizeof intArgument));

    const float floatArgument = 7.5;
    printf("%x",copyArgumentAndPrintCharByCharReturningSumOfArguments(&floatArgument,sizeof floatArgument));

    return 0;
}

long long copyArgumentAndPrintCharByCharReturningSumOfArguments(const void* data, size_t sizeOfData)
{
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
