#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

const int CON = 40005;
int B,E,P,N,M;
int distB[CON],distE[CON],distP[CON];
vector<vector<int>> adj(CON);
vector<bool> vis(CON);

void bfsB(int start){
  fill(vis.begin(),vis.end(),0);
  queue<int> q;
  q.push(start);

  vis[start] = true;

  while(!q.empty()){

    int node = q.front();q.pop();

    for(int child : adj[node]){
   
      if(vis[child]) continue;

      q.push(child);
      vis[child] = true;
      distB[child] = distB[node] + 1;

    }

  }

}
void bfsE(int start){
  fill(vis.begin(),vis.end(),0);
  queue<int> q;
  q.push(start);
  vis[start] = 1;

  while(!q.empty()){

    int node = q.front();q.pop();
    for(int child :adj[node]){
      
      if(vis[child]) continue;

      q.push(child);
      vis[child] = true;
      distE[child] = distE[node] + 1;

    }

  }

}

void bfsP(int start){
  fill(vis.begin(),vis.end(),0);
  queue<int> q;
  q.push(start);
  vis[start] = 1;

  while(!q.empty()){

    int node = q.front();q.pop();
    for(int child:adj[node]){

      if(vis[child]) continue;

      q.push(child);
      vis[child] = 1;
      distP[child] = distP[node] + 1;

    }

  }

}



int main(){

  cin.tie(0)->sync_with_stdio(0);
  freopen("piggyback.in","r",stdin);
  freopen("piggyback.out","w",stdout);

  cin >> B >> E >> P >> N >> M;
  for(int i = 0;i<M;i++){
    int a,b;cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  bfsB(1);
  bfsE(2);
  bfsP(N);


  long long ans = LLONG_MAX;
  for(int i = 1;i<=N;i++){
  long long sum = 1LL*B*distB[i] + 1LL*E*distE[i] + 1LL*P*distP[i];
  ans = min(sum,ans);
  }
  cout << ans << endl;
    
 
 
  
  return 0;
}
