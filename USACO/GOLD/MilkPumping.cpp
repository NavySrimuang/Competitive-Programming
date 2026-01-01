#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

/*

	Author:Navy
	SOL: Try each flow and track the best relults since flow are just need to be min and use SP with the cost

*/

int N,M;
vector<vector<pair<int,pair<int,int>>>> adj;

int dijkstra(int minflow){

	vector<int> cost(N+1,INT_MAX);
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	pq.push({0,1});
	cost[1] = 0;

	while(pq.size()){

		int dis = pq.top().first;
		int node = pq.top().second;
		pq.pop();

		if(dis > cost[node]) continue;

		for(auto it : adj[node]){

			int child = it.first;
			int c = it.second.first;
			int fl = it.second.second;

			if(fl < minflow) continue;

			if(cost[node] + c < cost[child]){
				cost[child] = cost[node] + c;
				pq.push({cost[child],child});
			}


		}

	}
	return (cost[N] == INT_MAX ? -1 : cost[N]);
}

int main(){

	cin.tie(0)->sync_with_stdio(0);
	freopen("pump.in","r",stdin);
	freopen("pump.out","w",stdout);

	cin >> N >> M;
	adj.resize(N+1);
	vector<int> flows;
	for(int i = 0;i<M;i++){

		int a,b,c,f;
		cin >> a >> b >> c >> f;
		adj[a].push_back({b,{c,f}});
		adj[b].push_back({a,{c,f}});
		flows.push_back(f);

	}

	int ans = -1;

	for(int &flow: flows){

		int cost = dijkstra(flow);
		if(cost == -1) continue;

		double rat = (double)flow/(double)cost;

		ans = max(ans,(int)(rat * 1e6));

	}

	cout << ans << endl;
  	return 0;
}
