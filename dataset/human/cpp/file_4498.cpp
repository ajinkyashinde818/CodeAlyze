#include<bits/stdc++.h>
using namespace std;

double T,ans=1e9;
int D,ta,tb,da,db;

int main(){
  cin>>T>>D>>ta>>tb>>da>>db;
  for(int i=0;i<=D;i+=da){
    for(int j=0;i+j<=D;j+=db){
      if(i==0&&j==0)continue;      
      double k=(double)(ta*i+tb*j) / (double)(i+j);
      ans=min(ans, abs(T-k));
    }
  }
  printf("%.10f\n",ans);
  return 0;
}
