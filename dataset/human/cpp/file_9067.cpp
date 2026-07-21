#include<bits/stdc++.h>                                                                          
using namespace std;
int main()
{
  int N,M;
  cin >> N >> M;
  vector<string> A(N);
  vector<string> B(M);
  for(int i=0; i<N; i++){
    cin >> A.at(i);
  }
  for(int i=0; i<M; i++){
    cin >> B.at(i);
  }
  int check=0;
  for(int i=0; i<N-M+1; i++){
    for(int j=0; j<N-M+1; j++){
      for(int k=0; k<M; k++){
        for(int l=0; l<M; l++){
          if(A.at(i+k).at(j+l)==B.at(k).at(l)){
            check++;
          }
        }
      }
      if(check==M*M){
        cout << "Yes" << endl;
        return 0;
      }
      else{
        check=0;
      }
    }
  }
  cout << "No" << endl;
}
