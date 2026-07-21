#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,t=0;
  long B=0;
  cin >> N;
  vector<long> A(N);
  for(int i=0; i<N; i++){
    cin >> A.at(i);
  }
  
  for(int i=0; i<N; i++){
    if(A.at(i)<0){
      A.at(i)=(-1)*A.at(i);
      t++;
    }
  }
  sort(A.begin(),A.end());
  for(int i=1; i<N; i++){
    B+=A.at(i);
  }
  if(t%2==1){
    cout << B-A.at(0) << endl;
  }
  else{
    cout << B+A.at(0) << endl;
  }
}
