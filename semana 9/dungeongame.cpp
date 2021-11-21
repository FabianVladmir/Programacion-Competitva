#include <bits/stdc++.h>
using namespace std;

//Dungeon Game

int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int rows=dungeon.size();
    if(rows==0)
        return 0;
    int cols=dungeon[0].size();
    vector<vector<int> > dp(rows,vector<int> (cols,0));
    dp[rows-1][cols-1]=max(1,1-dungeon[rows-1][cols-1]);
    
    for(int i=rows-2;i>=0;i--){
        dp[i][cols-1]=max(dp[i+1][cols-1]-dungeon[i][cols-1],1);
    }
    for(int i=cols-2;i>=0;i--){
        dp[rows-1][i]=max(dp[rows-1][i+1]-dungeon[rows-1][i],1);
    }
    
    for(int i=rows-2;i>=0;i--){
        for(int j=cols-2;j>=0;j--){
            int val1=max(dp[i+1][j]-dungeon[i][j],1);
            int val2=max(dp[i][j+1]-dungeon[i][j],1);
            dp[i][j]=min(val1,val2);
        }
    }
    return dp[0][0];
}

int main(){

    vector<vector<int>> dungeon{{-2,-3,3},{-5,-10,1},{10,30,-5}};

    return 0;
}