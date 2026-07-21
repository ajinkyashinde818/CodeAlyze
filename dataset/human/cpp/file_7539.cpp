#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
  	cin >> n;
  long long int a[n],b[n+1],ans=LLONG_MAX;
  b[0]=0;
  	for(int i=0;i<n;i++){
      cin >>a[i];
      b[i+1]=b[i]+a[i];
      //cerr<<b[i+1]<<endl;
    }
  for(int i=0;i<n-1;i++){
    ans=min(ans,abs(b[n]-2*b[i+1]));
    cerr<<b[i+1]<<ans<<endl;
  }
  cout << ans<<endl;
}
