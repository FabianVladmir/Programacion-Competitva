#include <bits/stdc++.h>
using namespace std;

/*https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/*/
static unordered_set<string> ops({"+", "-", "*", "/"});

int evalRPN(vector<string>& tokens) {
    stack<int> stack;
    for (auto t : tokens) {
        if (ops.find(t) == ops.end()) 
            stack.push(stoi(t));
        else {
            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();
            if (t == "+") stack.push(a + b);
            else if (t == "-") stack.push(a - b);
            else if (t == "*") stack.push(a * b);
            else stack.push(a / b);
        }
    }
    return stack.top();
}

int main(){

    vector<string> token = {"2","1","+","3","*"};
    int ans = evalRPN(token);
    cout << ans << endl;

    vector<string> token2 = {"4","13","5","/","+"};
    int ans2 = evalRPN(token2);
    cout << ans2 << endl;
    
    vector<string> token3 = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    int ans3 = evalRPN(token3);
    cout << ans3 << endl;

    return 0;
}