#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
  int N,M;
  cin>>N>>M;
  vector<string> A,B;
  for(int i=0;i<N;i++){
    string temp;
    cin>>temp;
    A.push_back(temp);
  }
  for(int i=0;i<M;i++){
    string temp;
    cin>>temp;
    B.push_back(temp);
  }
  bool check=false;
  for(int i=0;i<(N-M+1);i++){
    for(int j=0;j<(A[0].size()-B.size()+1);j++){
      bool icheck=true;
      for(int k=0;k<M;k++){
        for(int l=0;l<B[0].size();l++){
          if(A[i+k][j+l]!=B[k][l]){icheck=false; break;}
        }
      }
      if(icheck) check=true;
    }
  }
  if(check) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;

  return 0;
}
