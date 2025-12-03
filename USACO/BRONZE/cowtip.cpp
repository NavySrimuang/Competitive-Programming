#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){

  cin.tie(0)->sync_with_stdio(0);
  freopen("cowtip.in","r",stdin);
  freopen("cowtip.out","w",stdout);

  int n;cin >> n;

  vector<vector<char>>grid(n,vector<char>(n));

  for(int i = 0;i<n;i++){
    for(int j = 0;j<n;j++){
      cin >> grid[i][j];
    }
  }

  int cnt = 0;

  for(int i = n-1;i>=0;i--){
    for(int j = n-1;j>=0;j--){
      
      if(grid[i][j] == '1'){

        //flip
        cnt++;
        for(int k = 0;k<=i;k++){
          for(int l = 0;l<=j;l++){

            if(grid[k][l] == '0'){
              grid[k][l] = '1';
            }else{
              grid[k][l] = '0';
            }


          }
        }


      }

    }
  }

  cout << cnt << endl;

  //print
  // for(int i = 0;i<n;i++){
  //   for(int j = 0;j<n;j++){
  //     cout << grid[i][j];
  //   }
  //   cout << endl;
  // }


  return 0;
}
