#include <bits/stdc++.h>
using namespace std;

void prefixSum(vector<int> &arr){

    int n = arr.size();
    
    int prev = 0;
    for (size_t i = 1; i < n; i++)
    {
        arr[i] = prev + arr[i];
        prev = arr[i];
    }    
}


int main(){

    vector<int> arr ={1,2,3,4,5};
    prefixSum(arr);

    for (size_t i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    

    return 0;
}