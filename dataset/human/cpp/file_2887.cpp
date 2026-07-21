#include <bits/stdc++.h>
using namespace std;
int main(){
  long long n,cnt=0,ans=0;
  cin >> n;
  long long a[n],b[n];
  for(int i=0;i<n;i++){
    cin >> a[i];
    if(a[i]<0){
      cnt++;
      a[i]*=-1;
    }
    b[i]=a[i];
    ans+=a[i];
  }
  if(cnt%2==1){
    sort(b,b+n);
    ans-=b[0]*2;
  }
  cout << ans << endl;
  return 0;
}
