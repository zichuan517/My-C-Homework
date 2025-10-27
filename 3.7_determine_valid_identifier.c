#include <stdio.h>
#include <string.h>
int check(char id[], int n){
    if (id[0]>='0' && id[0]<='9')
        return 0;
    for (int j=0; j<n; j++){
        if (!((id[j]>='0' && id[j]<='9') || (id[j]>='a' && id[j]<='z') || (id[j]>='A' && id[j]<='Z') || id[j]=='_'))
            return 0;
    }
    return 1;
}
int main(){
    while(1){
        char id[50]={0};
        printf("输入一串字符:");
        scanf("%s",id);        
        for (int i=0; i<7; i++){
            if (i == 6){
                return 0;
            }
            if (id[i] != '0')
                break;
        }
        if (check(id,strlen(id)))
            printf("\"%s\"是合法的C标识符\n",id);
        else
            printf("\"%s\"不是合法的C标识符\n",id);
    }
}