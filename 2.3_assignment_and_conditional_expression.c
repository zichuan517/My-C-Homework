#include <stdio.h>
int main()
{
    int a,b,c;
    scanf("%d%d",&a,&b);
    printf("%d\n",a+=a+b);

    scanf("%d%d%d",&a,&b,&c);
    printf("%d\n",a*=b%c);
    
    scanf("%d%d",&a,&c);
    printf("%d\n",a/=c-a);
    
    scanf("%d",&a);
    printf("%d\n",a+=a-=a*=a);

    scanf("%d%d",&a,&b);
    printf("%d\n",a=(a=++b,a+5,a/5));
    
    scanf("%d%d",&a,&b);
    printf("%d\n",(a>=b>=2)?1:0);    
} 