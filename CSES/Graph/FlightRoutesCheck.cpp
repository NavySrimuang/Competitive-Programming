#include<bits/stdc++.h>
#define endl '\n'
using namespace std;


/*

    Author:Navy
    Sol: //from internal sol of USACO
         //if one vertex REACH and BE REACH by all other vertex then every vertex in this graph can reach all each other 

*/



int N,M;
const int CONS = 100001;
vector<vector<int>>adj(CONS),re_adj(CONS);
vector<bool>visited(CONS);

void dfsI(int node){

    if(visited[node]) return;
    visited[node] = true;

    for(int child : adj[node]){
        dfsI(child);
    }

}
void dfsII(int node){

    if(visited[node]) return;
    visited[node] = true;

    for(int child : re_adj[node]){
        dfsII(child);
    }

}



int main(){

    cin >> N >> M;
    for(int i = 0;i<M;i++){
        int a,b;cin >> a >> b;
        adj[a].push_back(b);
        re_adj[b].push_back(a);
    }

    dfsI(1);
    for(int i = 1;i<=N;i++){
        if(!visited[i]){
            cout << "NO" << endl;
            cout << 1 << " " << i << endl;
            return 0;
        }
    }
    fill(visited.begin(),visited.end(),false);

    dfsII(1);

    for(int i = 1;i<=N;i++){
        if(!visited[i]){
            cout << "NO" << endl;
            cout << i << " " << 1 << endl; //becareful here cuz 1->i != i->1
            return 0;
        }
    }

    cout << "YES" << endl;
    

    return 0;
}
