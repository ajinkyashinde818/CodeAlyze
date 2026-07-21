#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  vector<string> a(n);
  vector<string> b(m);
  for(int i=0;i<n;i++)
    cin>>a.at(i);
  for(int i=0;i<m;i++)
    cin>>b.at(i);
  bool c=0;
  for(int i=0;i+m-1<n;i++){
    for(int j=0;j+m-1<n;j++){
      bool f=1;
      for(int y=0;y<m;y++)
        for(int x=0;x<m;x++)
          f=(a.at(y+i).at(x+j)!=b.at(y).at(x)?0:f);
      c=(f?1:c);
    }
  }
  cout<<(c?"Yes":"No")<<endl;
}
