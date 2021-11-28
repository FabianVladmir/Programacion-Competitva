#include <bits/stdc++.h>
#include <cstdio>


using namespace std;

long long fib(long long n) {
  double phi = (1 + sqrt(5)) / 2;
  return round(pow(phi, n) / sqrt(5));
}
 

int main() {
    long long a, b, n;
    long long num;

    while(true) {
        num = 0;

        cin>>a>>b>>n;
        if((a == 0 && b == 0 && n == 0))
            break;

        for(int cont = 0 ; cont < n; cont++) {
            num += fib(a) * fib(b);
            a++;b++;
        }
        printf("%d\n",num);
    }

    return 0;
}