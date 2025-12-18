#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

/*

  Author: Navy
  SOL: BNS on Weight(cuz want min-max) and check if that weight is usable by using component id

*/



const int con = 1e5;
int N,M;
vector<int> pos;
vector<array<int,3>> hole; // a , b , w

vector<vector<int>> adj(con+1);
vector<int> comp(con + 1);

void dfs(int node,int id){

  comp[node] = id;

  for(int child: adj[node]){

    if(comp[child] == -1){
      dfs(child,id);
    }

  }

}


bool can(int w){

  //make graph at least w weight
  adj.assign(N+1,{});

  for(int i = 0;i<M;i++){
    if(hole[i][2] >= w){
      adj[hole[i][0]].push_back(hole[i][1]);
      adj[hole[i][1]].push_back(hole[i][0]);
    }
  }

  int comp_id = 0;
  comp.assign(N+1,-1);

  for(int i = 1;i<=N;i++){
    if(comp[i] == -1){
      comp_id++;
      dfs(i,comp_id);
    }
  }

  for(int i = 1;i<=N;i++){
    if(comp[i] != comp[pos[i]]) return false;
  }
  return true;

}



int main(){

  cin.tie(0)->sync_with_stdio(0);
  freopen("wormsort.in","r",stdin);
  freopen("wormsort.out","w",stdout);

  cin >> N >> M;
  pos.resize(N+1);
  bool sorted = 1;
  for(int i = 1;i<=N;i++){
    cin >> pos[i];
    if(pos[i] != i) sorted = false;
  }

  if(sorted){
    cout << -1 << endl;
    return 0;
  }


  int mxw = INT_MIN;
  hole.resize(M);
  for(int i = 0;i<M;i++){
    
    cin >> hole[i][0] >> hole[i][1] >> hole[i][2];
    mxw = max(mxw,hole[i][2]);
    
  }
  

  int lo = 0,hi = mxw;
  int ans = 0;
  while(lo <= hi){
    
    int mid = lo + (hi-lo)/2;

    if(can(mid)){
      ans = mid;
      lo = mid + 1;
    }else{
      hi = mid - 1;
    }

  }

  cout << ans << endl;


  return 0;
}
