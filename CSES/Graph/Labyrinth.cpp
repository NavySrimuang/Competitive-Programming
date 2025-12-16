#include<bits/stdc++.h>
#define endl '\n'
using namespace std;


/*

  Author:Navy
  SOL: bfs on grid

*/

int dy[] = {1,-1,0,0},dx[] = {0,0,-1,1};
char dir[] = {'D','U','L','R'};

const int CON = 1005;
char grid[CON][CON],par[CON][CON];
bool vis[CON][CON];
int dist[CON][CON];


int main(){

  int N,M;cin >> N >> M;
  
  int sr,sc,er,ec;

  for(int i = 0;i<N;i++){
    for(int j = 0;j<M;j++){
      char c;cin >> c;
      if(c == 'A'){
        sr = i;sc = j;
      }else if(c == 'B'){
        er = i; ec = j;
      }
      grid[i][j] = c;
    }

  }


  queue<pair<int,int>> q;
  q.push({sr,sc});
  vis[sr][sc] = true;
  
  while(!q.empty()){

    pair<int,int> cell = q.front();
    int r = cell.first;
    int c = cell.second;
    q.pop();

    for(int i = 0;i<4;i++){

      int nr = r + dy[i];
      int nc = c + dx[i];

      if(nr < 0 || nc < 0 || nr >= N || nc >= M || grid[nr][nc] == '#' || vis[nr][nc]) continue;

      q.push({nr,nc});
      vis[nr][nc] = true;
      dist[nr][nc] = dist[r][c] + 1;
      par[nr][nc] = dir[i];
    }

  }

if(!dist[er][ec]){
  cout << "NO\n";
}else{
  cout << "YES\n";
  cout << dist[er][ec] << endl;
  //print the path
  int row = er,col = ec;
  string path = "";
  while(!(row == sr && col == sc)){
    char d = par[row][col];
    path += d;
    if(d == 'U'){
      row++;
    }else if(d == 'D'){
      row--;
    }else if(d == 'L'){
      col++;
    }else{
      col--;
    }

  }
  reverse(path.begin(),path.end());
  cout << path << endl;
}

/*

........
.L..URR. 1,2
.D..U.U.
.DRRRRR.
........


*/


// for(int i = 0;i<N;i++){
//   for(int j = 0;j<M;j++){
//     if(par[i][j] == '\0'){
//       cout << '.';
//     }else{
//       cout << par[i][j];
//     }
//   }
//   cout << endl;
// }


  return 0;
}
