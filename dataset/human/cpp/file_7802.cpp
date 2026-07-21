#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  int64_t y=0;
  for(int i=0;i<n;i++){
    cin>>a.at(i);
    y+=(i==0?0:a.at(i));
  }
  int64_t x=a.at(0);
  int64_t m=abs(x-y);
  for(int i=1;i+1<n;i++){
    x+=a.at(i);
    y-=a.at(i);
    m=min(m,abs(x-y));
  }
  cout<<m<<endl;
}
