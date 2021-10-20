#include<stdio.h>
int main(void){
    float n;
    unsigned int a[32], *p = (unsigned int*)&n;
    while(~scanf("%f", &n)){
        for(int i = 31; i >= 0; i--) a[i] = *p%2, *p >>= 1;
        for(int i = 0; i < 32; i++) printf("%d", a[i]);
        puts("");
    }
    return 0;
}