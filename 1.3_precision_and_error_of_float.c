#include <stdio.h>
int main()
{
    float a=1.75,b=1.35;
    float c=a+b;
    printf("%.6f,%.7f\n",c,c);
    a=1.234567e10;
    b=20;
    c=a+b;
    printf("%f,%f",a,c);
    return 0;
}