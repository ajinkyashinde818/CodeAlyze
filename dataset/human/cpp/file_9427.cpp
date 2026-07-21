#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

int N,M;
string A[50],B[50];

bool check(int si, int sj){
  for(int i = si; i < si + M; i++){
    for(int j = sj; j < sj + M; j++){
      if(A[i][j] == B[i-si][j-sj]) continue;
      else return false ;
    }
  }
  return true;
}

int main(){
  cin >> N >> M;
  for(int i = 0; i < N; i++){
    cin >> A[i];
  }

  for(int i = 0; i < M; i++){
    cin >> B[i];
  }

  for(int i = 0; i < N - M + 1; i++){
    for(int j = 0; j < N - M + 1; j++){
      if(check(i,j)){
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
