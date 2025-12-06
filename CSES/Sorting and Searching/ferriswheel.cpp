#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

/*

  Author:Navy
  SOLN: 2p kinda like twosum in leetcode same logic I use some I track the count by -2 for each found then we will get the number of non chosen ppl

*/


int main(){

  int n,x;cin >> n >> x;
  //two sum leetcode ??

  vector<int>child(n);
  for(int i = 0;i<n;i++){cin >> child[i];}

  sort(child.begin(),child.end());

  int l = 0,r = n-1;
  int cnt = 0;
  int ppl = n;

  while(l<r){

    if(child[l] + child[r] <= x){
      ppl -= 2;
      cnt++;

      l++;
      r--;

    }else{

      r--;

    }


  }

  cout << cnt + ppl << endl;

  return 0;
}
