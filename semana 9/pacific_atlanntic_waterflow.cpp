#include <bits/stdc++.h>
using namespace std;

//Pacific Atlantic Water Flow
#define F first
#define S second
#define pii pair<int,int>

void get_ans_by_bfs(int m,int n,queue<pii>& q,vector<vector<bool>>& vis,vector<vector<int>>& grid)
{
    while(!q.empty())
    {
        int x = q.front().F;
        int y = q.front().S;
        q.pop();

        if(x+1<m and !vis[x+1][y] and grid[x][y]<=grid[x+1][y])
        {
            q.push({x+1,y});
            vis[x+1][y] = true;
        }
        if(x-1>=0 and !vis[x-1][y] and grid[x][y]<=grid[x-1][y])
        {
            q.push({x-1,y});
            vis[x-1][y] = true;
        }

        if(y+1<n and !vis[x][y+1] and grid[x][y]<=grid[x][y+1])
        {
            q.push({x,y+1});
            vis[x][y+1] = true;
        }

        if(y-1>=0 and !vis[x][y-1] and grid[x][y]<=grid[x][y-1])
        {
            q.push({x,y-1});
            vis[x][y-1] = true;
        }
    }
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix)
{

    vector<vector<int>> ans;

    int m = matrix.size();

    // base cases
    if(m==0)
        return ans;

    int n = matrix[0].size();
    if(n==0)
        return ans;

    vector<vector<bool>> pacific(m,vector<bool>(n,false));
    vector<vector<bool>> atlantic(m,vector<bool>(n,false));

    queue<pii> q;

    // do for pacific ocean

    for(int i=0;i<m;i++)
    {
        q.push({i,0});
        pacific[i][0] = true;
    }

    for(int i=0;i<n;i++)
    {
        q.push({0,i});
        pacific[0][i] = true;
    }

    get_ans_by_bfs(m,n,q,pacific,matrix);

    // do for atlantic ocean

    for(int i=0;i<m;i++)
    {
        q.push({i,n-1});
        atlantic[i][n-1] = true;
    }

    for(int i=0;i<n;i++)
    {
        q.push({m-1,i});
        atlantic[m-1][i] = true;
    }

    get_ans_by_bfs(m,n,q,atlantic,matrix);

    // push the cells where water can go to both the oceans

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(pacific[i][j] and atlantic[i][j])
                ans.push_back({i,j});
        }
    }

    return ans;      
}



int main(){



    return 0;
}