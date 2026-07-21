#include <bits/stdc++.h>
using namespace std;

int a[500][500];

int main(){
  int n;

  cin >> n;

  int tmp = 0;
  int cnt = 0;
  for(int i = 1;tmp < n;i++){
    tmp += i;
    cnt++;
  }

  if(tmp > n){
    cout << "No" << endl;
    return 0;
  }

  cout << "Yes" << endl;

  cout << cnt + 1 << endl;


  tmp = 1;
  for(int i = 0;i < cnt;i++){
    for(int j = 0;j < cnt;j++){
      if(i <= j){
        a[i][j] = tmp;
        a[j+1][i] = tmp;
        tmp++;
      }
    }
  }

  for(int i = 0;i <= cnt;i++){
    cout << cnt << " ";

    for(int j = 0;j < cnt;j++){
      cout << a[i][j];
      if(j < cnt-1) cout << " ";
    }
    cout << endl;
  }

  return 0;
}
