#include <stdio.h>
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

void reduction(int *a, int *b){
    int t = gcd(*a, *b);
    *a /= t;
    *b /= t;
}

int main(){
    int m,n;
    scanf("%d%d", &m, &n);
    if (m <= 0 || n <= 0){
        printf("分子分母必须为正整数");
        return 0;
    }
    if (gcd(m,n) == 1){
        printf("%d/%d为最简分数", m, n);
    }
    else{
        int x=m;
        int y=n;
        reduction(&m, &n);
        printf("%d/%d=%d/%d", x, y, m ,n);
    }
    return 0;
}
