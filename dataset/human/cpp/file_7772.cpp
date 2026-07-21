#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  long long a[N];
  long long x,y=0;
  for(int i=0;i<N;i++){
    cin>>a[i];
    y+=a[i];
  }
  x=a[0];
  y-=a[0];
  long long ans=abs(x-y);
  
  for(int i=1;i<N-1;i++){
    x+=a[i];
    y-=a[i];
    ans=min(ans,abs(x-y));
  }
  cout<<ans<<endl;
}
