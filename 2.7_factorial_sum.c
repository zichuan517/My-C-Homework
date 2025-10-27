#include <stdio.h>
int main()
{
    long long fact_sum=0;
    int n;
    long int fact=1;

    scanf("%dL",&n);
    if (n<1 || n>16)
    {
        printf("输入错误");
        return 1;
    }

    for (int i=1;i<=n;i++){
        for (int j=1;j<=i;j++){
            fact *= j;
        }
        fact_sum += fact;
        fact = 1;
    }
    printf("两层循环结果：%lld\n",fact_sum);

    fact_sum=0;   
    for (int k=1;k<=n;k++){
        fact *= k;
        fact_sum += fact;
    }
    printf("单层循环结果：%lld\n",fact_sum);
  
    return 0;
}
