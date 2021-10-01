#include <bits/stdc++.h>
using namespace std;

vector<int> prefixSum(vector<int> &arr){

    int n = arr.size();
    vector<int> ans(n+1);
    ans[0] = 0;
    int prev = 0;   
    for (size_t i = 0; i < n; i++)
    {
        prev+= arr[i];
        ans.push_back(prev);
    }
    return ans;    
}

int main()
{
    vector<int> arr{1,2,3,4,5};
    vector<int> ans;

    ans = prefixSum(arr);
    for (auto i : ans)
        cout << i << ' ';

    return 0;
}