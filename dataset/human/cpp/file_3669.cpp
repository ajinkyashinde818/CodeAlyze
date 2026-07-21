#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  long long cnt=0,n,ans=0;
  cin>>n;
  vector<int>a(n);
  vector<int>b(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  for(int i=0;i<n;i++){
    if(a[i]<0){
      a[i]=(-1)*a[i];
      ans+=a[i];
      cnt++;
    }
    else{
      ans+=a[i];
     }
  } 
  for(int i=0;i<n;i++){
    if(a[i]<0){
      b[i]=a[i]*(-1);
  }
    else{
      b[i]=a[i];
    }
  }
  sort(b.begin(),b.end());
  if(cnt%2==0){
    cout<<ans<<endl;
    return 0;
  }
  else{
    cout<<ans-b[0]*2<<endl;
    return 0;
  }
}
