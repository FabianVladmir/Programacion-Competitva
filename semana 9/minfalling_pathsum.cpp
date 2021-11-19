#include <bits/stdc++.h>
using namespace std;

//Minimum Falling Path Sum
int minFallingPathSum(vector<vector<int>>& mat) {
    int n = mat.size();
    
    int ans = INT_MAX;
    
    for(int i = 1; i < n; i++){
        for(int j = 0; j < n; j++){
            int temp = mat[i-1][j];
            if(j > 0)
                temp = min(temp, mat[i-1][j-1]);
            if(j < n-1)
                temp = min(temp, mat[i-1][j+1]);
            
            mat[i][j] = temp + mat[i][j];
        }
    }
    
    for(int j = 0; j < n; j++){
        ans = min(ans, mat[n-1][j]);
    }
    
    return ans;
}

int main(){

    vector<vector<int>> matrix = {{2,1,3},{6,5,4},{7,8,9}};
    cout << minFallingPathSum(matrix) << endl;

    return 0;
}
