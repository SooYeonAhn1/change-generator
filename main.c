#include "./include/change.h"

#include <stdio.h>

int main(int, char**){
    printf("Hello, this is a change generator!\n");
    printf("Insert the amount you want to convert to change.\n");
    printf("Anything after the second decimal point will be discarded.\n");
    setAmount();
    return 0;
}
