#include<bits/stdc++.h>
using namespace std;

//https://cses.fi/problemset/task/1744
// int main()
// {
//     int x, y;
//     cin >> x >> y;
//     int ans = 0;
//     while (x != y)
//     {
//         if (x > y)
//         {
//             x -= y;
//         }
//         else
//         {
//             y -= x;
//         }
//         ans++;
//     }

//     cout << ans << "\n";
// }

vector<vector<int>> dp(502,vector<int>(502,0));
void solve(){
    int a,b;
    cin >> a >> b;
    if (a>b) 
        swap(a,b);
    
    for (int i = 1; i < a+1; i++)
    {
        for (int j = i+1; j < b+1; j++)
        {
            dp[i][j] = INT_MAX;

            for (int k = 1; k < j; k++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[i][j-k]+1);
            }
            
            for (int k = 1; k < i; k++)
            {
                dp[i][j] = min(dp[i][j], dp[k][j]+dp[i-k][j]+1);
            }
            dp[j][i] = dp[i][j];
        }
        
    }
    cout << dp[a][b];
    
}

int main(){    

    solve();
    cout << endl;

    return 0;
}



