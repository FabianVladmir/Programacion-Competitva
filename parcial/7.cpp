/*
https://cses.fi/problemset/task/2074
https://cses.fi/problemset/result/2969316/
*/

#include <bits/stdc++.h>
using namespace std;

void printArray(vector<int> arr)
{
   for (int i = 0; i < arr.size(); i++)
   cout << arr[i] << " ";
 
   cout << endl;
}


void revereseArray(vector<int> &nums, int start, int end)
{
    if (start >= end)
    return;
     
    while (start < end)
    {
        swap(nums[start], nums[end]);
        start++;
        end--;
    }
    // printArray(nums);

}    

int sumRange(vector<int> &nums, int start, int end){

    int sum = 0;
    for (int i = start; i <= end; i++)
    {
        sum+=nums[i];
    }
    return sum;
}

int main(){

    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

   
    while (q--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        if(x==1){
            revereseArray(arr,y-1,z-1);         
            // printArray(arr);    
        }
        if(x==2){
            int ans = sumRange(arr,y-1,z-1);
            cout << ans << endl;
        }
    }
    
    return 0;
}
