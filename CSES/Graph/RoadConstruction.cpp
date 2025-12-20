#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

/*

  Author: Navy
  SOl: DSU with modified unite // kinda greedy method

*/

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

  int unite(int a,int b){

    int ra = find(a);
    int rb = find(b);

    if(ra == rb) return -1;

    if(sz[ra] < sz[rb]) swap(ra,rb);
    sz[ra] += sz[rb];
    par[rb] = ra;

    return ra;
  }


};


int main(){

  int N,M;
  cin >> N >> M;
  
  DSU uf(N);

  int mxsize = 1,cmpnow = N;

  while(M--){

    int a,b;cin >> a >> b;
    a--;b--;
    
    int root = uf.unite(a,b);

    if(root != -1){
      cmpnow--;
      mxsize = max(mxsize,uf.sz[root]);
    }

    cout << cmpnow << " " << mxsize << endl;
  }

  return 0;
}
