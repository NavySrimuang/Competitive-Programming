#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){

  long long n;cin >> n;
  vector<int>v(n);

  for(long long i = 0;i<n;i++){cin >> v[i];}

  sort(v.begin(),v.end());

  long long mid = v[(n-1)/2];

  long long sum = 0;

  for(long long i = 0;i<n;i++){
    
    sum += abs(mid - v[i]);

  }

  cout << sum << endl;


  return 0;
}
