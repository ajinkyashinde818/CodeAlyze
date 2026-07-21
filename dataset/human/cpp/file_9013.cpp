#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,M;
  cin>>N>>M;
  vector<string>A(N);
  vector<string>B(M);
  for(int i=0;i<N;i++){
    cin>>A.at(i);
  }
  for(int i=0;i<M;i++){
    cin>>B.at(i);
  }
  bool flag2=true;
  for(int i=0;i<N-M+1;i++){
    if(flag2==false){
      break;
    }
    for(int j=0;j<N-M+1;j++){
      bool flag=true;
      for(int k=0;k<M;k++){
        for(int l=0;l<M;l++){
          if(B.at(k).at(l)!=A.at(i+k).at(j+l)){
            flag=false;
          }
        }
      }
      if(flag){
        cout<<"Yes"<<endl;
        flag2=false;
        break;
      }
    }
  }
  if(flag2==true){
    cout<<"No"<<endl;
  }
}
