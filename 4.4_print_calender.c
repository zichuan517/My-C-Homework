#include <stdio.h>

int leap(int year){
    if (year % 4 ==0 && year % 100 != 0 || year %400 ==0)
        return 1;
    else
        return 0;
}

void month_day(int day[], int year){
    int base_day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30 ,31, 30 ,31};
    for (int i=0; i<12; i++){
        day[i] = base_day[i];
    }
    if (leap(year))
        day[1] = 29;
}

void first_day(int day[], int first[], int init){
    first[0] = init;
    for (int i=0; i<11; i++){
        first[i+1] = (first[i] + day[i]) % 7;
        if (first[i+1] == 0) {
            first[i+1] = 7;
        }
    }
}

void body(int year, int first[], int day[]){
    for (int i=0; i<12; i++){
        printf("\n%d年%d月\n",year,i+1);
        printf("星期一 星期二 星期三 星期四 星期五 星期六 星期日\n");
        int temp = first[i];
        for (int j=1; j<temp; j++){
            printf("       ");
        }
            for (int k=1; k<=day[i]; k++){
                printf("%4d   ",k);

            if ((temp + k - 1) % 7 == 0 && k != day[i]) {
                printf("\n");
            }
        }
        printf("\n");
    }
}



int main(){
    int year;
    int init;
    int first[12];
    int day[12];

    printf("输入一年的年份和1月1日是星期几(1~7):");
    scanf("%d%d",&year,&init);
    
    month_day(day, year);
    first_day(day, first, init);

    body(year, first, day);

    return 0;
}