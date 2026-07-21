#include <bits/stdc++.h>
using namespace std;




int main() {
  
  int N,M;
  cin>>N>>M;
  vector<string> vec_a(N);
  vector<string> vec_b(M);

  
  for (int i=0;i<N;i++){
    cin>>vec_a.at(i);
  }
  
  for (int i=0;i<M;i++){
    cin>>vec_b.at(i);
  }
  
  string answer="No";
  bool flag=false;
  
  
  for (int i=0;i<N-M+1;i++){
    

    for (int j=0;j<N-M+1;j++){

      bool match=true;
      
      for (int k=0;k<M;k++){

        for (int l=0;l<M;l++){
          if (vec_a.at(i+k).at(j+l)!=vec_b.at(k).at(l)){
            match=false;
          }
          if (match==false){
            break;
          }
        }
        if (match==false){
          break;
        }
      }
      
      if (match){
        answer="Yes";
        flag=true;
      }
      if (flag){
        break;
      }
    }
    if (flag){
      break;
    }
    
  }
  
  cout<<answer<<endl;
      

}
