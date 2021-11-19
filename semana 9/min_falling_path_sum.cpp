#include <bits/stdc++.h>
using namespace std;

int minFallingPathSum(vector<vector<int>>& arr) {
    int n = arr.size();
    vector<vector<int> > dp(n,vector<int>(n,0));
    
    int min1 = INT_MAX, min2 = INT_MAX;
    
    for(int j = 0; j < n; j++){
        dp[0][j] = arr[0][j];
        if(dp[0][j] < min1){
            min2 = min1;
            min1 = dp[0][j];
        }
        else if(dp[0][j] < min2){
            min2 = dp[0][j];
        }
    }
    int new_min1 = INT_MAX, new_min2 = INT_MAX;    
    
    for(int i = 1; i < n; i++){
        for(int j = 0; j < n; j++){
            dp[i][j] = arr[i][j];
            if(dp[i-1][j] == min1)
                dp[i][j] += min2;
            else
                dp[i][j] += min1;
            if(dp[i][j] < new_min1){
                new_min2 = new_min1;
                new_min1 = dp[i][j];
            }
            else if(dp[i][j] < new_min2)
                new_min2 = dp[i][j];   
        }
        min2 = new_min2;
        min1 = new_min1;
            
        new_min1 = INT_MAX;
        new_min2 = INT_MAX;
    }
    return *min_element(dp[n-1].begin(),dp[n-1].end());
}

int main(){

    vector<vector<int>> matrix{{2,1,3},{6,5,4},{7,8,9}};
    cout << minFallingPathSum(matrix) << endl;

    return 0;
}