#include "../include/change.h"

#include <stdio.h>
#include <string.h>

void setAmount() {
    char str[1024];
    str[0] = '\0';
    double input;

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
}
void getDenomination(int amount, char str[]) {
    if (amount >= 100) {
        getDollars(&amount, str);
    }
    if (amount > 0) {
        getCoins(&amount, str);
    }
    size_t len = strlen(str);
    len -= 2;
    strcpy(str + len, ".");
}

void getDollars(int * amount, char str[]) {
    int dollars[] = {10000, 5000, 2000, 1000, 500, 100};
    int count[6] = {0};
    for (int i = 0; i < 6 && *amount >= 1.0; i++) {
        while (*amount >= dollars[i]) {
            *amount -= dollars[i];
            count[i]++;
        }
    }
    
    char val_to_str[13];
    size_t num_len, len;
    for (int i = 0; i < 6; i++) {
        if (count[i] != 0) {
            sprintf(val_to_str, "%d", count[i]);
            num_len = strlen(val_to_str);
            val_to_str[num_len] = '\0';
            len = strlen(str);
            strncpy(str + len, val_to_str, num_len + 1);
            len = strlen(str);
            strcpy(str + len, " ");
            

            sprintf(val_to_str, "%d", dollars[i] / 100);
            num_len = strlen(val_to_str);
            val_to_str[num_len] = '\0';
            len = strlen(str);
            strncpy(str + len, val_to_str, num_len + 1);
            
            len = strlen(str);
            if (count[i] > 1) {
                strcpy(str + len, " dollar bills, ");    
            } else {
                strcpy(str + len, " dollar bill, ");    
            }
        }
    }
}

void getCoins(int * amount, char str[]) {
    int coins[] = {25, 10, 5, 1};
    int count[4] = {0};
    for (int i = 0; i < 4 && *amount > 0; i++) {
        while (*amount >= coins[i]) {
            *amount -= coins[i];
            count[i]++;
        }
    }
    
    char val_to_str[13];
    size_t num_len, len;
    for (int i = 0; i < 4; i++) {
        if (count[i] != 0) {
            sprintf(val_to_str, "%d", count[i]);
            
            num_len = strlen(val_to_str);
            val_to_str[num_len] = '\0';
            len = strlen(str);
            
            strncpy(str + len, val_to_str, num_len + 1);
            
            len = strlen(str);
            strcpy(str + len, " ");
            len = strlen(str);
            

            switch (i) {
                case 0:
                    strcpy(str + len, "quarter");
                    break;
                case 1:
                    strcpy(str + len, "dime");
                    break;
                case 2:
                    strcpy(str + len, "nickel");
                    break;
                case 3:
                    strcpy(str + len, "penny");
                    break;
            }

            if (count[i] > 1) {
                len = strlen(str);
                if (i == 3) {
                    strcpy(str + len - 1, "ies");
                } else {
                    strcpy(str + len, "s");
                }
            }

            len = strlen(str);
            strcpy(str + len, ", ");
        }
    }
}