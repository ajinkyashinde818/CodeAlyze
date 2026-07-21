#include <iostream>
using namespace std;

int main(){
  int n,m;
  cin>>n>>m;
  bool emerged[n],checked[n];
  for(int i=0;i<n;i++){
    emerged[i]=false;
    checked[i]=false;
  }
  int e[m];
  for(int i=0;i<m;i++){
    cin>>e[i];
    emerged[e[i]-1]=true;
  }
  for(int i=m-1;i>=0;i--)
    if(!checked[e[i]-1]){
      cout<<e[i]<<endl;
      checked[e[i]-1]=true;
    }
  for(int i=0;i<n;i++)
    if(!emerged[i])
      cout<<i+1<<endl;
}
