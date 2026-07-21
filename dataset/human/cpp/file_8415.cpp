#include <bits/stdc++.h>
using namespace std;

typedef pair<long long, long long> data_t;

int main(){
  int n,m;
  cin>>n>>m;
  vector<string> a(n),b(m);
  for(int i=0;i<n;i++)
    cin>>a[i];
  for(int i=0;i<m;i++)
    cin>>b[i];
  int flag=0;
  string tmp;
  for(int i=0;i+m<=n;i++){
    for(int j=0;j+m<=n;j++){
      flag=0;
      for(int l=0;l<m;l++){
        tmp=a[i+l].substr(j,m);
        if(b[l]!=tmp){
          flag=1;
          break;
        }
      }
      if(flag==0){
      cout<<"Yes"<<endl;
      return 0;
    }
    }
  }
  cout<<"No"<<endl;
  return 0;
}
