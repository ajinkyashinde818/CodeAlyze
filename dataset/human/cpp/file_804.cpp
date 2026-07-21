#include<bits/stdc++.h>
using namespace std;
int main(){
  int R,G,B,N;
  cin>>R>>G>>B>>N;
  int count=0;
  for(int i=0;i<=N/R;i++){
    for(int j=0;j<=N/G;j++){
      if((N-(i*R+j*G))>0&&(N-(i*R+j*G))%B==0||i*R+j*G==N){
        count=count+1;
      }
      else{
      }
    }
  }
  cout<<count<<endl;
}
