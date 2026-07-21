#include<bits/stdc++.h>
using namespace std;
int main(){
  double t,d,ta,tb,da,db;
  cin>>t>>d>>ta>>tb>>da>>db;
  double ans=1e9;
  for(int i=0;i<=1000;i++)
    for(int j=0;j<=1000;j++){
      double va=da*i;
      double vb=db*j;
      if(va+vb>d||i+j==0)continue;
      ans=min(ans,abs(t-(ta*va+tb*vb)/(va+vb)));
    }
  printf("%.10lf\n",ans);
  return 0;
}
