/*#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int a, b, n, q, l, L, R, start, len;
int main(void){
    scanf("%d %d %d", &a, &b, &n);
    char *s = (char*)malloc((n+a+1)*sizeof(char));
    int *dp = (int*)calloc(b+1, sizeof(int));
    scanf("%s", s);
    scanf("%d %d", &q, &l);
    char *p = (char*)malloc((l+1)*sizeof(char));
    for(int i = n; i < n+a; i++) s[i] = '0';
    for(int i = 0; i < l; i++) p[i] = '0';
    s[n+a] = '\0';
    p[l] = '\0';
    start = n+a-b;
    while(start<n+a-1 && s[start]=='0') start++;

    len = n+a-start;
    for(int i = 1; i <= len-l+1; i++)
        dp[i] = dp[i-1]+(!strncmp(s+i-1+start, p, l));
    while(q--){
        scanf("%d %d", &L, &R);
        if(R-l+1 <= L-1) printf("0\n");
        else printf("%d\n", dp[R-l+1]-dp[L-1]);
    }
    free(dp);
    free(s);
    return 0;
}*/

#include<stdio.h>
#include<stdlib.h>
int solve(int *p, int *q, int L){
    if(L==1 || L==0) return 1;
    if(L == 2) return 2;
    int idx = 0;
    while(q[idx] != p[1]) idx++;
    int l = solve(p+1, q, idx+1);
    int r = solve(p+idx+2, q+idx+1, L-idx-2);
    return l*r;
}
int n, pre[15], post[15];
int main(void){
    while(~scanf("%d", &n)){
        for(int i = 0; i < n; i++) scanf("%d", pre+i);
        for(int i = 0; i < n; i++) scanf("%d", post+i);
        printf("%d\n", solve(pre, post, n));
    }
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int a, b, n, q, l, L, R, lenS;
char s[200005];
char p[100005];
char tmp[200005];
int dp[200005];
int main(void){
    scanf("%d %d %d", &a, &b, &n);
    if(n > 200000)
    getchar();
    int cnt = n-b+a;
    if(cnt > n) cnt = n;
    while(cnt--) getchar();
    scanf("%s", s);
    if(cnt == n) s[0] = '0', s[1] = '\0';
    int len = strlen(s);
    cnt = b-len;
    if(cnt > 0){
    for(int i = len; i < len+cnt; i++) s[i] = '0';
    s[len+cnt] = '\0';
    }
    lenS = strlen(s);
    
    int idx = 0;
    while(idx < lenS-1 && s[idx] == '0') idx++;
    strcat(tmp, s+idx);
    lenS = strlen(tmp);

    scanf("%d %d", &q, &l);
    for(int i = 0; i < l; i++) p[i] = '0';
    p[l] = '\0';

    for(int i = 1; i < lenS; i++)
        dp[i] = dp[i-1]+(!strncmp(tmp+i-1, p, l));

    while(q--){
        scanf("%d %d", &L, &R);
        if(R-l+1 <= L-1) printf("0\n");
        else printf("%d\n", dp[R-l+1]-dp[L-1]);
    }
    return 0;
}