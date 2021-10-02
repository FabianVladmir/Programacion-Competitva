#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int> &nums){
    int ans = INT_MIN;
    int sum = 0;

    for(int i: nums){
        sum+=i;
        ans = max(sum,ans);
        sum = max(sum,0);
    }

    return ans;

}

int main(){

    vector<int> arr{-1, 3, -2, 5, 3, -5, 2, 2};
    int ans = maxSubArray(arr);
    cout << ans << endl;
    return 0;
}
