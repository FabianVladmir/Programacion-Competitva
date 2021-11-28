// https://cses.fi/problemset/task/1653

#include<bits/stdc++.h>
using namespace std;

int solve(){

    int n, k; 
    cin>>n>>k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin>>arr[i];
    
    pair<int,int> dp[1<<n];
    dp[0] = {1,0};
    for(int i = 1; i < (1<<n); ++i) {
        dp[i] = {n+1,0};
        for(int j = 0; j < n; j++) {
            int mask = i & (1<<j);
            if(mask) {
                auto option = dp[i^(1<<j)];
                if(option.second+arr[j]<= k) {
                    option.second += arr[j];
                } else {
                    option.first++;
                    option.second=arr[j];
                }
                dp[i] = min(dp[i], {option.first, option.second});
            }
        }
    }
    return dp[(1<<n)-1].first;
}

int main(){   
    int ans = 0;
    ans = solve();
    cout << ans << endl;
    return 0;
}