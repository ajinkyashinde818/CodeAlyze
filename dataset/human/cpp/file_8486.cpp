#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
using namespace std;
string A[55], B[55];

int main() {
  int N, M;
  cin >> N >> M;
  int count = 0;
  for (int i = 0; i < N; i++) cin >> A[i];
  for (int i = 0; i < M; i++) cin >> B[i];

  for (int i = 0; i < N - M + 1; i++) {
    for (int j = 0; j < N - M + 1; j++) {
      count = 0;
      for (int k = 0; k < M; k++) {
        for (int l = 0; l < M; l++) {
          if (A[i + k].at(j + l) == B[k].at(l)) count++;
        }
      }
      if (count == M * M) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }

  cout << "No" << endl;
  return 0;
}
