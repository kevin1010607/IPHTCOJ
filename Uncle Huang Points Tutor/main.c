#include<stdio.h>
long long solve(long long x, long long y, long long m){
    if(y == 0) return 1%m;
    long long p = solve(x, y/2, m)%m;
    p = (p*p)%m;
    return (y%2==0)?p:(p*x)%m;
}
int main(void){
    long long x, y, m;
    scanf("%lld %lld %lld", &x, &y, &m);
    printf("%lld\n", solve(x%m, y, m));
    return 0;
}