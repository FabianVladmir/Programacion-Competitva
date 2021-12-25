
/*https://open.kattis.com/problems/oddmanout*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int N,X,dato;
    cin>>N;
    int T=0;
    while(T < N)
    {
        map<int, bool> gquiz1;

        cin>>X;
        while(X--)
        {   
            cin>>dato;
            map<int, bool>::iterator buscar;
            buscar = gquiz1.find(dato);
            if (buscar != gquiz1.end())
                gquiz1.erase(buscar);
            else
                gquiz1.insert(pair<int, bool>(dato, false));
        }
        cout << "Case #" << T + 1 << ": ";
        for (auto itr = gquiz1.begin(); itr != gquiz1.end(); ++itr) {
            cout << itr->first
             << '\n';
        }
        T++;
    }
    return 0;
}