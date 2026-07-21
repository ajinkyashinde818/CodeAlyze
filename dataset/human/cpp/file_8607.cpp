#include <iostream>
#include <string>
#include <vector>
// TLEの場合はbit shiftに変える
using namespace std;
int N, M;
bool same_check(vector <string>A, vector <string>B, int strow, int stcol)
{
  if ((strow+M) > N) return false;
  if ((stcol+M) > N) return false;
  for (int Brow = 0;  Brow < M; Brow++) {
    for (int Bcol = 0; Bcol < M; Bcol++) {
      if ((B[Brow][Bcol])!=(A[Brow+strow][Bcol+stcol])) {
        return false;
      }
    }
  }
  return true;
}
int main()
{
  cin >> N >> M;
  vector <string> A(N), B(M);
  for (int i = 0; i < N; i++) cin >> A[i];
  for (int i = 0; i < M; i++) cin >> B[i];
  
  bool ans = false;
  for (int row = 0; row < N-M+1; row++) {
    for (int col = 0; col < N-M+1; col++) {
      if (same_check(A, B, row, col)) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
