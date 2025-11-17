#include <stdio.h>

void des2sn(int decimal, int radix){
    if (decimal == 0) {
        return;
    }
    des2sn(decimal / radix, radix);
    
    int t = decimal % radix;
    char r = (t>=0 && t<=9)? t + '0' : ('A'+t-10);
    printf("%c", r);
}

    
int main(){
    int decimal,radix;
    scanf("%d%d", &decimal, &radix);
    des2sn(decimal, radix);
    return 0;
}