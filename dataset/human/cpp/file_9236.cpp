#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int N, M;
char A[50][50];
char B[50][50];

bool f(int x, int y) {
  for (int i=0; i<M; i++) {
    for (int j=0; j<M; j++) {
      if (B[i][j] != A[i+x][j+y]) return false;
    }
  }
  return true;
}

int main() {
  cin >> N >> M;
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) cin >> A[i][j];
  }
  for (int i=0; i<M; i++) {
    for (int j=0; j<M; j++) cin >> B[i][j];
  }
  for (int x=0; x<=N-M; x++) {
    for (int y=0; y<=N-M; y++) {
      if (f(x, y)) {
        cout << "Yes\n";
        return 0;
      }
    }
  }
  cout << "No\n";
  return 0;
}
