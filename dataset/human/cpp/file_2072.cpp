#include <bits/stdc++.h>
using namespace std;
int main(){
  long n;
  cin>>n;
  long a[n];
  long ans = 0;
  long minus = 0;
  long syou = 10000000000;
  for(int i = 0;i<n;i++){
    cin >> a[i];
    ans += abs(a[i]);
    if(a[i] < 0){
      minus++;
    }
    syou = min(syou,abs(a[i]));
  }
  if(minus%2 ==0){
    cout<<ans<<endl;
  }
  else{
    cout<<ans-2*syou<<endl;
  }
  return 0;
}
