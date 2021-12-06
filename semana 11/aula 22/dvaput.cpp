#include <bits/stdc++.h>
using namespace std;


int main() {
  cin.tie(0), ios_base::sync_with_stdio(0);
  int n, k = 0, m = 0, x, y, z;
  string s;
  cin >> n >> s;
  vector<vector<int>> p(1, vector<int>(n));
  for (int i = 0; i < n; i++) 
    p[0][i] = s[i];
    
  for (int k = 1; k < n; k *= 2) {
    vector<tuple<int,int,int>> l(n);
    for (int i = 0; i < n; i++)
      l[i] = {p.back()[i], i + k < n ? p.back()[i + k] : -1, i};
    sort(l.begin(), l.end());
    p.push_back(vector<int>(n));
    for (int i = 0, j = 0; i < n; i++) {
      tie(x, y, z) = l[i];
      if (i && (get<0>(l[i - 1]) != x || get<1>(l[i - 1]) != y)) j++;
      p.back()[z] = j;
    }
  }

  vector<int> sa(n), lcp(n), rank(n);
  for (int i = 0; i < n; i++) 
    sa[p.back()[i]] = i;
  for (int i = 0; i < n; i++) 
    rank[sa[i]] = i;
  for (int i = 0; i < n; i++)
    if (rank[i]) {
      int j = sa[rank[i] - 1];
      while (i + k < n && j + k < n && s[i + k] == s[j + k]) k++;
      lcp[i] = k;
      if (k) k--;
    }
  for (int x : lcp) 
    m = max(m, x);
  cout << m << '\n';
}