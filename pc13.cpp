#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int>& nums, int k) {

    int ans = 0;
    for(int i=0; i<nums.size(); i++){
        int sum = 0;
        for(int j=i; j<nums.size(); j++){
            sum+=nums[j];
            if(sum == k){
                ans++;
            }
        }
    }
    return ans;
}

int subarraySum(vector<int>& nums, int k) {

    int n = nums.size();
    int ans = 0;    
   
    vector<int>sum(n+1,0);   
    
    for(int i=1;i<=n;i++)
        sum[i] =sum[i-1]+nums[i-1];
    
  
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {           
            if(sum[j] - sum[i] == k)
            ans++;
        }
    }
    return ans;
}


int main(){

    
    vector<int> arr = {1,1,1};
    
    int ans = subarraySum(arr,2);
    
    cout << ans << endl;



}


