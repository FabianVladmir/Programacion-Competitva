#include <bits/stdc++.h>
using namespace std;

long long int fact(long long int n) {
    vector<long long int> result(10000);
    if (n >= 0) {
      result[0] = 1;
      for (long long int i = 1; i <= n; ++i) {
         result[i] = i * result[i - 1];
      }
      return result[n];
   }
}

void solve(){

    long long int n;
    cin >> n;
    long long int ans = fact(n);
    // cout << ans << endl;
    long long int sz = trunc(log10(ans))+1;
    cout << sz << endl;

}

int main(){

    solve();

    return 0;
}