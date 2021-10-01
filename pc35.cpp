#include <bits/stdc++.h>
using namespace std;

//O(n^2)
int maxSubArray(vector<int> &nums){

    int maxx = 0;
    for (size_t i = 0; i < nums.size(); i++)
    {
        int currMax = 0;
        for (size_t j = 1; j < nums.size(); j++)
        {
            currMax+=nums[j];
            maxx = max(currMax,maxx);
        }
    }    
    return maxx;
}

int main(){

    // int n;
    // cin >> n;
    // vector<int> arr;
    // for (int i = 0; i < n; i++)
    // {
    //     int x;
    //     cin >> x;
    //     arr.push_back(x);
    // }
    
    vector<int> arr {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    // vector<int> arr {-1, 3, -2, 5, 3, -5, 2, 2};
    int ans = maxSubArray(arr);
    cout << ans << endl;


    return 0;
}