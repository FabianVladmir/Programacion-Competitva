//https://open.kattis.com/problems/fire2
#include <bits/stdc++.h>  
using namespace std;

typedef long long ll;
typedef vector<int> vi;

int test, weight, height;
vector<vector<char>> grid;
deque<tuple<int, int, int>> q1, q2; 
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> test;
    for (int tc=0;tc<test;tc++){
        cin >> weight >> height;
        grid.assign(height, vector<char>(weight, '.'));
        q1.clear();
        q2.clear();
        for (int r=0;r<height; r++){
            for (int c=0;c<weight;c++){
                cin >> grid[r][c];
                
                if (grid[r][c] == '@'){
                    q1.emplace_back(1, r, c);
                }
                else if (grid[r][c] == '*'){
                    q1.emplace_back(0, r, c);
                }
            }
        }

        int clock = 1;
        bool escaped = false;
        while (!(q1.empty() && q2.empty())){ 
            auto &pq = ((clock&1) ? q1 : q2); 
            auto &sq = ((clock&1) ? q2 : q1); 

            while(!pq.empty()){ 
                auto [type, r, c] = pq.front();
                
                pq.pop_front();

                for (int i=0;i<4;i++){
                    int nr = r + dr[i];
                    int nc = c + dc[i];

                    if (nc < 0 || nr < 0 || nc >= weight || nr >= height){
                        if (type == 1){
                            escaped = true;
                            break;
                        }
                        continue;
                    }

                    if (grid[nr][nc] == '#' || grid[nr][nc] == '*')continue;
                    if (type == 1 && grid[nr][nc] == '@') continue; 
                    grid[nr][nc] = ((type == 1) ? '@' : '*');

                    if (type == 1)
                        sq.emplace_back(type, nr, nc);
                    else
                        sq.emplace_front(type, nr, nc);
                }
                if(escaped)break;
            }

            if(escaped)break;
            clock++;
        }

        if (escaped){
            cout << clock << endl;
        }
        else{
            cout << "IMPOSSIBLE" << endl;
        }
    }
    return 0;
}