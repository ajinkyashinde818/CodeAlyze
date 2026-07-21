#include<bits/stdc++.h>
using namespace std;
main(){
  int N,M;
  cin>>N>>M;
  vector<string>A(N);
  for(auto&x:A)cin>>x;
  vector<string>B(M);
  for(auto&x:B)cin>>x;
  for(int y_a=0;y_a<N;++y_a){
    for(int x_a=0;x_a<N;++x_a){
      bool offset_failed=false;
      for(int y_b=0;y_b<M;++y_b){
        if(y_a+y_b>=A.size())offset_failed=true;
        if(offset_failed)break;
        for(int x_b=0;x_b<M;++x_b){
          if(x_a+x_b>=A[y_a+y_b].size())offset_failed=true;
          if(offset_failed)break;
          if(B[y_b][x_b]!=A[y_a+y_b][x_a+x_b])offset_failed=true;
        }
      }
      if(!offset_failed){
        cout<<"Yes"<<endl;
        return 0;
      }
    }
  }
  cout<<"No"<<endl;
}
