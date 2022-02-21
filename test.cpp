#include "bits/stdc++.h"
using namespace std;
#define int long long 
#define endl "\n"
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define len(x) (int)(x).length()
int N = 1e9 + 7;
int k;
vector<string> ans;

void func(string s){
        if(sz(s) == k){
                ans.push_back(s);
                return;
        }
        if (s[sz(s) - 1] == 'S'){ 
                func(s + "R");
        }
        else{
                func(s + "S");
                func(s + "R");
        }
}

void solve()
{
       cin >> k; 
       func("");
       cout << sz(ans) << endl;
       for(auto s : ans) cout << s << endl;
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