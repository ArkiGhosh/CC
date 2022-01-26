#include "bits/stdc++.h"
using namespace std;
#define int long long 
#define endl "\n"
#define sz(x) (int)(x).size()
//type cast .size() to int
//stay calm

void solve()
{
    int a, b;
    cin >> a >> b;
    int x = (b + 5) / 6;
    if (a > b) cout << "No" << endl;
    else if (a >= x) cout << "Yes" << endl;
    else cout << "No" << endl;

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