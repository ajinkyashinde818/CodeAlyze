#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int N, M;
  cin >> N; cin >> M;
  vector<string> a(N), b(M);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < M; i++) {
    cin >> b[i];
  }
  bool matched = false;
  for (int i = 0; i < N-M+1; i++) {
    for (int j = 0; j <N-M+1; j++) {
      for (int k = 0; k < M; k++) {
        for (int l = 0; l < M; l++) {
          //cout << i << ' ' << j << ' ' << b[k][l] << ' ' << a[k+i][l+j];
          if (b[k][l] != a[k+i][l+j]) goto out;
        }
      }
      matched = true;
      goto end;
out:
      matched = false;
    }
  }
  cout << "No" << endl;
  return 0;
end:
  cout << "Yes" << endl;
  return 0;
}
