#include <bits/stdc++.h>
using namespace std;

void printArray(vector<int> &arr){
    for (size_t i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){

    int n,k;
    cin >> n >> k;
    vector<int> arr(n);
    vector<int> diff(n);
    int limit;
    double ans;
    limit = n-1;
    
    for (size_t i = 0; i < n; i++)
    {
        cin >> arr[i];        
    }

    diff[0]++;

    for (size_t i = 0; i < n-1; i++)
    {
        if(arr[i] + 1000 <= arr[limit]){
            diff[i+1]--;
        }
        else{
            diff[i+1]++;
        }
    }

    // printArray(diff);

    for (size_t i = 1; i < n; i++)
    {
        diff[i]+=diff[i-1];
    }
    
    // printArray(diff);

    sort(diff.begin(), diff.end(), greater<int>());
    
    // printArray(diff);
    ans = diff[0];
    ans = ans/k;

    cout << ceil(ans) << endl;

    return 0;
}