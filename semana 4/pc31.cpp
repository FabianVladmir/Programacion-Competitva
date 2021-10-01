#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    int left = 0;
    int right = n-1;
    vector<int> ans;

    while (left < right)
    {
        if(nums[left] + nums[right] == target){
            ans.push_back(left);
            ans.push_back(right);
            return ans;   
            }
        else if(nums[left] + nums[right] < target){
            left++;

        }else{
            right--;
        }
    }
    
}

// vector<int> twoSum(vector<int>& nums, int target) {
//         unordered_map<int, int> dict;
//         for(int i = 0; i < nums.size(); i++){
//             int diff = target - nums[i];
//             if(dict.count(diff)) return {dict[diff], i};
//             else dict[nums[i]]=i;
//         }
//         return {-1,-1};
// }

int main(){

    vector<int> arr = {1,2,7,9,11,15};
    vector<int> arr2 = {-1,1,2,3,5};
    vector<int> ans = twoSum(arr2,5);
    
    
    for (size_t i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    

    return 0;
}