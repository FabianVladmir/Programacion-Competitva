#include <bits/stdc++.h>
using namespace std;

//STONEWALL

int solution(vector<int> &H) {
   
    stack<int> s;
    int size = (int)H.size(), cnt = 0;
    for (int i = 0; i < size; i++) {
        while (s.size() != 0 && s.top() > H[i]) {
            s.pop();
        }
        
        if (s.size() != 0 && H[i] == s.top()) {
            continue;
        } else {
            s.push(H[i]);
            cnt++;
        }
    }
    return cnt;
}