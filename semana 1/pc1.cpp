#include <bits/stdc++.h>
using namespace std;

//O(N^2)
int maxProductBF(vector<int>& nums) {
    
    int n = nums.size();
    int res=0;
    for(int i=0; i<n; i++)
    {
        for(int j=i+1;j<n;j++)
        {
            res = max(res,nums[i]*nums[j]);
        }
    }
    return res;
}

//0(N)
int maxProductN(vector<int>& nums) {
    int first=0,second=0;
    int n = nums.size();
    for(int i=0; i<n; i++){
        if(nums[i]>first){
            second=first;
            first=nums[i];
        }
        else{
            second=max(second,nums[i]);
        }
    }
    return first*second;
}

//O(N LOG(N))
int maxProduct(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    
    return (nums[nums.size()-1])*(nums[nums.size()-2]);
}
        
int main(){

    int n;
    cin >> n;
    vector<int> cad(n);
    for (size_t i = 0; i < cad.size(); i++)
    {
        cin >> cad[i];
    }

    cout << maxProduct(cad) << endl;
    cout << maxProductBF(cad) << endl;
    cout << maxProductN(cad) << endl;
    
}        