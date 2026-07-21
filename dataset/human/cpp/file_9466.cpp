#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cassert>
#include <functional>
#include <string>
#include <sstream>
#include <cctype>
using namespace std;

int main(){
  int N, M; cin >> N >> M;
  vector<string> A(N), B(M);
  for(int i = 0; i < N; i++) cin >> A[i];
  for(int i = 0; i < M; i++) cin >> B[i];

  for(int i = 0; i < N - M + 1; i++){
    for(int j = 0; j < N - M + 1; j++){
      bool ok = true;
      for(int k = 0; k < M; k++){
        if(A[i + k].substr(j, M) != B[k]) ok = false;
      }
      if(ok){
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
}
