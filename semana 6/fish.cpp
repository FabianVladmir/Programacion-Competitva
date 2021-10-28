#include <bits/stdc++.h>
using namespace std;
//FISH

int solution(vector<int> &A, vector<int> &B) {
    
    stack<int> s;
    int size = (int)A.size(), cnt = 0;
    for (int i = 0; i < size; i++) {
        if (B[i] == 1) {
            s.push(A[i]);
        } else {
            while (s.size() != 0) {
                if (A[i] > s.top()) {
                    s.pop();
                } else {
                    break;
                }    
            }
            if (s.size() == 0) {
                cnt++;
            }
        }
    }
    
    return cnt + s.size();
}