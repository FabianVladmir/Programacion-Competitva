# include <bits/stdc++.h>
using namespace std;

// https://open.kattis.com/problems/narrowartgallery

typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<bool, bool> pbb;
typedef pair<pll, pbb> pllbb; 
map<pllbb, ll> BUFFER;
bool operator<(const pllbb& s1, const pllbb& s2) 
{return tie(s1.first.first, s1.first.second) < tie(s2.first.first, s2.first.second);}
bool operator==(const pllbb& s1, const pllbb& s2) 
{return tie(s1.first.first, s1.first.second) == tie(s2.first.first, s2.first.second);}

# define INFFF 99999999

ll __Solution__(vector<pll>& v, int n, pllbb s) 
{
    if(BUFFER.count(s) > 0) {return BUFFER[s];}
    ll needed = s.first.first;
    ll spot = s.first.second;
    bool prevl = s.second.first;
    bool prevr = s.second.second;
    if(spot >= n) {
        if(needed <= 0) return 0;
        else return -INFFF;
    }
    ll lval = v[spot].first;
    ll rval = v[spot].second;
    ll fback = -INFFF;
    if(needed <= 0) {
        pllbb next = {{needed, spot+1} ,{true, true}};
        fback = lval + rval + __Solution__(v, n, next);
        BUFFER[s] = fback;
        return fback;
    }
    if(prevl) {
        pllbb next = {{needed-1, spot+1} , {true, false}};
        fback = max(fback, lval + __Solution__(v, n, next));
    }
    if(prevr) {
        pllbb next = {{needed-1, spot+1}, {false, true}};
        fback = max(fback, rval + __Solution__(v, n, next));
    }
    pllbb next = {{needed, spot+1}, {true, true}};
    fback = max(fback, lval + rval + __Solution__(v, n, next));
    BUFFER[s] = fback;
    return fback;
}

int main(int argc, char const *argv[])
{
    ll n, m;
    while(cin >> n && cin >> m){
        if (n == 0 && m == 0) break;
        vector<pll> v(n);
        for (auto &i : v) {cin >> i.first >> i.second;}
        BUFFER.clear();
        pllbb s = {{m, 0}, {true, true}};
        cout << __Solution__(v, n, s) << '\n';
    }

    return EXIT_SUCCESS;
}