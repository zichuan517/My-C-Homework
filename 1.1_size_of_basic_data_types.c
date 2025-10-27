#include <stdio.h>
int main()
{
    printf("sizeof(int)=%d\n",sizeof(int));
    printf("sizeof(char)=%d\n",sizeof(char));    
    printf("sizeof(float)=%d\n",sizeof(float));
    printf("sizeof(double)=%d\n",sizeof(double));
    printf("sizeof(long)=%d\n",sizeof(long));
    printf("sizeof(unsigned)=%d\n",sizeof(unsigned));
    printf("%d\n",sizeof(short));
    printf("%d\n",sizeof(long long));
    printf("%d\n",0100);
    printf("%d\n",sizeof(long double));    
    return 0;
}