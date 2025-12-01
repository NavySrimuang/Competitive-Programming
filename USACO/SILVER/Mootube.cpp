#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

/*

  Author:Navy
  SOL: dfs to check if reachable when we wanna visit each node the relavance will already be min along the way
        I use .first for node and .second for pairs

*/


int N,Q,k,s;
const int mx = 5000+1;
vector<vector<pair<int,int>>>adj(mx);
vector<bool>visited(mx);
int cnt = 0;

void dfs(int node){

  if(visited[node]) return;
  visited[node] = true;

  for(auto child:adj[node]){
    if(!visited[child.first] && child.second >= k){
      cnt++;
      dfs(child.first);
    }  
  }


}

int main(){

  cin.tie(0)->sync_with_stdio(0);
  freopen("mootube.in","r",stdin);
  freopen("mootube.out","w",stdout);

  cin >> N >> Q;

  for(int i=1;i<N;i++){
    int a,b,c;cin >> a >> b >> c;
    adj[a].push_back({b,c});
    adj[b].push_back({a,c});
  }

  while(Q--){

    cin >> k >> s;
    fill(visited.begin(),visited.end(),false);
    cnt = 0;

    dfs(s);

    cout << cnt << endl;

  }



  return 0;
}
