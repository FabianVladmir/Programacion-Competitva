//https://open.kattis.com/problems/buttonbashing
#include <bits/stdc++.h>
using namespace std;

vector<int> dist;
queue<int> q;
const int INF = 1e9;
int e, v, element, dest, n;
vector<int> transitions;
int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);                    
    cout.tie(NULL);
    cin >> element;
    n = 3601;
    for (int tc = 0; tc < element; tc++) {
        dist.assign(n, INF);  
        transitions.clear();

        cin >> e >> dest;
        for (int i = 0; i < e; i++) {
            cin >> v;
            transitions.push_back(v);
        }
        dist[0] = 0;
        queue<int> q;
        q.push(0);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto d : transitions) {  
                v = u + d;
                v = max(0, v);
                v = min(v, n - 1);
                if (dist[v] == INF) {
                    dist[v] = dist[u] + 1;  
                    q.push(v);              
                }
            }
        }

        for (int i=dest; i<n; i++) {
            if (dist[i] != INF) {
                
                cout << dist[i] << i-dest << endl;
                
                break;
            }
        }
    }

    return 0;
}