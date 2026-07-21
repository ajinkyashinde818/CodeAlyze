#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
  int N, M;
  bool ans = false;
  string *A, *B;

  cin >> N >> M;
  A = new string[N];
  for (int n = 0; n < N; n++) {
    cin >> A[n];
  }

  B = new string[N];
  for (int m = 0; m < N; m++) {
    cin >> B[m];
  }

  int n = 0, m = 0, left = -1;
  while (n < N && m < M) {
    if (left > -1) {
      if (A[n].substr(left, M) == B[m]) {
        n++; m++;
      }
      else {
        left = -1;
        n = n; m = 0;
      }
      continue;
    }

    left = A[n].find(B[m]);

    // not found
    if (left == -1) {
      n++;
      continue;
    }
    else {
      n++; m++;
    }
  }

  if (left > -1 && m == M) {
    cout << "Yes";
  } else {
    cout << "No";
  }

  cout << endl;
  return 0;
}
