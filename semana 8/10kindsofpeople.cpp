#include <bits/stdc++.h>
using namespace std;

//10 kinds of people
void printVectorofVector(vector<vector<int>> &nums){
    int m = nums.size();
    int n = nums[0].size();
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            cout << nums[i][j] << " ";
        }
        cout << endl;
        
    }
    
}


vector<pair<int,int>> dir {{0,1},{1,0},{0,-1},{-1,0}};

void solve(vector<vector<int>> &edge, int startX, int startY, int endX, int endY){

    int m = edge.size();
    int n = edge[0].size();
    
    int visited[1000][1000][1000] = {};
    int start = edge[startX][startY];
    int end = edge[endX][endY];

    bool decimal;
    if(start)
        decimal = true;
    else
        decimal = false;


    queue<vector<int>> q;
    q.push({startX,startY});
    while (!q.empty())
    {
        int sz=q.size();
        while (sz--)
        {
            auto curr = q.front(); q.pop();

            if(curr[0] == endX && curr[1] == endY){
                if(decimal)
                    cout << "decimal\n";
                else
                    cout << "binary\n";
            }
            
            for(auto it : dir){
                
                int i = curr[0] + it.first;
                int j = curr[1] + it.second;
                int obs = curr[2];

                if(i >= 0 && i < m && j >=0 && j < n ){

                    if(edge[i][j] && !visited[i][j][obs]){
                        q.push({i,j,obs});
                        visited[i][j][obs] = true;
                    }
                    else if(edge[i][j] == 1 && decimal)
                        obs++;
                    
                    else if (edge[i][j] == 0 && !decimal)
                    {
                        obs++;
                    }                    
                }       

            }
        }        
    }
    cout << "neither\n";
    return;

}



int main(){

    int r,c;
    cin >> r >> c;

    vector<vector<int>> gird(r, vector<int>(c));
    for (size_t i = 0; i < r; i++)
    {
        for (size_t j = 0; j < c; j++)
        {
            cin >> gird[i][j];
        }
        
    }

    // vector<vector<int>> gird{{1},{1},{0},{0}};


    // printVectorofVector(gird);
    int n;
    cin >> n;
    while (n--)
    {
        int r1,c1,r2,c2;
        cin >> r1 >> c1 >> r2 >> c2;

        solve(gird,r1-1,c1-1,r2-1,c2-1);
    }

    return 0;
}
