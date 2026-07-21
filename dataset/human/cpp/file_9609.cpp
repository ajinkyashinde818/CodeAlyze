#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,M;
  cin>>N>>M;
  vector<string> vecA(N);
  vector<string> vecB(M);
  for(int i=0;i<N;i++)
    cin>>vecA.at(i);
  for(int i=0;i<M;i++)
    cin>>vecB.at(i);
  int count=0;
  bool finished=false;
  for(int i=0;i<N-M+1;i++){
  	for(int j=0;j<N-M+1;j++){
      if(vecA.at(i).at(j)==vecB.at(0).at(0)){
      	for(int k=0;k<M;k++){
          for(int l=0;l<M;l++){
            if(vecA.at(i+k).at(j+l)==vecB.at(k).at(l)){
              count++;
              if(count==M*M){
                finished=true;
                break;
              }
            }
            else{
              count=0;
              break;
            }
          }
          if(count==0||finished==true)
            break;
        }
      }
    }
    if(finished==true)
      break;
  }
  if(finished==true)
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;
}
