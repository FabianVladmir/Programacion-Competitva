#include <bits/stdc++.h>
using namespace std;
//BRACKETS
static unordered_set<char> ops({'{', '(', '['});

bool validate(stack<char> &s, char input) {
    if (ops.find(input) == ops.end())
        {
        s.push(input);    
        return true;  
        }

    else {
        char c = s.top();
        if ((c == '{' && input == '}') ||
            (c == '(' && input == ')') ||
            (c == '[' && input == ']')) {
            s.pop();
            return true;  
        } 
    }
    return false;
}

int solution(string &S) {
    
    int n = S.size();
    stack<char> st;
    for (int i = 0; i < n; i++) {
        if (!validate(st, S[i])) {
            return false;
        }
    }
    
    return st.size() == 0;
}