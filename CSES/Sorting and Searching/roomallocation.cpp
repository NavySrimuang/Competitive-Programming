#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

/*

  Author:Navy
  SOL: use pq of <free_day,room> then if available just replace the new pq with the last room

*/


int main(){

  int n;cin >> n;
  vector<pair<pair<int,int>,int>>v(n); //.first.first = checkin .first.second = checkout .second = ori_idx;
  for(int i = 0;i<n;i++){
    cin >> v[i].first.first >> v[i].first.second;
    v[i].second = i;
  }

  sort(v.begin(),v.end());

  int last = 0;
  vector<int>ans(n);
  priority_queue<pair<int,int> ,vector<pair<int,int>>, greater<pair<int,int>>>pq;
  //pq store pair<free day,room id>
  for(int i = 0;i<n;i++){

    int a = v[i].first.first;
    int b = v[i].first.second;
    int idx = v[i].second;


    if(pq.empty() || !(a > pq.top().first)){
      //reserve new room
      last++;
      pq.push({b,last});
      ans[idx] = last;
    }else{

      //reuse
      int froom = pq.top().second;
      pq.pop();
      ans[idx] = froom;
      pq.push({b,froom});

    }

  }

  cout << last << endl;
  for(int i:ans) cout << i << " ";


  return 0;
}
