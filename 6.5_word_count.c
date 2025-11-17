#include <stdio.h>
#include <ctype.h>

int check_char(char c) {
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

int main() {
    int state = 0, input = 0;
    int count = 0;
    char ch;

    while ((ch = getchar()) != '#') {
        input = check_char(ch);
        
        if (state == 0 && input == 1) {
            state = 1;
            count++;
        }
        else if (state == 1 && input == 0) {
            state = 0;
        }
    }
    
    printf("%d\n", count);
    return 0;
}