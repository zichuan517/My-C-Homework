#include <stdio.h>
#include <string.h>

int c = 0;

struct contact{
    char name[20];
    char phone[20];
    char wechat[20];
    char qq[20];
};

void input(struct contact p[]){
    int n;
    printf("待输入的联系人数量:");
    scanf("%d",&n);
    printf("输入4个联系人信息(姓名 手机号 微信号 QQ号):\n");
    for (int i=0; i<n; i++){
        scanf("%s%s%s%s",p[c+i].name,p[c+i].phone,p[c+i].wechat,p[c+i].qq);
    }
    c += n;
}

void display(struct contact p[]){
    for (int i=0; i<c; i++){
        printf("%s %s %s %s\n", p[i].name, p[i].phone, p[i].wechat, p[i].qq);
    }
}

void add(struct contact p[]){
    scanf("%s%s%s%s",p[c].name,p[c].phone,p[c].wechat,p[c].qq);
    printf("输入待添加的联系人信息(姓名 手机号 微信号 QQ号):\n");
    c ++;
}

void search(struct contact p[]){
    int t;
    char info[20];
    printf("输入查找方式(1-姓名,2-手机号,3-微信号,4-QQ号)和联系人信息:");
    scanf("%d %s", &t, info);
    
    for (int i=0; i<c; i++){
        int found = 0;
        switch(t){
            case 1: 
                if (!strcmp(p[i].name, info)) {
                    printf("%s %s %s %s\n", p[i].name, p[i].phone, p[i].wechat, p[i].qq);
                    found = 1;
                }
                break;
             case 2: 
                if (!strcmp(p[i].phone, info)) {
                    printf("%s %s %s %s\n", p[i].name, p[i].phone, p[i].wechat, p[i].qq);
                    found = 1;
                }
                break;
            case 3: 
                if (!strcmp(p[i].wechat, info)) {
                    printf("%s %s %s %s\n", p[i].name, p[i].phone, p[i].wechat, p[i].qq);
                    found = 1;
                }
                break;  
            case 4: 
                if (!strcmp(p[i].qq, info)) {
                    printf("%s %s %s %s\n", p[i].name, p[i].phone, p[i].wechat, p[i].qq);
                    found = 1;
                }
                break;                                   
        }
    if (found) 
        break;
    }
}

void save(struct contact p[],const char *abook) {
    FILE *file = fopen(abook, "w");
    for (int i = 0; i < c; i++) {
        fprintf(file, "%s %s %s %s\n",p[i].name, p[i].phone, p[i].wechat, p[i].qq);
    }
    fclose(file);
    printf("已存入文件abook.txt\n");
}

int main(){
    int t;
    struct contact p[100];
    while(1){
        printf("选择操作(1-输入,2-显示,3-添加,4-查找,5-存入文件,0-退出):");
        scanf("%d", &t);
        if (!t)
            break;
        else if (t == 1){
            input(p);
        }            
        else if (t == 2){
            display(p);
        }
        else if (t == 3){
            add(p);
        }
        else if (t == 4){
            search(p);
        }
        else if (t == 5){
            save(p, "abook.txt");
        }
    }
    return 0;
}