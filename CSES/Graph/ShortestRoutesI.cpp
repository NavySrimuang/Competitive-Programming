#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

/*

  Author:Navy
  SOL: dijkstra this is my first dijkstra code. might be a bit scuff

*/
 
const int mxN = 1e5,mxM = 2e5;
int N,M;
 
vector<vector<pair<int,int>>> adj(mxN + 1);
vector<long long> dist(mxN + 1,LLONG_MAX);
 
void dijkstra(int start){
 
	priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
	pq.push({0,start});
	dist[start] = 0;
 
	while(!pq.empty()){
 
		long long dis = pq.top().first;
		int node = pq.top().second;
		pq.pop();
 
		if(dis > dist[node]) continue;
 
		for(auto it : adj[node]){
 
			int child = it.first;
			long long w = it.second;
 
			if(dis + w < dist[child]){
 
				dist[child] = dis + w;
				pq.push({dist[child],child});
 
			}
 
		}
 
	}
 
 
}
 
int main(){
 
	cin >> N >> M;
 
	while(M--){
 
		int a,b,c;
		cin >> a >> b >> c;
		adj[a].push_back({b,c});
		
	}
 
	dijkstra(1);
 
	for(int i = 1;i<=N;i++) cout << dist[i] << " ";
 
	return 0;
}

