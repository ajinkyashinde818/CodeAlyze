#include <iostream>
using namespace std;
int main() {
  int N, M;
  cin >> N >> M;
  char A[50][50], B[50][50];
  auto cursor = [](int x){return [&](int &i, int &j){i++; if(i>=x){j+=1; i=0;}};};
  auto nextM = cursor(M), nextNM = cursor(N-M);  
  for(int i=0; i<N; ++i) scanf("%s", &A[i][0]);
  for(int i=0; i<M; ++i) scanf("%s", &B[i][0]);
  bool ok = false;
  for(int Ax=0, Ay=0; !ok && Ay<=N-M; nextNM(Ax, Ay))
  {
    ok = true;
    for(int i = 0, j = 0; j < M; nextM(i, j))
      if(A[Ax+i][Ay+j] != B[i][j])
      {
        ok = false;
        break;
      }
  }
  if(ok)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
