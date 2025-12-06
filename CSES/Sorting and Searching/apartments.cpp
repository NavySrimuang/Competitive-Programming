#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

/*

  Author:Navy
  SOL: two pointer greedy kinda like the internol sol

*/



int main(){

  int n,m,k;cin >> n >> m >> k;

  vector<int>ppl(n),room(m);

  for(int i = 0;i<n;i++){cin >> ppl[i];}
  for(int i = 0;i<m;i++){cin >> room[i];}

  sort(ppl.begin(),ppl.end());
  sort(room.begin(),room.end());

  int i = 0,j = 0;
  int cnt = 0;
  while(i<m && j<n){

    if(abs(ppl[j] - room[i]) <= k){
      cnt++;
      i++;
      j++;
    }else{
      
      if(ppl[j] - room[i] > k){
        i++;
      }else{
        j++;
      }
      
    }

  }

  cout << cnt << endl;


  return 0;
}
