#include <stdio.h>

struct complex
{
    double real;
    double imag;
};

struct complex complexMult(struct complex c1, struct complex c2){
    struct complex s;
    s.real = c1.real * c2.real - c1.imag * c2.imag;
    s.imag = c1.real * c2.imag + c1.imag * c2.real;
    return s; 
}

int main(){
    struct complex t[2];
    scanf("%lf", &t[0].real);
    scanf("%lfi", &t[0].imag);
    scanf("%lf", &t[1].real);
    scanf("%lfi", &t[1].imag);    
    struct complex r = complexMult(t[0], t[1]);
    printf("%g%+gi\n", r.real, r.imag);
    return 0;
}