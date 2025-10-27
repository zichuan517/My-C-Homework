#include <stdio.h>
int main()
{
    int a,b,c,x,y;
    scanf("%d%d",&b,&c);
    printf("%d\n",b>c&&b==c);

    scanf("%d%d%d",&a,&b,&c);
    printf("%d\n",!(a>b)&&!c||1);

    scanf("%d%d",&a,&b);
    printf("%d\n",!(x=a)&&(y=b)&&0);
    
    scanf("%d%d%d",&a,&b,&c);
    printf("%d\n",!(a+b)+c-1&&b+c/2);

    printf("%d\n",1&&30%10>=0&&30%10<=3);
}