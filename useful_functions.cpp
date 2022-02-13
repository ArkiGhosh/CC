#include "bits/stdc++.h"
#define int long long
#define forn(n) for (int i = 0; i < n; i++)
#define revforn(n) for (int i = n - 1; i >= 0; i--)
#define genforn(i, s, n) for (int i = s; i < n; i++)
#define sortarr(arr, n) sort(arr, arr + n)
#define sz(x) (int)(x).size()
#define endl "\n"
using namespace std;

vector<vector<int>> lis;
vector<int> result;
vector<int> visited;
int mod = (int)1e9 + 7;
int gcd(int a, int b)
{
        if (b == 0)
                return a;
        return gcd(b, a % b);
}

// O(log n) base 2
int binary_search(int arr[], int n, int key)
{
        // bin search does not necessarily return first occurence
        int low = 0;
        int high = n;
        while (low <= high)
        {
                int mid = (high + low) / 2;
                if (arr[mid] == key)
                        return mid;
                else if (arr[mid] > key)
                        high = mid - 1;
                else
                        low = mid + 1;
        }
        return -1;
}

int gcd(int a, int b)
{
        if (b == 0)
                return a;
        return gcd(b, a % b);
}

// Number of subarrays of an array with n elements: nC2 + n
// Number of subsequences of an array with n elements: 2**n

long long binpow(long long a, long long b)
{
        // Prefer over pow()
        long long res = 1;
        while (b > 0)
        {
                if (b & 1)
                        res = res * a;
                a = a * a;
                b >>= 1;
        }
        return res;
}

// Sieve of Eratosthenes
// Time Complexity O(nlog(logn))
void PrimeSieve(int n)
{
        int prime[n + 1] = {0};
        for (int i = 2; i <= n; i++)
        {
                if (prime[i] == 0)
                {
                        for (int j = i * i; j <= n; j = j + i)
                                prime[j] = 1;
                }
        }
        for (int i = 2; i <= n; i++)
        {
                if (prime[i] == 0)
                        cout << i << " ";
        }
        cout << "\n";
}

// Prime Factorisation using Sieve
// Time Complexity:
// Preprocessing for Sieve: O(nloglogn)
// Factorisation: O(logn)
void PrimeFactors(int n)
{
        int spf[n + 1] = {0};
        for (int i = 2; i <= n; i++)
                spf[i] = i;

        for (int i = 2; i <= n; i++)
        {
                if (spf[i] == i)
                {
                        for (int j = i * i; j <= n; j = j + i)
                        {
                                if (spf[j] == j)
                                        spf[j] = i;
                        }
                }
        }
        while (n != 1)
        {
                cout << spf[n] << " ";
                n = n / spf[n];
        }
}

// frequency count function
void countFreq(int arr[], int n)
{
        unordered_map<int, int> a;

        // Traverse through array elements and
        // count frequencies
        for (int i = 0; i < n; i++)
                a[arr[i]]++;
        for (auto x : a)
                cout << x.first << " " << x.second << endl;
}

void edge(int u, int v)
{
        lis[u].push_back(v);
        lis[v].push_back(u);
}

void bfs(int node)
{
        queue<int> q;
        q.push(node);
        visited[node] = 1;
        while (!q.empty())
        {
                int a = q.front();
                q.pop();
                result.push_back(a);
                for (auto i = lis[a].begin(); i != lis[a].end(); i++)
                {
                        if (!visited[*i])
                        {
                                q.push(*i);
                                visited[*i] = 1;
                        }
                }
        }
}

// subset generation, prefer bitset
void subset_gen(vector<int> &a)
{
        vector<vector<int>> subset;
        for (int i = 1; i <= (1 << sz(a)) - 1; i++)
        {
                vector<int> s;
                for (int j = 0; j < sz(a); j++)
                {
                        if ((1 << j) & i)
                                s.push_back(a[j]);
                }
                subset.push_back(s);
                dbg(s);
        }
}