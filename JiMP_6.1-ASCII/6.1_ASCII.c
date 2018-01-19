//Zastosowano flagi:  -Wall -pedantic -Wextra -Werror -std=c99
#include <stdio.h>

void asciiPrinting(unsigned int);

int main(void)
{
    for(int i = 32; i < 127; ++i){
        asciiPrinting(i);
    }

    return 0;
}

void asciiPrinting(unsigned int n)
{
    unsigned char ascii = n;
    printf("%c --- %d\n",ascii,n);
}
