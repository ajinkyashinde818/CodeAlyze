#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,M;
  cin>>N>>M;
  string n[N],m[M];
  for(int i=0;i<N;i++)
    cin>>n[i];
  for(int i=0;i<M;i++)
    cin>>m[i];
  if(M==N){
    bool p=true;
    for(int i=0;i<M;i++)
      for(int j=0;j<M;j++)
        if(n[i][j]!=m[i][j])
          p=false;
    if(p==true)
      cout<<"Yes"<<endl;
    else
      cout<<"No"<<endl;
    return 0;
  }
  for(int i=0;i<N-M;i++)
    for(int j=0;j<N-M;j++){
      bool present=true;
      for(int p=i;p<i+M;p++)
        for(int q=j;q<j+M;q++)
          if(n[p][q]!=m[p-i][q-j])
            present=false;
      if(present==true){
        cout<<"Yes";
        return 0;
      }
    }
  cout<<"No"<<endl;
  return 0;
}
