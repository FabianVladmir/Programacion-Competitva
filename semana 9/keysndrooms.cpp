#include <bits/stdc++.h>
using namespace std;

//keys and rooms    

void dfs(vector<vector<int>>& rooms, int key, int visited[])
{
    visited[key]=true;
    for(int i=0;i<rooms[key].size();i++)
    {
        if(!visited[rooms[key][i]])
        {
            dfs(rooms,rooms[key][i],visited);
        }
    }
}

bool canVisitAllRooms(vector<vector<int>>& rooms) {
    int n=rooms.size();
    int visited[n];
    
    memset(visited,0, sizeof visited);
    
    dfs(rooms, 0, visited);
    
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            return false;
        }
    }
    return true;
}


int main(){

    vector<vector<int>> room{{},{},{},{}};
    cout << canVisitAllRooms(room) << endl;
    
    return 0;
}