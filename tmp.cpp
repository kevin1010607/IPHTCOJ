#include<bits/stdc++.h>
using namespace std;
int t, n, p, k;
int main(void){
    cin >> t;
    while(t--){
        cin >> n >> p >> k;
        vector<int> v(n), dp(n+1);
        for(auto& i : v) cin >> i;
        sort(v.begin(), v.end());
        for(int i = 1; i <= n; i++){
            if(i >= k) dp[i] = dp[i-k]+v[i-1];
            else dp[i] = dp[i-1]+v[i-1];
        }
        cout << upper_bound(dp.begin(), dp.end(), p)-dp.begin() << "\n";
    }
    return 0;
}