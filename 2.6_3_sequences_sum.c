#include <stdio.h>
#include <math.h>
int main()
{
    int i=1;
    int s1=0;
    int s2=0;
    float s3=0;
    int n;    
    scanf("%d",&n);
    if (n<10)
        return 1;

    for (;i<=n;i++){
        s1 += i;
        s2 += 2*i-1;
        s3 += pow(-1,i+1)/(float)i;
    }
    printf("for:s1=%d,s2=%d,s3=%f\n",s1,s2,s3);

    i=1;s1=0;s2=0;s3=0;    
    while(i<=n){
        s1 += i;
        s2 += 2*i-1;
        s3 += pow(-1,i+1)/(float)i;
        i++;
    }
    printf("while:s1=%d,s2=%d,s3=%f\n",s1,s2,s3);   

    i=1;s1=0;s2=0;s3=0;   
    do{
        s1 += i;
        s2 += 2*i-1;
        s3 += pow(-1,i+1)/(float)i;
        i++;
    }
    while (i<=n);
    printf("do while:s1=%d,s2=%d,s3=%f\n",s1,s2,s3);    
    
    return 0;
}