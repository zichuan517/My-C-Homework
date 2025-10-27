#include <stdio.h>

int check(int n) {
    if (n < 3 || n > 45)
        return 0;
    else
        return 1;
}

void input(int *n) {
    printf("输入Fibonacci数列的项数:");
    scanf("%d", n);
    if (!check(*n)) {
        printf("项数超出范围，请重新输入\n");
        input(n);
}
}
int main() {
    int n;
    int a[45] = {0, 1};

    for (int i = 0; i < 43; i++) {
        a[i + 2] = a[i + 1] + a[i];
    }

    input(&n);

    for (int j = 0; j < n; j++) {
        printf("%10d", a[j]);
        if ((j + 1) % 8 == 0 && j != 0)
            printf("\n");
    }
    return 0;
}