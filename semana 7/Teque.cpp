#include <bits/stdc++.h>
using namespace std;
deque<int> dq;
deque<int> ans;
//TEQUE
void solve(string cad, int x){

    
    if(cad == "push_back"){
        dq.push_back(x);
    }
    else if (cad == "push_front")
    {
        dq.push_front(x);
    }
    else if (cad == "push_middle")
    {
        int mid = (dq.size() + 1)/ 2;
        auto it = dq.begin() + mid;
        dq.insert(it, x);        
    }
    //get
    else if(cad == "get"){
        if(x > dq.size())
            return;
        auto it = dq.begin() + x;
        ans.push_back(*it);
    }
    
    while (!ans.empty())
    {
        cout << ans.front() << endl;
        ans.pop_front();
    }
}


int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    while (n--)
    {
        string cad;
        int x;
        cin >> cad;
        cin >> x;
        solve(cad,x);
    }
    
    return 0;
}