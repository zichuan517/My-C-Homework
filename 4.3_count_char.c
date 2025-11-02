#include <stdio.h>
int main() {
    int count[6] = {0};
    char c;
    
    while ((c = getchar()) != EOF) {
        if (c >= 'A' && c <= 'Z') {
            count[0]++; 
        } else if (c >= 'a' && c <= 'z') {
            count[1]++;
        } else if (c >= '0' && c <= '9') {
            count[2]++;
        } else if (c == ' ') {
            count[3]++;
        } else if (c < 32) {
            count[4]++;
        } else {
            count[5]++; 
        }
    }
    
    printf("%d个大写字母,%d个小写字母,%d个数字,%d个空格,%d个制表符,%d个其它字符\n",
           count[0], count[1], count[2], count[3], count[4], count[5]);
    
    return 0;
}