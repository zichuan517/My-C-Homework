/*
int factorial(int n){
    if (!n){
        return 1;
    }
    return n*factorial(n-1);
}

int C(int n , int m){
    return (factorial(n)/(factorial(m) * factorial(n-m)));
}
*/

/*
int pascal(int x, int y) {
    int triangle[x][x];

    for (int i = 0; i < x; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                triangle[i][j] = 1;
            }
            else {
                triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
            }
        }
    }

    return triangle[x-1][y-1];
}
*/


#include <stdio.h>

int pascal(int x, int y){
    if (y == 1 || y == x){
        return 1;
    }
    else{
        return pascal(x-1,y)+pascal(x-1,y-1);
    }
}
int main() {
    int x,y;
    scanf("%d%d", &x, &y);
    printf("%d", pascal(x,y));    
    return 0;
}