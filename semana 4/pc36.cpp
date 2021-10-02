#include <bits/stdc++.h>
using namespace std;

// https://cses.fi/problemset/task/1077
int main(){

    int n, k;
    cin >> n >> k;
    vector<int> arr;
    for (size_t i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    if(k==1){
        for (size_t i = 0; i < n; i++)
        {
            cout << 0 << " ";
        }
        return 0;        
    }
    if(k==2){
        for (size_t i = 1; i < n; i++)
        {
            cout << abs(arr[i-1] - arr[i]) << " ";
        }
        return 0;        
    }
    



    return 0;
}