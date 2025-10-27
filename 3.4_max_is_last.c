#include <stdio.h>
int main()
{
    int n,max;
    int i=1;
    int c=0;
    int arr[100]={114514};

    printf("有几个整数？");
    scanf("%d",&n);
    printf("输入%d个整数:",n);
    printf("最大数位于最后:");

    for (i=0; i<n; i++)
        scanf("%d",&arr[i]);
    
    max = arr[0];
    for (i=1;i<n;i++){
        if (arr[i]>max){
            c = i;
            max = arr[i];
        }
    }
    
    for(i=0; i<n; i++){
        if (i==c)
            continue;
        printf("%d ",arr[i]);
    }
        printf("%d ",max);

    return 0;
}