#include "bits/stdc++.h"
using namespace std;
#define int long long 
#define endl "\n"
#define sz(x) (int)(x).size()
//type cast .size() to int
//stay calm

vector<vector<int>> lis;
vector<int> visited, length;

void addedge(int u, int v){
    lis[u].push_back(v); lis[v].push_back(u);
}

void dfs(int v, int p){
    visited[v] = 1;
    for(int i : lis[v]){
        if(i != p){
            length[i] = length[v] + 1;
            dfs(i, v);
        }
    }
}

void solve()
{
    int n, m; cin >> n >> m;
    lis.assign(n, vector<int>());
    visited.assign(n, 0);
    length.assign(n, 0);
    int u, v;
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        u--; v--;
        addedge(u, v);
    }
    dfs(0, -1);
    vector<pair<int, int>> ans;
    for(int i = 0; i < n; i++){
        ans.push_back({length[i], i});
    }
    sort(ans.begin(), ans.end());
    int i = ans[n - 1].second;
    for(int j = 0; j < n; j++) length[j] = 0;
    dfs(i, -1);
    sort(length.begin(), length.end());
    cout << length[n - 1] << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //int t; cin >> t;
    //while (t--) 
    solve();
    return 0;
}
