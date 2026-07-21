#include<bits/stdc++.h>
using namespace std;
int main(){
int N,M;
  cin>>N>>M;
  vector<vector<char>>A(N,vector<char>(N));
  for(int i=0;i<N;i++){
  string a;
    cin>>a;
    for(int j=0;j<N;j++)
      A.at(i).at(j)=a.at(j);
 }vector<vector<char>>B(M,vector<char>(M));
  for(int i=0;i<M;i++){
  string b;
    cin>>b;
    for(int j=0;j<M;j++)
      B.at(i).at(j)=b.at(j);
  }string ans="No";
  for(int i=0;i<=N-M;i++){
  for(int j=0;j<=N-M;j++){
     bool x=true;
    for(int I=0;I<M;I++){
   for(int J=0;J<M;J++)
     if(B.at(I).at(J)!=A.at(i+I).at(j+J)){
       x=false;
     }
   }if(x){ans="Yes"; break;}
  
  }if(ans=="Yes") break;
  }
  cout<<ans<<endl;
  return 0;
}
