#include <bits/stdc++.h>
using namespace std;

//Unique Paths II
int uniquePathsWithObstacles(vector<vector<int>>& grid)
    {
        int row = grid.size();
        int col = grid[0].size();
 
        vector<vector<int>> dp(row,vector<int>(col,0));
  
        for(int i=0;i<row;i++)
        {
            if(grid[i][0])
                break;
 
            dp[i][0] = 1;
        }
 
        for(int i=0;i<col;i++)
        {
            if(grid[0][i])
                break;
 
            dp[0][i] = 1;
        }
 
        for(int i=1;i<row;i++)
        {
            for(int j=1;j<col;j++)
            {                
                if(grid[i][j])
                    continue; 
               
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
 
        return dp[row-1][col-1];
    }

int main(){

    vector<vector<int>> obstacleGrid{{0,0,0},{0,1,0},{0,0,0}};
    cout << uniquePathsWithObstacles(obstacleGrid) << endl;

    return 0;
}
