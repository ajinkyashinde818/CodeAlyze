#include<bits/stdc++.h>
using namespace std;

int main(){
  int64_t N;
  cin >> N;
  vector<int64_t> A(N);
  int64_t M=0;
  for(int64_t i=0; i<N; i++){
    cin >> A.at(i);
    if(A.at(i)<0){
      M++;
    }
    A.at(i)=abs(A.at(i));
  }
  sort(A.begin(), A.end());
  int64_t Ans=0;
  if(M%2==1){
    Ans-=A.at(0);
    for(int64_t i=1; i<N; i++){
      Ans+=A.at(i);
    }
  }
  else{
    for(int64_t i=0; i<N; i++){
      Ans+=A.at(i);
    }
  }
  cout << Ans << endl;
}
