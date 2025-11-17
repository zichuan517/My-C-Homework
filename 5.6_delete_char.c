#include <stdio.h>

void getString(char* t){
    int i = 0;
    char c = getchar();
    while (c != '\n'){
        t[i] = c;
        c = getchar();
        i++;
    }
    t[i] = '\0';    
}

void deleteCharInString(char* t, char c){
    int i = 0, j = 0;
    while (t[i]){
        if (t[i] != c){
            t[j] = t[i];
            j++;
        }
        i++;
    }
    t[j] = '\0';
}

int main(){
    char t[50];
    getString(t);
    char c = getchar();
    deleteCharInString(t, c);
    printf("%s", t);
    return 0;
}