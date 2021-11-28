// https://cses.fi/problemset/task/1683
#include <bits/stdc++.h>
using namespace std;

int k;
vector<vector<int>> g, h;
vector<int> a, b, vis1, vis2;

void dfs1(int i) {
  vis1[i] = 1;
  for (int j : g[i])
    if (!vis1[j])
      dfs1(j);
  a.push_back(i);
}

void dfs2(int i) {
  vis2[i] = 1;
  b[i] = k;
  for (int j : h[i])
    if (!(vis2[j]))
      dfs2(j);
}

void solve(){
    
    int n, m, u, v;
    cin >> n >> m;
    
    g = vector<vector<int>>(n);
    h = vector<vector<int>>(n);

    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        h[v].push_back(u);
    }

    vis1 = vector<int>(n);
    for (int i = 0; i < n; i++)
        if (!vis1[i])
        dfs1(i);

    reverse(a.begin(), a.end());

    b = vector<int>(n);
    vis2 = vector<int>(n);

    for (int i : a)
        if (!vis2[i]) {
        k++;
        dfs2(i);
        }

    cout << k << '\n';
    for (int i = 0; i < n; i++)
        cout << b[i] << " \n"[i == n - 1];
}


int main() {
  
  solve();
  return 0;
}