#include <bits/stdc++.h>
using namespace std;

//Domino and Tromino Tiling

int numTilings(int n) {
    
    long one[n + 1];      
    
    long both[n + 1];
    
    one[0] = 1L;
    both[0] = 1L;
    one[1] = 0L;
    both[1] = 1L;
    
    for (int i = 2; i <= n; i++) {
        one[i] = (both[i-2] + one[i-1]) % 1000000007L;
        both[i] = (both[i-1] + both[i-2] + 2 * one[i-1]) % 1000000007L;
    }
    
    return static_cast<int>(both[n]);
}

int main(){
    int n = 5;
    cout << numTilings(n) << endl;
    return 0;
}