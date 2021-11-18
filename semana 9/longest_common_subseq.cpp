#include <bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(string text1, string text2) {
    int n = text1.size();
    int m = text2.size(); 
    vector<vector<int>> dp(n,vector<int>(m));       
    
    
    for(int i=1; i <= n; i++){
        for(int j=1; j <= m; j++){
            if(text1[i-1] == text2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    
    return dp[n][m];
}


//itertiva

// int lcs(string& text1 , string& text2 , int n , int m){
//     if(n==0 || m==0)
//         return 0;
    
//     if(text1[n-1] == text2[m-1])
//         return 1 + lcs(text1,text2,n-1,m-1);
    
//     return max(lcs(text1 , text2 , n-1,m) , lcs(text1,text2,n,m-1));
// }
    

// int longestCommonSubsequence(string text1, string text2) {
//     int n = text1.size();
//     int m = text2.size();
    
//     return lcs(text1 , text2 , n , m);
// }


int main(){

    string cad1= "abcde";
    string cad2 = "ace";
    int ans;
    cout << longestCommonSubsequence(cad1,cad2) << endl;

    return 0;
}


