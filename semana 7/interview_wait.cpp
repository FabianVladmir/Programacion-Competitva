#include <bits/stdc++.h>
using namespace std;
//INTERVIEW WAIT

void solve(vector<int> &nums){

    deque<int> dq;
    for(auto &it : nums)
        dq.push_front(it);
    
    int ans = 0;
    while (!dq.empty())
    {
        int left = dq.back();
        int right = dq.front();

        if(left == -1 || right == -1){
            cout << ans <<endl;
            return;}
        else if(right < left){
            ans+=dq.front();
            dq.pop_front();}
        else{
            ans+=dq.back();
            dq.pop_back();
        }
    }
    cout << ans << endl;
}

int main(){

    vector<int> arr{4,-1,5,2,3};
    solve(arr);
}