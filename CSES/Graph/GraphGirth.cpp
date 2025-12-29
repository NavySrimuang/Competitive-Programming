#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

/*

  Author:Navy
  SOL: basic cycle detection and length = dist[child] + dist[node] + 1

*/
const int conN = 2500,conM = 5000;
vector<vector<int>> adj(conN+1);
vector<bool> vis(conN+1,0);
vector<int> dist(conN+1,0);
vector<int> par(conN+1,-1);

int mn = INT_MAX;
int n,m;

void bfs(int start){


  vis.assign(n+1,0);
  dist.assign(n+1,0);
  par.assign(n+1,-1);

  queue<int> q;
  q.push(start);
  vis[start] = 1;
  dist[start] = 0;
  while(!q.empty()){

    int node = q.front();
    q.pop();

    for(int child: adj[node]){
      if(!vis[child]){
        vis[child] = 1;
        par[child] = node;
        dist[child] = dist[node] + 1;
        q.push(child);
      }else if(child != par[node]){
        //found cycle
        mn = min(mn,dist[child] + dist[node] + 1);
      }

    }

  }

}


int main(){
  cin >> n >> m;

  while(m--){
    int a,b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for(int i = 1;i<=n;i++){
    bfs(i);
  }

  cout << (mn == INT_MAX ? -1:mn) << endl;



  return 0;
}
