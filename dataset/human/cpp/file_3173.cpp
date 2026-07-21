#include <bits/stdc++.h>
using namespace std ;

int main(){
  long long int n, a[100010], ans=0, x=1000000010;
  cin >> n;
  for(int i=0;i<n;i++)cin >> a[i];
  for(int i=0;i<n-1;i++){
    if(a[i]<0){
      a[i]*=-1;
      a[i+1]*=-1;
    }
    ans+=a[i];
  }
  if(a[n-1]<0){
    ans+=abs(a[n-1]);
    for(int i=0;i<n;i++)x=min(x,abs(a[i]));
    ans-=2*x;
  }
  else ans+=a[n-1];
  cout << ans << endl;

  return 0;
}
