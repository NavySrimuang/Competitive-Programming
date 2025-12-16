#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

/*

  Author:Navy
  SOL: bfs all monster at the same time by pushing all of them in to queue
        bfs the person for shortest path
        -> then check if the person is nearer to the exit than the monster
  
*/


bool ok = false;
bool mmove = false;
const int CON = 1005;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
char dir[] = {'L','R','U','D'};
char grid[CON][CON],par[CON][CON];
int mdist[CON][CON],pdist[CON][CON];
bool mvis[CON][CON],pvis[CON][CON];
int N,M;
queue<pair<int,int>> mq,q;
int ar,ac,sr,sc;
int main(){

  cin >> N >> M;
  for(int i = 0;i<N;i++){
    for(int j = 0;j<M;j++){
      char c;cin >> c;
      if(c == 'M'){
        mq.push({i,j});
        mvis[i][j] = 1;
      }
      else if(c == 'A'){
        sr = i;sc = j;
        q.push({i,j});
        pvis[i][j] = 1;

        //edge case
        if(i == 0 || j == 0 || i == N-1 || j == M-1){
          cout << "YES\n0";
          return 0;
        }

      }

      grid[i][j] = c;

    }
  }
 
  while(!mq.empty()){
    pair<int,int> cell = mq.front();mq.pop();
    int r = cell.first;
    int c = cell.second;

    for(int i = 0;i<4;i++){
      int nr = r + dy[i];
      int nc = c + dx[i];


      if(nr < 0 || nc < 0 || nr >= N || nc >= M || grid[nr][nc] == '#' || grid[nr][nc] == 'M' || mvis[nr][nc]) continue;

      mmove = 1;
      mq.push({nr,nc});
      mvis[nr][nc] = 1;
      mdist[nr][nc] = mdist[r][c] + 1;
  }

  }


  while(!q.empty()){

    pair<int,int> cell = q.front();q.pop();
    int r = cell.first;
    int c = cell.second;

    for(int i = 0;i<4;i++){
      int nr = r + dy[i];
      int nc = c + dx[i];


      if(nr < 0 || nc < 0 || nr >= N || nc >= M || grid[nr][nc] == '#' || grid[nr][nc] == 'M' || pvis[nr][nc]) continue;

      q.push({nr,nc});
      pvis[nr][nc] = 1;
      pdist[nr][nc] = pdist[r][c] + 1;
      par[nr][nc] = dir[i];

      if(nr == 0 || nc == 0 || nr == N-1 || nc == M-1 &&(grid[nr][nc] == '.')){
        if(((pdist[nr][nc] < mdist[nr][nc]) && mdist[nr][nc] > 0) || !mmove){

          //valid
          ok = true;
          ar = nr;
          ac = nc;

        }
      }

    }


  }


  if(!ok){
    cout << "NO" << endl;
  }else{
    cout << "YES" << endl;
    cout << pdist[ar][ac] << endl;
    int r = ar;
    int c = ac;
    string path = "";
    while(!(r == sr && c == sc)){
      char d = par[r][c];
      path += d;
      if(d == 'R') c--;
      else if(d == 'D')r--;
      else if(d == 'U')r++;
      else c++;
    }
    reverse(path.begin(),path.end());
    cout << path << endl;
  }
  
  return 0;
}
