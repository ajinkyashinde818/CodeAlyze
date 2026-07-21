#include <bits/stdc++.h>
using namespace std;

int main(){
  bool zero = false;
  int mc = 0;
  int n;
  cin >> n;
  vector<long long> a(n);
  long long sum = 0;
  
  for(int i=0; i<n; i++){
    cin >> a[i];
    if(a[i]<0){
      mc ++;
      a[i] = abs(a[i]);
    }
    if(a[i]==0) zero = true;
    sum += a[i];
  }
  
  if(zero||mc%2==0){
    cout << sum << endl;
  }
  else{
    sort(a.begin(),a.end());
    cout << sum - 2 * a[0] << endl;
  }
}
