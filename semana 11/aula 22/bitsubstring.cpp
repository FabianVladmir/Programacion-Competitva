
#include <bits/stdc++.h>
using namespace std;

int kOnes(string s, int K)
{
	int n = s.length();
	int res = 0;
	int countOfOne = 0;
	vector<int> freq(n+1);
	
	freq[0] = 1;
	
	for (int i = 0; i < n; i++) {
		
		countOfOne += (s[i] - '0');
		
		if (countOfOne >= K) {

			res += freq[countOfOne - K];
		}

		freq[countOfOne]++;
	}
	return res;
}

int main()
{
	string s;
    cin >> s;
	// int k = std::stoi(s, nullptr, 2);
    
	// --k;
    long int n = s.size() + 1;
    vector<long int> ans;
	while(n--){
        long int temp;
	    temp = kOnes(s, n);
        ans.push_back(temp);
        // cout << temp << endl;
	}
    
    reverse(ans.begin(), ans.end());
    
    for(auto indx : ans){
        cout << indx << " ";
    }
    cout << endl;

	return 0;
}