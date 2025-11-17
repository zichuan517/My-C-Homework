#include <stdio.h>
#include <math.h>

void decimalReverse(unsigned decimal){
    if (decimal/10 == 0){
        printf("%d", decimal);
        return;
    }
    else{
        printf("%d", decimal%10);
        decimal /= 10;
        decimalReverse(decimal);
    }
}

int main(){
    int decimal;
    scanf("%d", &decimal);
    printf("%c", decimal>=0?' ':'-');
    decimalReverse(fabs(decimal));
    return 0;
}