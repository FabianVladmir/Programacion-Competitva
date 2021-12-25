#include <bits/stdc++.h>
using namespace std;

// https://open.kattis.com/problems/pikemanhard

tuple<int,int> optimal(int n, int time, vector<int> lis) {
    int total_time = 0, penalty = 0;
    for (int i = 0; i < n; i++) {
        if (total_time + lis[i] > time) {
            return make_tuple(i, penalty);
        }
        total_time += lis[i];
        penalty = (penalty + total_time) % 1000000007;
    }
    return make_tuple(n, penalty);
}

void solve() {
    int n, t;
    cin >> n >> t;
    int a, b, c, t0;
    cin >> a >> b >> c >> t0;
    vector<int> lis;
    lis.push_back(t0);
    for (int i = 1; i < n; i++) {
        lis.push_back(((a * lis[i - 1] + b) % c) + 1);
    }
    sort(lis.begin(), lis.end());
    int i, p;
    tie(i, p) = optimal(n, t, lis);
    cout << i << " " << p << endl;
}

int main(int argc, char const *argv[])
{
    solve();

    return 0;
}