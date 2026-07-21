#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  vector<vector<char> > A(N, vector<char>(N));
  vector<vector<char> > B(M, vector<char>(M));
  string tmp;

  for (int i=0; i<N; i++){
    cin >> tmp;
    for (int j=0; j<N; j++){
      A[i][j] = tmp[j];
    }
  }
  for (int i=0; i<M; i++){
    cin >> tmp;
    for (int j=0; j<M; j++){
      B[i][j] = tmp[j];
    }
  }

  int count = 0;
  string flag = "No";
  for (int i=0; i<N-M+1; i++){
    for (int j=0; j<N-M+1; j++){
      count = 0;
      for (int k=0; k<M; k++){
        for (int l=0; l<M; l++){
          if (A[i+k][j+l] == B[k][l]){
            count++;
          }
        }
      }
      if (count == M*M){
        flag = "Yes";
      }
    }
  }
  cout << flag << endl;

  return 0;
}
