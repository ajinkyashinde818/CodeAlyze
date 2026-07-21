#include <bits/stdc++.h>

using namespace std;
using ll = long long;

template <class T> ostream &operator<<(ostream &os, vector<T> &v) {
  for (auto i = v.begin(); i != v.end(); i++) {
    os << *i << " ";
  }
  return os;
}

const string YES = "Yes";
const string NO = "No";

void solve(long long N, long long M, std::vector<std::string> A, std::vector<std::string> B){
  bool f = false;
  for(int i=0; i<=N-M; i++){
    for(int j=0; j<=N-M; j++) {
      bool ff = true;
      for(int k=0; k<M; k++) {
	for(int l=0; l<M; l++) {
	  if(B[k][l] != A[k+i][l+j]) 
	    ff = false;
	}
      }
      f = f or ff;
    }
  }
  if(f)
    std::cout << YES << std::endl;
  else
    std::cout << NO << std::endl;
}

int main(){
  long long N;
  scanf("%lld",&N);
  long long M;
  scanf("%lld",&M);
  std::vector<std::string> A(N);
  for(int i = 0 ; i < N ; i++){
    std::cin >> A[i];
  }
  std::vector<std::string> B(M);
  for(int i = 0 ; i < M ; i++){
    std::cin >> B[i];
  }
  solve(N, M, std::move(A), std::move(B));
  return 0;
}
