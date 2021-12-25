//https://open.kattis.com/problems/pandachess
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m, d;
map<ll, unordered_set<ll>> adjlist;
map<ll, int> dist;
vector<ll> ts;
unordered_set<ll> ics;
void toposort(ll u) {
    dist[u] = 1;
    for (auto v : adjlist[u]) {
        if (dist[v] == 0) toposort(v);
    }
    ts.emplace_back(u);
}

int main() {
    cin >> n >> m >> d;
    
    for (int i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;        
        adjlist[a].insert(b);
        ics.insert(a);
        ics.insert(b);
    }
    for (auto u : ics) {
        if (dist[u] == 0) toposort(u);
    }
    reverse(ts.begin(), ts.end());

    
    for (int i = 0; i < n; i++) {
        dist[ts[i]] = i+1;  
    }
    
    vector<int> v;
    vector<int> L(n, 0);  
    for (int i = 0; i < n; i++) {
        ll a;
        scanf("%lld", &a);
        if (dist[a] == 0) continue;
        v.push_back(dist[a]);
    }

    int k = 0;  
    for (int i = 0; i < (int) v.size(); i++) {
        int pos = lower_bound(L.begin(), L.begin() + k, v[i]) - L.begin();
        L[pos] = v[i];
        if (pos == k) {
            k++;
        }
    }
    cout << 2*(n - k) << endl;

    return 0;
}