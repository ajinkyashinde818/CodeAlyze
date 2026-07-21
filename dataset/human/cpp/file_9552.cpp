#include <iostream>
#include <string>
using namespace std;
int main(){

  int n,m,blank;
  string a[50],b[50];

  cin>>n>>m;

  for(int i=0;i<n;i++) cin>>a[i];
  for(int i=0;i<m;i++) cin>>b[i];

  for(int i=0;i<=n-m;i++) for(int j=0;j<=n-m;j++){
      if(a[i][j]==b[0][0]){
        blank=0;
        for(int k=0;k<m;k++) for(int u=0;u<m;u++) if(a[i+k][j+u]!=b[k][u]) blank++;
        if(blank==0){
          cout<<"Yes"<<endl;
          return 0;
        }
      }
    }
  cout<<"No"<<endl;

  return 0;

}
