#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
struct edge { int u, v; ll w; };
 
ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int main() {
  int N, M;
  char A[50][50], B[50][50];
  cin >> N >> M;

  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      cin >> A[i][j];

  for (int i = 0; i < M; i++)
    for (int j = 0; j < M; j++)
      cin >> B[i][j];
  
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i + M - 1 >= N || j + M - 1 >= N) continue;
      
      int match = 1;
      for (int bi = 0; bi < M; bi++) {
        for (int bj = 0; bj < M; bj++) {
          if (A[i + bi][j + bj] != B[bi][bj]) match = 0;
        }
      }
      if (match) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
