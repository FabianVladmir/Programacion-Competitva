#include<bits/stdc++.h>
using namespace std;

//Max sum of any contiguos subarray of size k
//O(N^2)

int maxContiguosSum(vector<int> &nums, int target){

    int maxSum = 0, subarraySum;
        for (int i = 0; i <= nums.size()-target; i++) {
            subarraySum = 0;
            for (int j = i; j < i+target; j++) {
                subarraySum += nums[j];
            }
            maxSum = max(maxSum, subarraySum);
        }

        return maxSum;
}

//O(N)
// int maxContiguosSum(vector<int> &nums, int target){

//     int maxSum = 0;
//     int subarraySum = 0;
//     int curr=0;
//     for(int i=0;i<nums.size();i++){
//         subarraySum+=nums[i];
//         if(i>=target-1){
//             maxSum = max(subarraySum,maxSum);
//             subarraySum -= nums[curr];
//             curr++;
//         }
        
//     }

// }



int main(){

    vector<int> arr {2,3,4,1,5};
    int ans = maxContiguosSum(arr,3);
    cout << ans << endl;


    return 0;
}
