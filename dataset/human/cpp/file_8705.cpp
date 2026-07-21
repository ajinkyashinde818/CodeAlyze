#include <cstdio>
#include <iostream>

using namespace std;
int main() {

  int64_t N, M;

  cin >> N >> M;
  char A[N][N], B[M][M];
  
  for(int64_t i=0;i<N;i++)
    for(int64_t j=0;j<N;j++)
      cin >> A[i][j];

  for(int64_t i=0;i<M;i++)
    for(int64_t j=0;j<M;j++)
      cin >> B[i][j];
  
  for(int64_t i=0;i<N-M+1;i++) {
    for(int64_t j=0;j<N-M+1;j++) {
      bool b = true;
      for(int64_t k=0;k<M;k++) {
	for(int64_t l=0;l<M;l++) {
	  if(A[i+k][j+l] != B[k][l]) {
	    b = false;
	    goto jump;
	  }	    
	}
      }
      if(b) {
	cout << "Yes" << endl;
	return 0;
      }
    jump:
      ;
    }
  }
  cout << "No" << endl;
  
  return 0;
}
