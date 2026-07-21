#include<bits/stdc++.h>
using namespace std;

int main(){
 long long N,u,c,ans;
  cin>>N;
  ans=100000000000;
  
  vector<long long>a(N),b(N);
  cin>>a[0];
  b[0]=a[0];
  u=a[0];
    for(int i=1;i<N;i++){
      cin>>a[i];
      b[i]=b[i-1]+a[i];
      u+=a[i];
    }
     for(int i=0;i<N-1;i++){
      c=abs(u-2*b[i]);
       ans=min(ans,c);
    }
      cout<<ans<<endl;
}
