#include<iostream>
using namespace std;

int main() {
  int N,M; cin >> N >> M;
  string A[50],B[50];
  for ( int i = 0; i < N; i++ ) cin >> A[i];
  for ( int i = 0; i < M; i++ ) cin >> B[i];

  bool isMatch = true;
  bool exist = false;
  for ( int li = 0; li < N; li++ ) {
    for ( int lj = 0; lj < N; lj++ ) {
      if ( li + M - 1 >= N || lj + M -1 >= N )continue;
      isMatch = true;
      for ( int i = 0; i < M; i++ ) {
	for ( int j = 0; j < M; j++ ) {
	  if ( A[i+li][j+lj] != B[i][j] ) isMatch  = false;
	}
      }
      if ( isMatch ) {
	cout << "Yes" << endl;
	return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
