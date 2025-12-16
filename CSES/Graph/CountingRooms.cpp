#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int R,C;
const int CONS = 1000;
char grid[CONS][CONS];
bool visited[CONS][CONS];
int cnt = 0;

void floodfill(int r,int c){

    if(r < 0 || r >= R || c < 0 || c >= C) return;
    if(visited[r][c]) return;
    if(grid[r][c] == '#') return;

    visited[r][c] = true;

    floodfill(r+1,c);
    floodfill(r-1,c);
    floodfill(r,c+1);
    floodfill(r,c-1);

    return;
}

int main(){

    cin >> R >> C;
    for(int i = 0;i<R;i++){
        for(int j = 0;j<C;j++){
            cin >> grid[i][j];
        }
    }

    for(int i = 0;i<R;i++){
        for(int j = 0;j<C;j++){
            if(!visited[i][j] && grid[i][j] == '.'){
                cnt++;
                floodfill(i,j);
            }
        }
    }

    cout << cnt << endl;

    return 0;
}
