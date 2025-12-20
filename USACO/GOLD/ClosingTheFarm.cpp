#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

/*

  Author:Navy
  SOL: rebuild and connect based on the opening farm just like internol Sol

*/


const int con = 2e5;
int N,M;

vector<vector<int>> adj(con);
vector<bool> stillopen(con,0);

struct DSU{

  vector<int> par,sz;

  DSU(int n){
    par.resize(n);
    sz.resize(n,1);
    iota(par.begin(),par.end(),0);
  }

  int find(int x){
    if(par[x] == x) return x;
    else return par[x] = find(par[x]);
  }

  bool unite(int a,int b){
    int ra = find(a);
    int rb = find(b);

    if(ra == rb) return 0;

    if(sz[ra] < sz[rb]) swap(ra,rb);
    sz[ra] += sz[rb];
    par[rb] = ra;
    return 1;
  }

};

int main(){

  cin.tie(0)->sync_with_stdio(0);
  freopen("closing.in","r",stdin);
  freopen("closing.out","w",stdout);

  cin >> N >> M;
  DSU dsu(N);
  while(M--){
    int a,b;cin >> a >> b;
    a--;b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  vector<int> order(N);
  vector<bool> ans(N);
  for(int i = 0;i<N;i++){
    int a;cin >> a;
    a--;
    order[N-1-i] = a;
  }

  int cc = 0;
  for(int i = 0;i<N;i++){

    int barn = order[i];
    cc++;
    stillopen[barn] = true;

    for(int j : adj[barn]){
      if(stillopen[barn] && stillopen[j] && (dsu.find(barn) != dsu.find(j))){
        dsu.unite(barn,j);
        cc--;
      }
    }

    ans[N-1-i] = cc == 1;
   

  }
  
  for(int i = 0;i<N;i++){
    if(ans[i]) cout << "YES\n";
    else cout << "NO\n";
  }

  return 0;
}
