#include <stdio.h>

struct T {
    int h; 
    int m; 
    int s;  
};

int check(struct T time) {
    if ((time.h < 0 || time.h > 23) ||
        (time.m < 0 || time.m > 59) ||
        (time.s < 0 || time.s > 59))
        return 0;
    else
        return 1;
}


int main()
{
    struct T ori;
    struct T adj;
    int delta;


    while(1){
        printf("请输入时,分,秒:");
        scanf("%d,%d,%d",&ori.h,&ori.m,&ori.s);
        if (check(ori))
            break;
        else
            printf("输入时间不符合要求，请重新输入\n");
        }

    while(1){
        printf("请输入调整时间的秒数:");
        scanf("%d",&delta);
        if (!delta)
            return 0;

        int t = 3600*ori.h + 60*ori.m + ori.s + delta;
        t = (t % 86400 + 86400) % 86400;
        adj.h = t / 3600;
        adj.m = t % 3600 / 60;
        adj.s = t % 60;
    
        printf("%02d-%02d-%02d调整%02d秒后为:%02d-%02d-%02d\n",ori.h,ori.m,ori.s,delta,adj.h,adj.m,adj.s);
    }

    return 0;
}