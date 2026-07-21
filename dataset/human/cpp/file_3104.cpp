#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,  minus = 0, minV = 10000000;
  cin >> n;
  int a[n];
  long long sum = 0;
  for ( int i = 0; i < n; i++){
    cin >> a[i];
    if(a[i] < 0){
      minus++;
    }
    sum += abs(a[i]);
    minV = min(minV, abs(a[i]));
  }

  if(minus % 2 == 0){
    cout << sum << endl;
  } else {
    cout << sum - 2*minV << endl;
  }


  return 0;
}
