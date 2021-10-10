/*
https://www.spoj.com/problems/CODFURY/
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int p,m;
        cin >> p >> m;
        vector<int> arr(p+5);
        int flag=0;
        long long sum=0,maxx=-1,total=99999999;
        vector<int> prefixSum(p+5);
        prefixSum[0]=0;
        for(int i=1;i<=p;i++)
        {
            cin >> arr[i];
            sum+=arr[i];
            prefixSum[i] =sum;
        }

        int temp1=0;
        sum=0;
        for(int i=1;i<=p;i++)
        {
            if(flag==1)
                i--;
            sum= prefixSum[i] - prefixSum[temp1];
            flag=0;
            if(sum>m)
            {
                flag=1;
                temp1++;
            }
            if(maxx<(i-temp1)){
                maxx=(i-temp1);
                total = sum;
            }
            else if(maxx==(i-temp1))
            {
                if(total>sum)
                    total=sum;
            }
        }
        if(maxx==0)
            total=0;
            
        if(total==99999999)
            cout << "0 0\n";
        else
            cout << total << " " << maxx;
    }
    return 0;
}