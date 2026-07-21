#include <bits/stdc++.h>
using namespace std;

int main(){
  long long n, total=0, tmp = 0, x = 0, y = 0, tmpx = 0, tmpy = 0;
  cin >> n;
  int a[n];
  for(int i=0;i<n;i++){
    cin >> a[i];
  }

  for (int i=0; i<n; i++) {
    total += a[i];
  }

  for (int i=0; i<n-1; i++) {
    tmp += a[i];
    tmpx = tmp;
    tmpy = total - tmpx;
    if(i == 0){
      x = tmpx;
      y = tmpy;
    }else if(abs(tmpx-tmpy)<abs(x-y)){
      x = tmpx;
      y = tmpy;
    }
  }
  cout << abs(x-y) << endl;

  return 0;
}
