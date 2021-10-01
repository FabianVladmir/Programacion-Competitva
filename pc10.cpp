#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, num, cont = 0;
    cin >> n >> k;

    while (n--)
    {
        cin >> num;
        if (num % k == 0)
            ++cont;
    }
    cout << cont << '\n';

    return 0;
}