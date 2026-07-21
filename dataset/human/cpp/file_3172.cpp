#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  int i,j = 0;
  for(i = 0; i< n;i++){
    cin >> a[i];
  }
  for(i = 0; i< n;i++){
    if(a[i] < 0)j++;
  }
  for(i = 0; i< n;i++){
    b[i] = abs(a[i]);
  }
  sort(b.begin(), b.end());
  long ans = 0;
  if(j %2 ==1){
    ans = b[0] * -1;
    for(i = 1; i< n;i++){
      ans += b[i];
    }
  }else{
    for(i = 0; i< n;i++){
      ans += b[i];
    }
  } 
  cout << ans << endl;
}
