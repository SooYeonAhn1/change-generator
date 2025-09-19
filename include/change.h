#ifndef CHANGE_H
#define CHANGE_H

// function to set the amount to generate change
void setAmount();

// function that controls the denomination calcualtion flow. Calculated from larger denominations to smaller denominations
void getDenomination(int amount, char str[]);

// function that calculates the change for dollar bills
void getDollars(int * amount, char str[]);

// function that calculates the change for cents
void getCoins(int * amount, char str[]);

#endif /* CHANGE_H */