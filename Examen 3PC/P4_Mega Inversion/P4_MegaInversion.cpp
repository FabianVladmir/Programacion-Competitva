//https://open.kattis.com/problems/megainversions
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int MX = 2e5 + 5;

ll bit2[MX], bit1[MX];
int n;

void update (int i, int val, ll ar[]) {
	for (; i <= n; i += i&(-i)) {
		ar[i] += val;
	}
}

ll query (int i, ll ar[]) {
	ll res = 0;
	for (; i; i -= i&(-i)) {
		res += ar[i];
	}
	return res;
}

int main () {
	cin >> n;
	vector<int> ar(n);
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}

	ll sol = 0;
	for (int i = n - 1; i >= 0; i--) {
		sol += query(ar[i] - 1, bit2);
		ll uno = query(ar[i] - 1, bit1);
		update(ar[i], 1, bit1);
		update(ar[i], uno, bit2);
	}
	cout << sol << '\n';
}