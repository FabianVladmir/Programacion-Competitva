#include <bits/stdc++.h>
using namespace std;
//BACKSPACE

void solve(string cad){

    deque<char> dq;   
    
    for (size_t i = 0; i < cad.size(); i++)
    {
        char element = cad[i];
        if(element == '#')
            dq.pop_front();
        else{
            dq.push_front(element);
        }        
    }
    
    string str = "";
    while (!dq.empty())
    {
        str+=dq.front();        
        dq.pop_front();
    }
    
    reverse(str.begin(),str.end());
    cout << str << endl;

}


int main(){    
    string cad = "abc#de##f#ghi#jklmn#op#";
    solve(cad);

    return 0;
}