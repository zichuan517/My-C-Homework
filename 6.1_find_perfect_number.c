#include <stdio.h>

int factorsNum = 0;
int isPerfectNumber(int num, int factorsList[]);
void print(int perfectNumber, int factorsList[]);

int main(){
    int i, upperNumber, factorList[100];
    scanf("%d", &upperNumber);
    
    for (int i = 1; i <= upperNumber; i++){
        if (isPerfectNumber(i, factorList)){
            print(i, factorList);
        }
    }

    return 0;
}

int isPerfectNumber(int num, int factorsList[]){
    int i, j = 0, sum = 0;
    for (int i = 1; i < num; i++){
        if (num % i == 0){
            sum += i;
            factorsList[j++] = i;
        }
    }
    if (num == sum){
        factorsNum = j;
        return 1;
    }
    return 0;
}

void print(int perfectNumber, int factorsList[]){
    int i;
    printf("%d:", perfectNumber);
    for(i = 0; i < factorsNum; i++){
        printf(" %d", factorsList[i]);
    }
    printf("\n");
}