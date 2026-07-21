#include <bits/stdc++.h>
#include <map> // pair
using namespace std;


int main(){
  int N,M;
  cin>>N>>M;
  vector<string> A(N);
  vector<string> B(M);
  for(int i = 0;i<N;i++){
    cin>>A.at(i);
  }
  for(int i = 0;i<M;i++){
    cin>>B.at(i);
  }
  string ans = "No";

  int stind2 = 0;
  for(int h = 0;h<(N-M+1);h++){
    int stind = 0;
  for(int i = 0;i<(N-M+1);i++){
    int c = 0;
    for(int j = 0; j < M; j++){
      string tmp ;
      for(int k = 0;k<M;k++){
        tmp.push_back(A.at(stind+j).at(stind2+k));
      }
      if(tmp==B.at(j))c++;
    }
    if(c==M){
      ans = "Yes";
      break;
    }
    stind++;
  }
    if(ans=="Yes")break;
    stind2++;
  }

  cout<<ans<<endl;
}
