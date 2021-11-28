#include <bits/stdc++.h>
using namespace std;
//https://www.beecrowd.com.br/judge/en/problems/view/1642
#define tam_ascii 128
int m;
int temp = 0;
int temp2 = 0;
int solve(string texto,int ans = 0){

    int begin = 0;
    int end = m-1;
    int arr[tam_ascii];    
    int sizecad = texto.length();    
    
    for (int i = 0; i < tam_ascii; ++i)
        arr[i] = 0;


    for (int i = 0; i < m; ++i){
        if(arr[texto[i]] == 0){
            temp++;
        }
        arr[texto[i]]++;
    }
    while(end < sizecad-2){

        while(temp <= m && (end < sizecad-2))
        {
            end++;
            
            if(arr[texto[end]] == 0){
                temp++;
            }

            arr[texto[end]]++;
        }
        
        if(temp > m){
            begin++;
        }

        if((end - begin + 1) > ans){
            ans = end - begin + 1;
        }

        if(arr[texto[begin-1]] > 0){
            arr[texto[begin-1]]--;
            temp2 = arr[texto[begin-1]];
            if(temp2 == 0){
                temp--;
            }
        }
    }
    temp = temp2 = 0;
    return ans;
}

int main()
{
    while(true){

        int len = 0;
        cin>>m;
        
        char txt[1000010];
        
        if(m != 0){
          cin.ignore();
          //std::getline(std::cin, txt);
          if(fgets(txt,1000010, stdin) != NULL){
            len = solve(txt,len);
          }
            printf("%d\n", len);
        }
        else{            
            break;
        }
    }
    return 0;
}