#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int N;
const int MX = 2e5;
vector<vector<int>>adj(MX + 1);
vector<int>dist(MX+1);
void dfs(int node,int parent){

  if(parent != -1) dist[node] = dist[parent] + 1;

  for(int child: adj[node]){
    if(child != parent) dfs(child,node);
  }

}

int main(){

  cin >> N;
  for(int i = 0;i<N-1;i++){
    int a,b;cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  dfs(1,-1);

  int mx = -1,start = -1;

  for(int i = 1;i<= N;i++){
    if(dist[i] > mx){
      mx = dist[i];
      start = i;
    }
  }

  fill(dist.begin(),dist.end(),0);

  dfs(start,-1);

  for(int i = 1;i<=N;i++){
    mx = max(dist[i],mx);
  }

  cout << mx << endl;

  return 0;
}
