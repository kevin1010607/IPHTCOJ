#include<stdio.h>
#define MOD 1000000007
typedef struct{long long s[3][3];}Mtx;
Mtx mul(Mtx a, Mtx b){
    Mtx m;
    for(int i = 0; i < 3; i++) for(int j = 0; j < 3; j++) m.s[i][j] = 0;
    for(int i = 0; i < 3; i++) for(int j = 0; j < 3; j++) for(int k = 0; k < 3; k++) m.s[i][j] = (m.s[i][j]+(a.s[i][k]*b.s[k][j])%MOD)%MOD;
    return m;
}
Mtx power(long long n){
    Mtx m, p;
    m.s[1][1] = m.s[1][2] = m.s[2][0] = m.s[2][2] = 0;
    m.s[0][0] = m.s[0][2] = m.s[1][0] = m.s[2][1] = 1;
    m.s[0][1] = 2;
    if(n == 1) return m;
    p = power(n/2);
    p = mul(p, p);
    return n%2?mul(p, m):p;
}
int P(long long n){
    if(n == 1) return 1;
    if(n == 2) return 12;
    if(n == 3) return 13;
    Mtx m = power(n-3);
    return ((13*m.s[0][0])%MOD+(12*m.s[0][1])%MOD+(m.s[0][2])%MOD)%MOD;
}
int main(void){
    long long x, n;
    scanf("%lld", &n);
    while(n--){
        scanf("%lld", &x);
        printf("%d\n", P(x));
    }
    return 0;
}