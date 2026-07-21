#include <iostream>

int main(){
  int n,i,near0=1000000000;
  bool isOdd=0,notExist0=1;
  long ans=0;
  std::cin>>n;
  int a[n];
  for (i=0;i<n;i++)std::cin>>a[i];
  for (i = 0; i < n; i++) {
    if (a[i]<0){
      a[i]=-a[i];
      isOdd=!isOdd;
  }
  ans+=a[i];
}
  if (isOdd){
    for(i=0;i<n;i++){
      if (near0>a[i])near0=a[i];
      if (near0==0)break;
    }
    ans-=near0*2;
  }
  std::cout<<ans<<'\n';
}
