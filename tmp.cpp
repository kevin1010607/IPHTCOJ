#include<bits/stdc++.h>
using namespace std;
typedef struct{int x,y,u;}S;
bool connect(S a, S b, int r){
    return ((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)) <= r*r;
}
int dfs(int id, vector<S>& v, int r){
    int res = 1;
    v[id].u = 1;
    for(int i = 0; i < v.size(); i++){
        if(v[i].u == 1) continue;
        if(connect(v[id], v[i], r)) res += dfs(i, v, r);
    }
    return res;
}
int main(void){
    int t, k, n, r;
    cin >> t;
    while(t--){
        cin >> n >> r >> k;
        int res1 = 0, res2 = 0;
        vector<S> v(n);
        for(auto& i : v) cin >> i.x >> i.y;
        for(int i = 0; i < n; i++){
            if(v[i].u == 1) continue;
            int aa = dfs(i, v, r);
            aa<k?res1++:res2++;
        }
        cout << res1 << " " << res2 << "\n";
    }
    return 0;
}