#include <bits/stdc++.h>
using namespace std;

//Integer Lists
void printVector(vector<int> &nums){
    for(auto i:nums){
        cout << i << " ";
    }
    cout << endl;
}

void solve(string letters, vector<int> &nums){

    
    int n = letters.size();
    int m = nums.size();
    deque<int> dq;
    
    if(  m==1 || m==0){
        cout << "error" << endl;
        return;
    }
    int countR = count(letters.begin(),letters.end(),'R');
    int countD = count(letters.begin(), letters.end(),'D');

    // cout << countR << " " << countD << endl;

    for(auto it:nums){
        dq.push_back(it);
    }

    if(countR % 2 == 1){
        deque<int> temp(dq);
        vector<int> v_back;
        vector<int> v_front;
        int left = temp.front();
        int right = temp.back();
        while (!temp.empty())
        {
            v_front.push_back(right);
            v_back.push_back(left);
            if(temp.size() == 1){
                v_front.push_back(temp.back());
                temp.pop_front();
            }

            temp.pop_back();
            temp.pop_front();            

            reverse(v_front.begin(), v_front.end());

            for (size_t i = 0; i < v_front.size(); i++)
            {
                v_back.push_back(v_front[i]);
            }                
            
        }
        dq.clear();
        for(auto it:nums){
            dq.push_front(it);
        }
        // cout << "sasa" << endl;
    }

    while (countD--)
    {
        dq.pop_front();
    }
   
    // vector<int> ans;
    // ans.clear();
    while (!dq.empty())
    {
        // ans.push_back(dq.front());
        cout << dq.front() << " ";
        dq.pop_front();
    }
    cout << endl;
    
    // printVector(ans);

}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        string cad;
        cin >> cad;
        int n;
        cin >> n;
        vector<int> arr(n);
        for (size_t i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        
        solve(cad,arr);
    }
    return 0;
}