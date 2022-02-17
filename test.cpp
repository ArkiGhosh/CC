#include "bits/stdc++.h"
using namespace std;
#define int long long 
#define endl "\n"
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define len(x) (int)(x).length()
int N = 1e9 + 7;

vector<vector<int>> lis;
vector<int> visited, height;
int n, m;

void dfs(int v){
        visited[v] = 1;
        for(auto i : lis[v]){
                if (visited[i]){
                        height[v] = max(height[v], height[i] + 1);
                        continue;
                }
                dfs(i);
                height[v] = max(height[v], height[i] + 1);
        }
}

void solve()
{
        cin >> n >> m;
        lis.assign(n, vector<int>());
        visited.assign(n, 0);
        height.assign(n, 0);
        int x, y;
        for(int i = 0; i < m; i++){
                cin >> x >> y;
                lis[x - 1].push_back(y - 1);
        }
        for(int i = 0; i < n; i++){
                if (!(visited[i])) dfs(i);
        }
        cout << *max_element(all(height));
}

int32_t main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int t = 1; 
        //cin >> t;
        while (t--) 
        solve();
        return 0;
}