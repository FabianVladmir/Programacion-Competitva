#include <bits/stdc++.h>
using namespace std;

//Unique Paths
int uniquePaths(int m, int n) {
    vector<int> dp(n);
    dp[0] = 1; 
    for (int i = 0; i < m; i++) { 
        for (int j = 1; j < n; j++) { 
            dp[j] += dp[j - 1]; 
        } 
    } 
    return dp[n - 1]; 
}


int main(){

    int m=3;
    int n=7;
    cout << uniquePaths(m,n) << endl;

    return 0;
}