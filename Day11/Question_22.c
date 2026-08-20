/*
Write a program to find profit or loss percentage given cost price and selling price.
*/

#include <math.h>
#include <stdio.h>

int main(void) {
    double cost, price;
    if (scanf("%lf %lf", &cost, &price) != 2) {
        return 1;
    }
    if (cost <= 0 || price < 0) {
        return 1;
    }
    if (price == cost) {
        puts("No Profit No Loss");
    } else {
        printf("%s %g%%\n", price > cost ? "Profit" : "Loss", 100 * fabs(price - cost) / cost);
    }
    return 0;
}
