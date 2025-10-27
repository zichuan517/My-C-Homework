#include <stdio.h>
int main()
{
    int a,b;
    double x,y;
    printf("%.2f\n",3.5+1/2+56%10);
    scanf("%d",&a);
    printf("%d\n",a++*1/3);
    scanf("%d%lf%lf",&a,&x,&y);
    printf("%.2f\n",x+a%3*(int)(x+y)%2/4);
    scanf("%d%d%lf%lf",&a,&b,&x,&y);    
    printf("%.2f\n",(float)(a+b)/2 + (int)x%(int)y);
    return 0;
}