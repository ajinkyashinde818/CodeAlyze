#include <iostream>
#include <string>

using namespace std;

int N, M;
string A[50];
string B[50];

inline bool is_include(int posi, int posj) {
  int ti;
  for(int i=0; i<M; i++) {
    ti = i+posi;
    for(int j=0; j<M; j++) {
      if(A[ti][posj+j] != B[i][j]) {
        return false;
      }
    }
  }
  return true;
}


int main() {
  cin >> N >> M;
  cin.ignore();
  for(int i=0; i<N; i++) {
    getline(cin, A[i]);
  } 

  for(int i=0; i<M; i++) {
    getline(cin, B[i]);
  }

 
  const int size=N-M;

  for(int i=0; i<=size; i++) {
    for(int j=0; j<=size; j++) {
      if(is_include(i, j)) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
