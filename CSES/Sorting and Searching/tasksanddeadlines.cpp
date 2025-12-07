#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

/*

  Author:Navy
  SOLN: do the task by the smallest duration 

*/

int main(){

  int n;cin >> n;
  vector<pair<long long,long long>>task(n);

  for(int i = 0;i<n;i++){
    long long a,b;cin >> a >> b;
    task[i] = {a,b};
  }

  sort(task.begin(),task.end());

  long long sum = 0;
  long long timeline = 0; //track the current time
  for(int i = 0;i<n;i++){
    timeline += task[i].first;
    sum += (task[i].second - timeline); 
  }

  cout << sum << endl;


  return 0;
}
