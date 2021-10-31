#include <bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int,vector<int>,greater<int>> pq;
    
    for(auto i : nums)
    {
        pq.push(i);
        if(pq.size()>k) pq.pop();
    }
    
    return pq.top();
}

int main(){

    vector<int> nums = {3,2,1,5,6,4};
    int k = 2;
    int ans = findKthLargest(nums,k);
    cout << ans << endl;
}