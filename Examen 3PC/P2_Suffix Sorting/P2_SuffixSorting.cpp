//https://open.kattis.com/problems/suffixsorting
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

class SuffixArray {
   private:
    vi RA;  

    void countingSort(int k) {               
        int maxi = max(300, n);             
        vi c(maxi, 0);                       
        for (int i = 0; i < n; ++i)         
            ++c[i + k < n ? RA[i + k] : 0];  
        for (int i = 0, sum = 0; i < maxi; ++i) {
            int t = c[i];
            c[i] = sum;
            sum += t;
        }
        vi tempSA(n);
        for (int i = 0; i < n; ++i)  
            tempSA[c[SA[i] + k < n ? RA[SA[i] + k] : 0]++] = SA[i];
        swap(SA, tempSA);  
    }

    void constructSA() {  
        SA.resize(n);
        iota(SA.begin(), SA.end(), 0); 
        RA.resize(n);
        for (int i = 0; i < n; ++i) RA[i] = T[i];  
        for (int k = 1; k < n; k <<= 1) {          
          
            countingSort(k);  
            countingSort(0);  
            vi tempRA(n);
            int r = 0;
            tempRA[SA[0]] = r;           
            for (int i = 1; i < n; ++i)  
                tempRA[SA[i]] =          
                    ((RA[SA[i]] == RA[SA[i - 1]]) && (RA[SA[i] + k] == RA[SA[i - 1] + k])) ? r
                                                                                           : ++r;
            swap(RA, tempRA);                   
            if (RA[SA[n - 1]] == n - 1) break;  
        }
    }

   public:
    const char* T;  
    const int n;    
    vi SA;          

    SuffixArray(const char* initialT, const int _n) : T(initialT), n(_n) {
        constructSA();  
    }
};

#define MAX_N 200000
char s[MAX_N];

int main() {
    while (cin.getline(s, MAX_N)) {
        
        int n = strlen(s);
        
        s[n++] = char(9);
        SuffixArray sa(s, n);

        int num_q, q;
        cin >> num_q;
        for (int q_num = 0; q_num < num_q; q_num++) {
            cin >> q;
            if (q_num > 0) cout << " ";
            cout << sa.SA[q + 1];
        }
        cout << endl;

        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        memset(s, 0, sizeof(s));
    }

    return 0;
}