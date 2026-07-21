#include<bits/stdc++.h>
using namespace std;
int main(){
  
  int n;
  cin >> n;
  
  vector<int64_t> cont(n);
  
  int64_t count = 0;
  bool jad = false;
  for(int i = 0 ; i < n ; i++){
    int a;
    cin >> a;
    if(a < 0){
      count++;
      count %= 2;
      a *= -1;
    }
    if(a == 0){
      jad = true;
    }
    cont.at(i) = a;
  }
  
  sort(cont.begin() , cont.end());
  
  int64_t ans = 0;
  for(int i = 0 ; i < n ; i++){
    ans += cont.at(i);
  }
  
  if(count % 2 == 0 || jad){
    cout << ans << endl;
  }
  else{
    cout << ans - 2*cont.at(0) << endl;
  }
}
