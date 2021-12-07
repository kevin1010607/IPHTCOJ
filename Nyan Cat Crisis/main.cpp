#include<bits/stdc++.h>
using namespace std;
typedef struct{int x, y, u;}P;
int t, n, r, k;
int dfs(int idx, vector<P>& v){
    int res = 1;
    v[idx].u = 1;
    for(int i = 0; i < n; i++){
        if(v[i].u) continue;
        if(((v[idx].x-v[i].x)*(v[idx].x-v[i].x)+(v[idx].y-v[i].y)*(v[idx].y-v[i].y)) <= r*r)
            res += dfs(i, v);
    }
    return res;
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> r >> k;
        vector<P> v(n);
        for(auto& p : v) cin >> p.x >> p.y;
        int res1 = 0, res2 = 0;
        for(int i = 0; i < n; i++){
            if(v[i].u) continue;
            int cnt = dfs(i, v);
            (cnt<k)?(res1++):(res2++);
        }
        cout << res1 << " " << res2 << "\n";
    }
    return 0;
}