
/* 
https://cses.fi/problemset/task/1644/

https://cses.fi/problemset/result/2971773/
 */

#include <bits/stdc++.h>
#define ll long long
using namespace std;

void maxSubarraySum(vector<int> &nums, int a, int b){
    
    int n=nums.size();
    vector<ll> prefixsum(n+1);
    prefixsum[0] = 0;

    for(int i=1;i<=n;i++){
       
        prefixsum[i] = prefixsum[i-1] + nums[i-1];
    }
    multiset<ll> curr;
    ll ans = INT_MIN;
    for(int i=a;i<=n;i++){
        if(i>b){
            curr.erase(curr.find(prefixsum[i-b-1]));
        }
        curr.insert(prefixsum[i-a]);
        ans = max(ans, prefixsum[i] - *curr.begin());
    }
    cout<<ans<<"\n";
}
int main() {

    int n, a, b;
    cin >> n >> a >> b;
    vector<int> arr(n);

    for (size_t i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    maxSubarraySum(arr,a,b);

    
}