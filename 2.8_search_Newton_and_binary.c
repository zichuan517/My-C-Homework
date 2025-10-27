#include <stdio.h>
#include <math.h>
int main()
{
    float a3,a2,a1,a0,x,x0,x1,e,low,high,mid;
    int c0=0,c1=0;
    
    scanf("%f%f%f%f",&a3,&a2,&a1,&a0);
    scanf("%f",&e);
    scanf("%f",&x);
    scanf("%f%f",&low,&high);

    while(1) {
        if (fabs(x - x0) < e)
            break;
        x0 = x;
        x = x0 - (a3*x0*x0*x0 + a2*x0*x0 + a1*x0 + a0) / (3*a3*x0*x0 + 2*a2*x0 + a1);
        c0 += 1;
}
    printf("%f\n",x0);
    printf("%d\n",c0);

    while(1){
        mid = (high + low)/2;    
        if (fabs(high-low)<e)
            break;
        if ((a3*mid*mid*mid + a2*mid*mid + a1*mid + a0)*(a3*high*high*high + a2*high*high + a1*high + a0)<=0)
            low = mid;
        else
            high = mid;
        c1 += 1;    
        x1 = high;
        }
    printf("%f\n",x1);
    printf("%d\n",c1);
    
    return 0;
}