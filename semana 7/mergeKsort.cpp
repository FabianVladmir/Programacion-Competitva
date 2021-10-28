#include <bits/stdc++.h>
using namespace std;
//MERGE K SORT

void solve(vector<vector<int>> &list){

    priority_queue<int,vector<int>, greater<int>> pq; 

    for(auto &i : list){
        for(auto &j : i){
            pq.push(j);
        }
    }

    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();

    }
    
}


int main(){

    vector<vector<int>> list{{1,4,5}, {1,3,4},{2,6}};
    solve(list);

    return 0;
}