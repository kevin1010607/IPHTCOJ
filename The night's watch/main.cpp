#include<bits/stdc++.h>
using namespace std;
int t, n, m, k, res;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> m >> k;
        vector<int> v(n);
        for(auto& i : v) cin >> i;
        if(k >= m-1){
            int m1 = *max_element(v.begin(), v.begin()+m);
            int m2 = *max_element(v.rbegin(), v.rbegin()+m);
            res = max(m1, m2);
        }
        else{
            res = INT_MIN;
            for(int i = 0; i <= k; i++){
                int now = INT_MAX;
                for(int j = 0; j < m-k; j++){
                    int l = i+j, r = (n-(k-i))-(m-k-j);
                    now = min(now, max(v[l], v[r]));
                }
                res = max(res, now);
            }
        }
        cout << res << "\n";
    }
    return 0;
}