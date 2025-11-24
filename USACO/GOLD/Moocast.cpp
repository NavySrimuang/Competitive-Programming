#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

/*

    Author:Navy
    Sol: Binary search on X that makes all vertex connects

*/


int N;
vector<pair<int,int>>cow(1001); // 1 based
vector<vector<int>>adj(1001);
vector<bool>visited(1001);

int vis_cnt;

void setIO(string s){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  if(!s.empty()){
    freopen((s+".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
  }
}





void dfs(int node){

    if(visited[node]) return;
    visited[node] = true;
    vis_cnt++;
    for(int child:adj[node]){
        dfs(child);
    }

}



bool can(long long x){

    //check if this index can connect the whole graph

    adj.assign(N+1,{}); //flush
    vis_cnt = 0;
    visited.assign(N+1,false);


    for(int i = 1;i<=N;i++){
        for(int j = i+1;j<=N;j++){

            long long dx = (long long)cow[i].first - cow[j].first;
            long long dy = (long long)cow[i].second - cow[j].second;
            long long d = dx*dx + dy*dy;

            if(x >= d){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }

        }
    }


    dfs(1);

    return vis_cnt == N;


}





int main(){


    setIO("moocast");

    cin >> N;
    for(int i = 1;i<=N;i++){ cin >> cow[i].first >> cow[i].second;};

    if(N==1){ //base case
        cout << 0 << endl; return 0;
    }

    //precompute all distance

    vector<long long>dists; // 0 based for bns
    for(int i = 1;i<=N;i++){
        for(int j = i+1;j<=N;j++){
            long long dx =  (long long) cow[i].first - cow[j].first;
            long long dy = (long long) cow[i].second - cow[j].second;
            dists.push_back(dx*dx + dy*dy);
        }
    }

    sort(dists.begin(),dists.end());
    dists.erase(unique(dists.begin(),dists.end()),dists.end());

    int lo = 0,hi = dists.size() - 1;
    int ans = hi;

    //bns
    while(hi >= lo){

        int mid = lo + (hi-lo)/2;
        long long x = dists[mid];

        if(can(x)){
            ans = mid;
            hi = mid - 1;
        }else{
            lo = mid + 1;
        }



    }

    cout << dists[ans] << endl;


    return 0;
}
