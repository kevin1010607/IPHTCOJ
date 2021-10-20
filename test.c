#include<stdio.h>
int dp[1000005];
int solve(int n){
    int ret = 0;
    while(n) ret += n%10==1?1:0, n /= 10;
    return ret;
}
int main(void){
    for(int i = 1; i < 1000005; i++) dp[i] = dp[i-1]+solve(i);
    int q, a, b;
    scanf("%d", &q);
    while(q--){
        scanf("%d %d", &a, &b);
        printf("%d\n", dp[b]-dp[a-1]);
    }
    return 0;
}