#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

/*

  Author:Navy
  SOL:from internal sol, normal backtracking would got TLE
        ideal sol_n -> try to dfs until it reach the same color then call it component 1;
                        do the same with next color and increment the component count;

                        then check if first one == c or include 2++ components -> have both color garunteed;

*/


int N,M;
const int mx = 1e5;
string s;
vector<vector<int>>adj(mx+1);
vector<int>cmp(mx+1); //cmp == components
int cmpcnt = 0;
void dfs(int node){

  if(cmp[node]) return;
  cmp[node] = cmpcnt;

  for(int child:adj[node]){
    if(!cmp[child] && s[node - 1] == s[child - 1]) dfs(child);
  }
  
}

int main(){

  cin.tie(0)->sync_with_stdio(0);
  freopen("milkvisits.in","r",stdin);
  freopen("milkvisits.out","w",stdout);

  cin >> N >> M;
  cin >> s;

  for(int i = 0;i<N-1;i++){
    int a,b;cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }


  for(int i = 1;i<=N;i++){
    if(cmp[i] == 0){
      cmpcnt++;
      dfs(i);
    }
  }

  while(M--){
    int a,b;char c;
    cin >> a >> b >> c;
    if(s[a-1] == c || cmp[a] != cmp[b] ) cout << 1; //diff cmp = have both color
    else cout << 0;
  }

  return 0;
}
