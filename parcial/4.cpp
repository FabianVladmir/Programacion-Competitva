/*
https://cses.fi/problemset/task/1645
*/

#include <bits/stdc++.h>
using namespace std;

void nearSmallerValue(vector<int> &nums){

    int n=nums.size();
    stack<int> st;
    
    for (size_t i = 0; i < n; i++)
    {
        int j;
        while (!st.empty() && st.top() >= nums[i]){
            st.pop();
            j--;
        }            
        
        if (st.empty())
            cout << 0 << " ";
        else{
            st.pop();            
            cout << j+1 << " ";
        }           
       
        st.push(nums[i]);
        j = i;
                
    }    

}

int main(){

    int n;
    cin >> n;
    vector<int> arr(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    nearSmallerValue(arr);
    return 0;
}