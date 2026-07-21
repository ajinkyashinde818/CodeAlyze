#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
  long N, M;
  cin >> N >> M;

  vector<string> a(N);
  for (int i = 0; i < N; ++i)
    cin >> a[i];

  vector<string> b(M);
  for (int i = 0; i < M; ++i)
    cin >> b[i];

  for (int i = 0; i < N - M + 1; ++i) {
    for (int j = 0; j < N - M + 1; ++j) {
      bool match = false;
      for (int k = 0; k < M; ++k) {
        if (a[i + k].substr(j, M) == b[k])
          match = true;
        else {
          match = false;
          break;
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
