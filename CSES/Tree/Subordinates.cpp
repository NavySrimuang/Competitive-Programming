#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int N;
const int CONS = 2000005;
vector<vector<int>>adj(CONS);
int cnt[CONS];
bool visited[CONS];

void dfs(int node){

    if(visited[node]) return;
    visited[node] = true;
    cnt[node]++;

    for(int child:adj[node]){
        if(!visited[child]){
            
            dfs(child);
            cnt[node] += cnt[child];
        }
    }



}





int main(){

    cin >> N;

    for(int i = 2;i<=N;i++){
        int a;cin >> a;
        adj[i].push_back(a);
        adj[a].push_back(i);
    }

    dfs(1);

    for(int i = 1;i<=N;i++){
        cout << cnt[i]-1 << " ";
    }




    return 0;
}
