#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,M;
  cin>>N>>M;
  
  bool flag=false;
  
  vector<vector<char>>A(N,vector<char>(N));
  
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cin>>A.at(i).at(j);
    }
        }
        
        vector<vector<char>>B(M,vector<char>(M));
        
        for(int i=0;i<M;i++){
          for(int j=0;j<M;j++){
cin>>B.at(i).at(j);
          }
        }
        
        for(int i=0;i<=N-M;i++){
          for(int j=0;j<=N-M;j++){
            int sum=0;
            for(int k=0;k<M;k++){
              for(int l=0;l<M;l++){
if(A.at(0+i+k).at(0+l+j)==B.at(k).at(l)){
  sum++;
}
                
              }
                  }
                  
                  if(sum==M*M){
cout<<"Yes"<<endl;
                    flag=true;
                    break;
                  }
                  }
                  
                  if(flag){
                    break;
                  }
                  }
                  if(flag==false){
cout<<"No"<<endl;
                  
                  }
}
