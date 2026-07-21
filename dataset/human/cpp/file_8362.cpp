#include <bits/stdc++.h>
using namespace std;
#include<cstdio>
void ans(){
  int n,m;
  cin>>n>>m;
  
  vector<string> a(n),b(m);
  for(int i=0; i<n; i++)cin>>a.at(i);
  for(int i=0; i<m; i++)cin>>b.at(i);
  
 

  for(int j=0; j<=n-m; j++){//j<=n-m  =忘れ
    for(int k=0; k<=n-m; k++){
      for(int i=0; i<m; i++){
        string a_ =a.at(j+i).substr(k,m);
        if(b.at(i)!=a_)break; 
        if(b.at(i)==a_&&i==m-1) {
          cout<<"Yes";return;}
      }
     // cout<<"Yes";return;
    }
  }
  cout<<"No";return;
}
int main() {
  ans();
}
