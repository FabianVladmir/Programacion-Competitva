#include <bits/stdc++.h>
using namespace std;

int subarraysDivByK(vector<int>& nums, int k) {
    int ans = 0;
    for(int i=0; i<nums.size(); i++){
        int sum = 0;
        for(int j=i; j<nums.size(); j++){
            sum+=nums[j];
            if(sum%k == 0){
                ans++;
            }
        }
    }
    return ans;
}

int main(){

    vector<int> arr = {4,5,0,-2,-3,1};
    
    int ans = subarraysDivByK(arr,5);
    
    cout << ans << endl;

}