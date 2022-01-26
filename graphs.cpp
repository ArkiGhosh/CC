#include <bits/stdc++.h>
#define lint long long int

using namespace std;

vector<vector<int>> lis;
vector<int> result, visited, dist, parent; 

void edge(int u, int v){
    lis[u].push_back(v); lis[v].push_back(u);
}

void bfs(int node){
    queue<int> q;
    q.push(node);
    visited[node] = 1;
    while(!q.empty()){
        int a = q.front();
        q.pop();
        result.push_back(a);
        for(auto i = lis[a].begin(); i != lis[a].end(); i++)
        {
            if (!visited[*i]){
                q.push(*i);
                visited[*i] = 1;
                dist[*i] = dist[a] + 1;
                parent[*i] = a;
            }
        }
    }
}

void dfs(int v){
    visited[v] = 1;
    for(int i : lis[v]){
        if (!visited[i]) dfs(i);
    }
}

void shortest_path(int final, int source){
    if (!visited[final]){
        cout << -1;
    }
    else{
        int distance;
        vector<int> path;
        path.push_back(final);
        while(final != source){
            path.push_back(parent[final]);
            final = parent[final];
        }
        for(int i : path) cout << i << " ";
        cout << endl;
        cout << dist[path[0]] << endl;
    }
}

int main(){
    
    int n, s, f;
    cin >> n >> s >> f;
    visited.assign(n, 0);
    lis.assign(n, vector<int>());
    dist.assign(n, 0); parent.assign(n, 0);
    int u, v;
    for(int i = 0; i < 4; i++){
        cin >> u >> v;
        edge(u, v); edge(v, u);
    }

    //source
    bfs(s);
    for(int i = 0; i < n; i++){
        if(!visited[i]) bfs(i);
    }

    for(auto i = result.begin(); i != result.end(); i++){
        cout << *i << " ";
    }
    cout << endl;
    
    shortest_path(f, s);
}

