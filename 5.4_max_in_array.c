#include <stdio.h>
#define ELE_NUM 10
float findMaxEle(float* t){
    float max = t[0];
    for(int i=1; i < ELE_NUM; i++){
        if (t[i] > max){
            max = t[i];
        }
    }
    return max;
}
int main(){
    int i;
    float ele[ELE_NUM], maxEle = 0.0;
    for(i = 0; i < ELE_NUM; i++){
        scanf("%f", &ele[i]);
    }
    maxEle = findMaxEle(ele);
    printf("%f\n", maxEle);
    return 0;
}