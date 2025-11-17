#include <stdio.h>

unsigned long sums(int digit, int level){
    unsigned long sum = 0, item = digit;
    while(level--){
        sum += item;
        item = digit + 10 * item;
    }
    return sum;
}

int main(){
    int digit, level;
    unsigned long ssum = 0;
    scanf("%d%d", &digit, &level);
    ssum = sums(digit, level);
    printf("%lu", ssum);
    return 0;
}