#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  vector<int> a(n),s(n);
  bool no=false;
  int g=0;
  int f=1000000001;
  for(int i=0;i<n;i++){
    cin>>a[i];
    
    if(a[i]==0) no=true;
    if(a[i]<0){
      g++;
      s[i]= -a[i];
    }
    else{
      s[i]=a[i];
    }
    f=min(f,s[i]);
  }
  long long ans=0;
  if(no || (g%2==0)){
    for(int i=0;i<n;i++){
     
      ans+=s[i];
    }
  }
  else{
    for(int i=0;i<n;i++){
     
      ans+=s[i];
    }
    ans-=2*f;
  }
  cout<<ans<<endl;
}
