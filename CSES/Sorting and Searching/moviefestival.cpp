#include<bits/stdc++.h>
#define endl '\n'
using namespace std;


//Greedy approach select the from the least end time and check if it isn't intersected with the last

int main(){

  int n;cin >> n;
  vector<pair<int,int>>v(n);
  for(int i = 0;i<n;i++){
    int a,b;cin >> a >> b;
    v[i] = {a,b};
  }

  sort(v.begin(),v.end(),[](auto a,auto b){return a.second < b.second;});

  int cnt = 0;

  int last = -1;

  for(int i = 0;i<n;i++){

    if(!i){
      cnt++;
      last = v[i].second;
      continue;
    }

    if(v[i].first >= last){  //pass the intersection test
      cnt++;
      last = v[i].second;
    }

  }

  cout << cnt << endl;
  
  return 0;
}
