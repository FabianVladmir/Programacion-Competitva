#include <bits/stdc++.h>
using namespace std;

void solve(int n){
    int shifts = 0;
    int elements = 0;
    cout << "{" ;
    while(n>0){
        if(n&1 == 1){
            if(elements == 0){
                cout << pow(3,shifts) << " ";
            }
            else{
                cout << ", " << pow(3,shifts) << " ";
            }
            elements++;
        }
        n >>=1;
        shifts++;
    }
    cout << "}";


}

int main(){
    while (true)
    {
        int n;
        cin >> n;
        if(n == 0)
            break;
        solve(n-1);
    }
    return 0;
}