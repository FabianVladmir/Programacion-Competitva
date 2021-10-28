#include <bits/stdc++.h>
using namespace std;

//NESTING
bool validate(stack<char> &s, char c) {
    if (c == '(') {
        s.push(c);
    } else {
        if (c == ')' && s.top() == '(') {
            s.pop();
        } else {
            return false;
        }
    }
    
    return true;
}

int solution(string &S) {
    
    stack<char> s;
    int size = (int)S.size();
    for (int i = 0; i < size; i++) {
        if (!validate(s, S[i])) {
            return false;
        }
    }
    
    return s.size() == 0;
}