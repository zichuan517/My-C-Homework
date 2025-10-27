#include <stdio.h>

void replace(char t[], int j) {
    for(int i = 0; i < j; i++) {
        if (t[i] >= '0' && t[i] <= '9')
            t[i] = '*';
    }
    for (int i = 0; i < j; i++)
        printf("%c", t[i]);    
}

void reverse(char t[], int j) {
    for (int i = j - 1; i >= 0; i--)
        printf("%c", t[i]);
}

int main() {
    char t[50] = {0};
    
    for (int i = 0; i < 3; i++) {
        char ch;  
        int j=0;      
        printf("输入一个字符串:");
        for(; (ch = getchar()) != '\n'; j++) {
            t[j] = ch;
        }

        printf("正序:");
        replace(t, j);
        printf("\n");
        printf("逆序:");
        reverse(t, j);
        printf("\n");        
    }
    return 0;
}