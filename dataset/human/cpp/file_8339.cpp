#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
  int N,M;
  cin >> N >> M;
  vector<string> A(N);
  vector<string> B(M);
  for(int i=0; i < N; i++)
      cin >> A[i];
  for(int i=0; i < M; i++)
      cin >> B[i];
  int ok = 0;
  for(int k=0; k < N-M+1; k++){
    for(int l=0; l < N-M+1; l++){
      for(int i=k; i < k+M; i++){
        for(int j=l; j < l+M; j++){
          if(A[i][j] == B[i-k][j-l])
	    ok += 1;
	  else{
	    ok = 0;
	    break;
	  }
	}
	if(ok == 0) break;
      }
      if(ok == M*M) break;
    }
    if(ok == M*M) break;
  }
  if(ok == M*M)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  return 0;
}
