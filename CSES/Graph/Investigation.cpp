#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = LLONG_MAX;
const int mxN = 1e5;

int N,M;
vector<vector<pair<int,ll>>> adj;

 ll dist[mxN + 1];
int num[mxN + 1];
int mxf[mxN+1];
int mnf[mxN+1];

void dijkstra(int start){

	priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
	dist[start] = 0;
	pq.push({0,start});
	num[start] = 1;
	mnf[start] = 0;
	mxf[start] = 0;
	
	while(pq.size()){

		ll dis = pq.top().first;
		int node = pq.top().second;
		pq.pop();


		for(auto it : adj[node]){
			
			int child = it.first;
			ll w = it.second;

			if(dist[node] + w == dist[child]){

				num[child] = (num[child] + num[node]) % (int)(1e9 + 7);
				mnf[child] = min(mnf[child],mnf[node] + 1);
				mxf[child] = max(mxf[child],mxf[node] + 1);

			}
			else if(dist[node] + w < dist[child]){
				dist[child] = dist[node] + w;
				num[child] = num[node];
				mnf[child] = mnf[node] + 1;
				mxf[child] = mxf[node] + 1;
				pq.push({dist[child],child});
			}

		}	

	}
}	

int main(){

	cin >> N >> M;
	adj.resize(N + 1);
	for(int i = 0;i<M;i++){
		int a,b; ll c;
		cin >> a >> b >> c;
		adj[a].push_back({b,c});
	}	
	for(int i = 1;i<=N;i++){
		dist[i] = INF;
		mnf[i] = 1e9;
		mxf[i] = 0;
	}
	dijkstra(1);
	
	cout << dist[N] << " " << num[N] << " " << mnf[N] << " " << mxf[N] << endl;
	return 0;
}
