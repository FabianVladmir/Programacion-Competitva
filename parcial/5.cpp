/*
https://cses.fi/problemset/task/1648

    https://cses.fi/problemset/result/2967295/
    https://cses.fi/problemset/result/2968150/


*/
#define ll long long
#include <bits/stdc++.h>
using namespace std;


// int sumRange(vector<ll> &nums, int a, int b){

//     int sum = 0;
//     for (int i = a-1; i < b; i++)
//     {
//         sum+=nums[i];
//     }    
//     return sum;
// }

// void updateVal(vector<ll> &nums, int k, ll u){
//     nums[k-1] = u;
// }


void update(vector<ll> &nums, vector<ll> &arrsum, int k, ll u, int newsize){
    int idx = k/newsize;
    arrsum[idx] = arrsum[idx] - nums[k] - u;
    nums[k] = u;

}


int sumRange (vector<ll> &nums, vector<ll> &arrsum, int a, int b, int newsize){
        
    int sum = 0;
    int start = a/newsize;
    int end = b/newsize;

    if(start == end){
        for (int i = a; i <= b; i++)
        {
            sum+=nums[i];
        }
        
    }else{
        for (int i = a; i <= (start + 1) * newsize - 1; i++)
            sum += nums[i];
        for (int i = start + 1; i <= end - 1; i++)
            sum += arrsum[i];
        for (int i = end * newsize; i <= b; i++)
            sum += nums[i];

    }
    return sum;
}


int main(){

    int n, q;
    cin >> n >> q;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    double block = sqrt(n);
    int newsize = (int) n/block;
    vector<ll> temp(newsize);

    for (int i = 0; i < n; i++)
    {
        temp[i/newsize]+=arr[i];
    }

    while (q--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        if(x==1){
            update(arr,temp,y-1,z,newsize);
        }
        if(x==2){
            int ans = sumRange(arr,temp,y-1,z-1,newsize);
            cout << ans << endl;
        }
    }
    
    return 0;
}

