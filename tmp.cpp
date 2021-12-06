#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int> &x, vector<int> &y, vector<int> &used, int idx, int first, int &alone, int q){
    int flag = 0;
    used[idx] = 1;
    for(int i = 0; i < x.size(); i++){
        if(used[i]) continue;
        if((x[idx]-x[i])*(x[idx]-x[i])+(y[idx]-y[i])*(y[idx]-y[i]) <= q*q)
            dfs(x,y,used, i, 0, alone, q);
    }
    if(flag && first) alone++;
}
int main(void){
    int n, q, alone(0), total(0);
    cin >> n >> q;
    vector<int> x(n), y(n), used(n, 0);
    for(int i = 0; i < n; i++) cin >> x[i] >> y[i];
    for(int i = 0; i < n; i++){
        if(used[i]) continue;
        dfs(x, y, used, i, 1, alone, q);
        total++; 
    }
    cout << alone << " " << total-alone << "\n";
    return 0;
}