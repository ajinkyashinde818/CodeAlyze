#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  int64_t c;
  cin>>n>>c;
  vector<int64_t> x(n+2,0);
  vector<int> v(n+2,0);
  for(int i=1;i<=n;i++)
    cin>>x.at(i)>>v.at(i);
  x.at(n+1)=c;
  vector<int64_t> sc(n+2,0);
  vector<int64_t> mc(n+2,0);
  vector<int64_t> dc(n+2,0);
  for(int i=1;i<=n;i++){
    sc.at(i)=sc.at(i-1)+v.at(i);
    if(sc.at(i)-x.at(i)>mc.at(i-1)){
      mc.at(i)=sc.at(i)-x.at(i);
      dc.at(i)=x.at(i);
    }else{
      mc.at(i)=mc.at(i-1);
      dc.at(i)=dc.at(i-1);
    }
  }
  vector<int64_t> sa(n+2,0);
  vector<int64_t> ma(n+2,0);
  vector<int64_t> da(n+2,0);
  for(int i=n;i>0;i--){
    sa.at(i)=sa.at(i+1)+v.at(i);
    if(sa.at(i)-(c-x.at(i))>ma.at(i+1)){
      ma.at(i)=sa.at(i)-(c-x.at(i));
      da.at(i)=c-x.at(i);
    }else{
      ma.at(i)=ma.at(i+1);
      da.at(i)=da.at(i+1);
    }
  }
  int64_t m=0;
  for(int i=0;i<=n;i++)
    m=max(m,mc.at(i)+ma.at(i+1)-min(dc.at(i),da.at(i+1)));
  cout<<m<<endl;
}
