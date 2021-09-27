#include <bits/stdc++.h>
using namespace std;

vector<int> hasBucle(vector<int> &arr){

    vector<int> ans;
    map<int,int> mp;
    int indx = 0;
    
    //get the frequency
    for (size_t i = 0; i < arr.size(); i++)
    {
        mp[arr[i]]++;
    }    

    //checks if current and subsequent elements have a frequency greater than 1 and 2
    //then a loop will exist in the array
    for (auto it = mp.begin(); it != mp.end() ; it++, indx++)
    {
       if(it->second > 1 && mp[arr[indx+1]] > 2){
           ans.push_back(it->first);
       }       
    }

    return ans;
} 

int main(){

    vector<int> arr = {1, 2, 3, 4, 5, 2, 3, 4, 5, 2, 3, 4, 5, 2};
    // vector<int> arr = {1, 2, 3, 4, 5, 6, 3, 7, 8, 9, 10, 11, 8, 9, 10, 11, 8, 9, 10, 11, 8};

    vector<int> ans = hasBucle(arr);
    for (size_t i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}