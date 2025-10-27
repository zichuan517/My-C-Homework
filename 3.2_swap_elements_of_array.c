#include <stdio.h>
int main()
{
    int a[100];
    int n;
    int i,j,t;
    printf("有几个数(1~100):");
    scanf("%d",&n);
    if (n>100 | n<1){
        printf("元素个数超出范围");
        return 0;
    }
    printf("输入%d个数:",n);
    for (i=0;i<n;i++)
        scanf("%d",&a[i]);
    
    for (i=0;i<n/2;i++){
        t=a[i];
        a[i]=a[n-1-i];
        a[n-1-i]=t;
    }
    printf("逆序存储后的数组元素依次为:\n");
    for (i=0;i<n;i++)
        printf("%d ",a[i]);
    
    while(1){
        printf("\n输入要交换的两个元素位置(0~%d):",n-1);
        scanf("%d%d",&i,&j);
        if (i>=0 & i<n & j>=0 & j<n){
            a[i]+=a[j];
            a[j]=a[i]-a[j];
            a[i]-=a[j];
        }
        else
            break;
        for (i=0;i<n;i++)
            printf("%d ",a[i]);
    }
    return 0;
}