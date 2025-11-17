#include <stdio.h>
    long func_fac(int n){
        if (!n){
            return 1;
        }
        return n*func_fac(n-1);
    }

    double func_pow(double x, int n){
        double re = 1;
        for (int i = 0; i < n; i++){
            re *= x;
        }
        return re;
    }

    double func_sum(double x, int n){
        double ex = 1;
        for (int i = 0; i <n; i++){
            ex += func_pow(x, i+1) / func_fac(i+1);
        }
        return ex;
    }

    int main(){
        double x, ex;
        unsigned int n;
        scanf("%lf%u", &x, &n);
        while (n > 20){
            printf("please enter a smaller number");
            scanf("%u", &n);
        }        
        ex = func_sum(x, n);
        printf("%f", ex);
        return 0;
    }