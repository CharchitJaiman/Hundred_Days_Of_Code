/*
Write a program to calculate electricity bill based on units consumed with these rates: 
First 100 units at ₹5/unit 
Next 100 units at ₹7/unit 
Next 100 units at ₹10/unit 
Above at ₹12/unit
*/

#include <stdio.h>

int main(void) {
    int units;
    if (scanf("%d", &units) != 1) {
        return 1;
    }
    if (units < 0) {
        return 1;
    }
    long long bill;
    if (units <= 100) {
        bill = 5 * units;
    } else if (units <= 200) {
        bill = 500 + 7 * (units - 100);
    } else if (units <= 300) {
        bill = 1200 + 10 * (units - 200);
    } else {
        bill = 2200 + 12LL * (units - 300);
    }
    printf("Bill: ₹%lld\n", bill);
    return 0;
}
