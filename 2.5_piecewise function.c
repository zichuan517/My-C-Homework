#include <stdio.h>
int main()
{
    int a;
    float b;
    
    printf("输入一个整数:");
    scanf("%d",&a);
    if (a < 0 || a >= 30) {
        printf("x输入错误, 要求0<=x<30\n");
        return 1;
    }    
    switch(a/10){
        case 0: printf("x=%d时, y=%d\n",a,a);break;
        case 1: printf("x=%d时, y=%d\n",a,a*a+1);break;
        case 2: printf("x=%d时, y=%d\n",a,a*a*a+a*a+1);break;
    }

    printf("输入一个实数:");
    scanf("%f",&b);
    if (b < 0 || b >= 30) {
        printf("x输入错误, 要求0<=x<30\n");
        return 1;
    }    
    if (b>=0 && b<10)
        printf("x=%f时, y=%f\n",b,b);
    else if (b>=10 && b<20)
        printf("x=%f时, y=%f\n",b,b*b+1);
    else if (b>=20 && b<30)
        printf("x=%f时, y=%f\n",b,b*b*b+b*b+1);
    return 0; 
}   