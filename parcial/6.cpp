/*
https://cses.fi/problemset/task/2420

https://cses.fi/problemset/result/2968221/
*/
#include <bits/stdc++.h>
using namespace std;

void update(string &cad, int k, char val){

    cad[k] = val;

}

bool isAlphaNumeric(char &c) {
    if ( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') ) {
        return true;
    }
    return false;
}

char toLower(char &c) {
    if (c >= 'A' && c <= 'Z') {
        return 'a' + (c - 'A'); 
    }
    return c;
}

bool isPalindrome(string cad, int start, int end){

    
    while (start < end) {
        while (start < end && !isAlphaNumeric(cad[start])) {
            ++start;
        }
        while (end > start && !isAlphaNumeric(cad[end])) {
            --end;
        }
        
        if (start >= end) {
            break;
        }
        
        if (toLower(cad[start++]) != toLower(cad[end--])) {
            return false;
        }
    }
    
    return true;

}


int main(){
 
    int n, q;
    cin >> n >> q;
    string cad;
    cin >> cad;
 
    while (q--)
    {
        int x;
        cin >> x;
        if(x==1){
            int y;
            char z;
            cin >> y >> z;
            update(cad,y-1,z);
        }

        if(x==2){
            int y, z;
            cin >> y >> z;

            if(!isPalindrome(cad,y-1,z-1)){
                cout << "NO" << endl;
            }
            else{
                cout << "YES" << endl;
            }
                
        }
    }
    
    return 0;
}