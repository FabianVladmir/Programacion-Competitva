#include <bits/stdc++.h>
using namespace std;

void printArray(vector<int> &arr){
    for (size_t i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    
}

int main() {

	int n,k;
    cin >> n >> k;

	vector<int> elements(n,0); 
        
	vector<int> diff(n, 0); 

    while (k--)
    {
        int A, B;
        cin >> A >> B;
        diff[A-1]++;
	    diff[B]--;      
                
    }   

    for (int i = 1; i < n; i++) {
        diff[i] += diff[i - 1];
        elements[i] += diff[i];
    }


	// printArray(elements);
    sort(elements.begin(),elements.end());
    int mid = n/2;
    cout << elements[mid] << endl;
	
	return 0;
}



// int main(){

//     int n, k;
//     cin >> n >> k;
//     vector<int> arr(n);
//     while (k--)
//     {
//         int A, B;
//         cin >> A >> B;
//         // if(A == B)
//         //     arr[A-1]++;

//         for (size_t i = A - 1; i <= B - 1 ; i++)
//         {
//             arr[i]++;
//         }
        
//         // printArray(arr);

//     }
//     printArray(arr);
//     cout << endl;
//     sort(arr.begin(), arr.end());

//     int mid = n/2;    
//     cout << arr[mid];
//     return 0;
// }