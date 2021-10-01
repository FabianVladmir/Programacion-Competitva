#include <bits/stdc++.h>
using namespace std;


vector<int> sortedSquares(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n, 0);
    int left =0;
    int right =n-1;
    int index = n-1;

    while(left <= right){

        int temp1  = nums[left]* nums[left];
        int temp2 = nums[right]*nums[right];

        if(abs(temp1) > abs(temp2)){
            res[index] = temp1;
            left++;

        }else{
            res[index] = temp2;
            right--;
        }

    index--;
    }
    return res;
}


int main(){


    vector<int> arr = {-4,-3,1,2,3};
    vector<int> ans = sortedSquares(arr);

    for (size_t i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    


    return 0;
}