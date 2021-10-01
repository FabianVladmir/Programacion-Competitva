#include <bits/stdc++.h>
using namespace std;
bool isAnagram(string a, string b){

    if(a.size() != b.size())
        return false;
    
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    for (size_t i = 0; i < a.size(); i++)
    {
        if(a[i] != b[i])
            return false;
    }    
    return true;
}


int main(){

    string n = "cat";
    string m = "tac";

    bool ans = isAnagram(n,m);
    cout << ans << endl;

    return 0;
}