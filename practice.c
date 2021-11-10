#include<stdio.h>
#include<string.h>
#define max(a,b) a>b?a:b
char s1[1005], s2[1005];
int q, a, b, dp[1005], l1, l2, ans = 0;
int main(void){
    while(~scanf("%s %s", s1, s2)){
        l1 = strlen(s1), l2 = strlen(s2);
        for(int i = 1; i <= l1-l2+1; i++){
            dp[i] = dp[i-1]+(!strncmp(s1+i-1, s2, l2));
            //printf("%d ", dp[i]);
        }gg
        ans = 0;
        scanf("%d", &q);
        while(q--){
            scanf("%d %d", &a, &b);
            if(b-a+1 < l2) continue;
            ans = max(ans, dp[b-l2+1]-dp[a-1]);
        }
        printf("%d\n", ans);
    }
    return 0;
}