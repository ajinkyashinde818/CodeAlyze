#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,n;
  cin>>a>>b>>c>>n;
  int  res=0;
  bool OK=false;
  
  for(int i=0;i<=n;i++){
    for(int j=0;j<=n;j++){
      int N=n;
      N-=a*i+b*j;
      
      if(N%c==0 && N>=0)
        res++;
    }
  }
  
  cout<<res;
}
