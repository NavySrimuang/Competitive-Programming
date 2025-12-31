#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;

/*

	Author:Navy
	SOL: kinda bruteforce but with precomputed dist from 1 to N and N to 1 and try to use coupon every edges

*/

const int mxN = 1e5;
const ll INF = LLONG_MAX;
int N,M;
vector<vector<pair<int,int>>> ADJ(mxN + 1),RADJ(mxN + 1);

vector<ll> dijkstra(int start,vector<vector<pair<int,int>>> &adj){

	vector<ll> dist(N+1,INF);
	dist[start] = 0;

	priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
	pq.push({0,start});


	while(pq.size()){

		int dis = pq.top().first;
		int node = pq.top().second;
		pq.pop();

		if(dis > dist[node]) continue;

		for(auto it : adj[node]){

			int child = it.first;
			int w = it.second;

			if(dist[node] + w < dist[child]){

				dist[child] = dist[node] + w;
				pq.push({dist[child],child});

			}

		}


	}
	return dist;

}



int main(){

	cin >> N >> M;

	vector<array<int,3>> edges(M);

	for(int i = 0;i<M;i++){

		int a,b,c;
		cin >> a >> b >> c;
		ADJ[a].push_back({b,c});
		RADJ[b].push_back({a,c});
		edges[i][0] = a;
		edges[i][1] = b;
		edges[i][2] = c;
	}

	vector<ll> dist1 = dijkstra(1,ADJ);
	vector<ll> distN = dijkstra(N,RADJ);

	ll mn = INF;

	for(int i = 0;i<M;i++){

		int start = edges[i][0];int end = edges[i][1]; int w = edges[i][2];
		if(dist1[start] == INF || distN[end] == INF) continue;
		mn = min(mn,dist1[start] + w/2 + distN[end]);

	}

	cout << mn << endl;

  	return 0;
}
