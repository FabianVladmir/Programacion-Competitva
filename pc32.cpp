#include <bits/stdc++.h>
using namespace std;

vector<int> threeSum(vector<int> &nums, int target){

    int n = nums.size();
    vector<int> ans(n);
    for (size_t i = 0; i < n; i++)
    {
        int curr = i, next = i+1, last = n-1; 
        while (next < n && next < last)
        {
            if(nums[curr] + nums[next] + nums[last] == target){
                ans.push_back(nums[curr]);
                ans.push_back(nums[next]);
                ans.push_back(nums[last]);
                while (last!=0 && nums[last] == nums[last-1] ) last--;
                while (next != n-1 && nums[next] == nums[next+1]) next++;
                last--,next++;
                
            }
            else if(nums[curr] + nums[next] + nums[last] > target){
                while (last!=0 && nums[last] == nums[last-1] ) last--;
                last--;
            }

            else{
                while (next != n-1 && nums[next] == nums[next+1]) next++;
                next++;
            }
        }
        while (i!=n-1 && nums[i] == nums[i+1]) i++;        
          
    }
    return ans;
}


int main(){






    return 0;
}