#include<stdio.h>
#define MOD 1000000007
typedef struct{long long a[2][2];}Mtx;
Mtx pd(Mtx a, Mtx b){
    Mtx m;
    m.a[0][0] = m.a[0][1] = m.a[1][0] = m.a[1][1] = 0;
    for(int i = 0; i < 2; i++) for(int j = 0; j < 2; j++) for(int k = 0; k < 2; k++) m.a[i][j] = (m.a[i][j]+(a.a[i][k]*b.a[k][j])%MOD)%MOD;
    return m;
}
Mtx pw(long long n){
    Mtx m, p;
    m.a[0][0] = m.a[0][1] = m.a[1][0] = 1, m.a[1][1] = 0;
    if(n == 1) return m;
    p = pw(n/2);
    p = pd(p, p);
    return (n%2==0?p:pd(m, p));
}
long long F(long long n){
    if(n==1 || n==2) return 1;
    Mtx m = pw(n-2);
    return (m.a[0][0]+m.a[0][1])%MOD;
}
int main(void){
    long long n;
    while(~scanf("%lld", &n)) printf("%lld\n", F(n));
    return 0;
}