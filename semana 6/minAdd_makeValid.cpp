#include <bits/stdc++.h>
using namespace std;

/*https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/*/
int minAddToMakeValid(string s) {
        
    if(s.size() == 0) return 0;
    stack<char> st;
    int ans = 0;
    for(auto it : s){
        if(it == '(')
            st.push(it);
        
        else{
            if(!st.empty() && it == ')')
                st.pop();
            else
                ans++;
        }
    }
    // cout << st.size() << endl;
    return ans+st.size();
}

int main(){

    string cad = "())";
    string cad2 = "(((";
    int ans = minAddToMakeValid(cad);
    cout << ans << endl;
    int ans2 = minAddToMakeValid(cad2);
    cout << ans2 << endl;


    return 0;
}