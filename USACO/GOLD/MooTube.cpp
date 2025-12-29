#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

/*

  Author:Navy
  SOL: from the internal sol: sort edges by weight and sort queries by weight then connect all for each query and print out the size of the sz(startvid) -1

*/


struct DSU{

  vector<int>par, sz;

  DSU(int n){
    par.resize(n);
    sz.resize(n);

    iota(par.begin(),par.end(),0);
    fill(sz.begin(),sz.end(),1);
  }

  int find(int x){

    if(par[x] == x) return x;
    else return (par[x] = find(par[x]));

  }

  bool unite(int a,int b){

    int ra = find(a);
    int rb = find(b);

    if(ra == rb) return false;

    if(sz[ra] < sz[rb]) swap(ra,rb);

    sz[ra] += sz[rb];
    par[rb] = ra;

    return true;

  }

};

bool cmp(const pair<int,pair<int,int>> &a,const pair<int,pair<int,int>> &b){

  return a.second.first > b.second.first;

}

int main(){

  cin.tie(0)->sync_with_stdio(0);
  freopen("mootube.in","r",stdin);
  freopen("mootube.out","w",stdout);

  int n,q;
  cin >> n >> q;

  vector<pair<int,pair<int,int>>> edges(n-1); // w,{a,b}

  for(int i = 0;i<n-1;i++){
    int a,b,w;
    cin >> a >> b >> w;
    a--;
    b--;
    edges[i] = {w,{a,b}};
  }

  vector<pair<int,pair<int,int>>> queries(q); // idx, {k,v}

  for(int i = 0;i<q;i++){

    int k,v;
    cin >> k >> v;
    v--;

    queries[i] = {i,{k,v}};

  }

  sort(edges.begin(),edges.end(),greater<pair<int,pair<int,int>>>());
  sort(queries.begin(),queries.end(),cmp);

  DSU dsu(n);

  int idx = 0;
  vector<int> ans(q);
  for(auto query : queries){

    int v = query.second.second;
    int K = query.second.first;

    while(idx < (int)edges.size() && edges[idx].first >= K){
      dsu.unite(edges[idx].second.first,edges[idx].second.second);
      idx++;
    }

    ans[query.first] = dsu.sz[dsu.find(v)] - 1;

  }

  for(int i:ans){
    cout << i << endl;
  }

  return 0;
}
