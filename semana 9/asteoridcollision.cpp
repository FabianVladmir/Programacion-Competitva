#include <bits/stdc++.h>
using namespace std;

//asteroidcollision

vector<int> asteroidCollision(vector<int>& a) {
    vector<int> s; // use vector to simulate stack.
    for (int i : a) {
        while (!s.empty() && s.back() > 0 && s.back() < -i)
            s.pop_back();
        if (s.empty() || i > 0 || s.back() < 0)
            s.push_back(i);
        else if (i < 0 && s.back() == -i)
            s.pop_back();
    }
    return s;
} 

int main(){

    vector<int> asteroid{5,10,-5};
    vector<int> ans;
    asteroidCollision(asteroid);
    for(int i: ans)
        cout << i << " ";
    cout << endl;
    return 0;
}
    