#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double double_tt;
#define PI = 4.0*atanl(1.0)

int 
main(int argc, char const *argv[])
{
    double_tt n;
    while (cin >> n && n != 0){
        bool flag = false;
        if (n < 0) flag = true;
        n = abs(n);
        for (ll i = sqrt(n)+1; i >= 1; i--){
            if (flag && i%2 == 0) continue;
            double_tt power = 1/double_tt(i);
            double_tt val = pow(n,power);
            double_tt diff = abs(val - floor(val));
            if (diff < .00001){
                cout << i << endl;
                break;
            }
        }
    }

    return 0;
}