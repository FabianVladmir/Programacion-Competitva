/*https://www.urionlinejudge.com.br/judge/en/problems/view/1077*/
#include <bits/stdc++.h>
using namespace std;

string infixToPosfix(string &cad){

    string ans = "";
    stack<char> st;

    for(auto it : cad){
        if(isalpha(it) && isdigit(it)){
            ans+=it;
        }
        else if(it == '(')
            st.push('(');
        
        else if(it == ')') {
            while(st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
 
        //If an operator is scanned
        else {
            while(!st.empty() && it <= st.top()) {
                ans += st.top();
                st.pop(); 
            }
            st.push(it);


        }
    }

    while(!st.empty()) {
        ans += st.top();
        st.pop();
    }

    return ans;
 
}

int main(){

    int n;
    cin >> n;
    while (n--)
    {
        string cad,ans;
        cin >> cad;
        ans=infixToPosfix(cad);
        cout << ans << endl;
    }
    
    return 0;
}
