#include <stdio.h>
#include <string.h>

struct Candidate{
    int num;
    char name[10];
    char gender;
    unsigned vote;
};

int main()
{
    int n;
    struct Candidate p[50];
    int cate;
    int num;
    char name[10];

    printf("有几位候选人:");
    scanf("%d",&n);
    printf("输入%d位候选人信息(编号,姓名,性别):\n",n);
    
    for (int i=0; i<n; i++){
        scanf("%d %s %c",&p[i].num,p[i].name,&p[i].gender);
        p[i].vote = 0;
    }
    printf("开始投票:\n");

    while(1){

        printf("投票(0 编号,1 姓名,10 结束):\n");
        scanf("%d",&cate);

        if (cate == 10){
            break;
        }

        else if (cate == 0){
            scanf("%d",&num);
            for (int j=0; j<n; j++){
                if (p[j].num == num){
                    p[j].vote += 1;
                    break;
                }
            }    
        }

        else if (cate == 1){
            scanf("%s",name);
            for (int k=0; k<n; k++){
                if (!strcmp(p[k].name, name)){
                    p[k].vote += 1;
                    break;
                }
            }
        }
    }
    
    printf("投票结果:\n");
    for (int t=0; t<n; t++){
        printf("%d,%s,%c:%d票\n",p[t].num,p[t].name,p[t].gender,p[t].vote);
    }

    return 0;
}