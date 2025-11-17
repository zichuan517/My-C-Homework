#include <stdio.h>

void string_filter(char* t){
    int i = 0, j = 0, m = 0, n = 0;
    int num[101] = {0};
    char list[101];
    
    if (t[0] != '\0') {
        list[j] = t[0];
        num[j] = 1;
    }
    else {
        return;
    }
    
    for (i = 1; t[i] != '\0'; i++){
        if (t[i] == t[i-1]){
            num[j]++;
            if (num[j] > 9){
                num[j] = 9;
                j++;
                list[j] = t[i];
                num[j] = 1;
            }
        }
        else{
            j++;
            list[j] = t[i];
            num[j] = 1;
        }
    }

    for (m = 0; m <= j; m++){
        if (num[m] == 1){
            t[n] = list[m];
            n++; 
        }
        else {
            t[n] = num[m] + '0';
            n++;
            t[n] = list[m];
            n++;
        }
    }
    t[n] = '\0';
}

int main(){
    char t[101];
    int i = 0;
    char c = getchar();

    while (c != '\n'){
        t[i] = c;
        c = getchar();
        i++;
    }
    t[i] = '\0';

    string_filter(t);

    printf("%s\n", t);

    return 0;
}