#include "./include/change.h"

#include <stdio.h>

int main(int, char**){
    char str[1024];
    str[0] = '\0';
    double input;

    printf("Hello, this is a change generator!\n");
    printf("Insert the amount you want to convert to change.\n");
    printf("Anything after the second decimal point will be discarded.\n");
    do {
        printf("Insert Amount: ");
        fflush(stdout);
        scanf("%lf", &input);
        if (input < 0) {
            printf("Only non-negative values are accepted. Please provide a valid value.\n");     
        }
    } while (input  < 0);

    int amount = input * 100;
    if (amount !=  0) {
        getDenomination(amount, str);
        printf("This can be converted to: %s\n", str);
    } else {
        printf("No change is required for this value.\n");
    }
    
    return 0;
}
