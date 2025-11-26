#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

/*

    Author:Navy
    Sol: floodfill with some adjusting

*/




int N;
const int CONS = 1000;
char  grid[CONS+5][CONS+5];
bool  visited[CONS+5][CONS+5];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int area,peri;
int amx,pmx;

void ff(int r,int c){

    if(r < 0 || c < 0 || r >= N || c >= N || grid[r][c] == '.'){
        peri++;
        return;
    }
    if(visited[r][c]) return;


    visited[r][c] = true;
    area++;

    for(int i = 0;i<4;i++){
        ff(r+dx[i],c+dy[i]);
    }
    


}

void setIO(string s){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  if(!s.empty()){
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
  }
}


int main(){

    setIO("perimeter");

    cin >> N;
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            cin >> grid[i][j];
        }
    }
    bool take = false;

    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            if(!visited[i][j] && grid[i][j] == '#'){
                area = peri = 0;
                //reset the counting system
                
                ff(i,j);

                if(!take){
                    amx = area;
                    pmx = peri;
                    take = true;
                }

                if(area > amx){
                    amx = area;
                    pmx = peri;
                }else if(area == amx){
                    pmx = peri;
                }
            
            }
        }
    }

    cout << amx << " " << pmx << endl;


    return 0;
}
