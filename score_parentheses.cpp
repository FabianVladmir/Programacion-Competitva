#include <bits/stdc++.h>
using namespace std;

/*https://leetcode.com/problems/score-of-parentheses/*/

int scoreOfParentheses(string s) {
    int score=0;
    stack<int> st;
    
    for(char &c: s){
        if(c=='('){
            st.push(score);
            score = 0;
        }else{
            score = st.top() + max(score*2, 1);
            // score = max(score * 2, 1);
            st.pop();
        }
    }
    return score;
}

int main(){

    string cad = "(())";
    int ans = scoreOfParentheses(cad);
    cout << ans << endl;

    string cad2 = "()";
    int ans2 = scoreOfParentheses(cad2);
    cout << ans2 << endl;

    string cad3 = "()()";
    int ans3 = scoreOfParentheses(cad3);
    cout << ans3 << endl;

    string cad4 = "(()(()))";
    int ans4 = scoreOfParentheses(cad4);
    cout << ans4 << endl;


    return 0;
}