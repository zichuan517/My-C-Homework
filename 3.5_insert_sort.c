#include <stdio.h>

void last_sort(float t[], int r) {
    for (int i = r; i > 0; i--) {
        if (t[i] < t[i - 1]) {
            float temp = t[i];
            t[i] = t[i - 1];
            t[i - 1] = temp;
        } 
        else
            break;
    }
}

int main() {
    float a[20] = {0};
    printf("从小到大地输入10个数:");
    for (int i = 0; i < 10; i++) {
        scanf("%f", &a[i]);
    }
    
    for (int i = 10; i < 15; i++) {
        printf("输入要插入的数据:");
        scanf("%f", &a[i]);
        last_sort(a, i);
        printf("目前有%d个元素:", i + 1);
        for (int j = 0; j < i + 1; j++) {
            printf("%8.3f", a[j]);
        }
        printf("\n");
    }
    return 0;
}
