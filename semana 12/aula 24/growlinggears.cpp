#include <bits/stdc++.h>
using namespace std;

void solve(){

    int k;
    cin >> k;
    double maxs = -INFINITY;
    int maxx = 0;

    for (size_t i = 1; i <= k; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        double temp = (double)b/(a<<1);
        double val = -a * temp * temp + b * temp + c;

        if(val > maxs){
            maxs = val;
            maxx = i;
        }
    }
    cout << maxx << endl;
    
}

int main(){

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    
    return 0;
}