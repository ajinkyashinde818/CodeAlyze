#include<iostream>
#include<string>
using namespace std;

string A[50], B[50];

int main() {
  int N, M;
  cin >> N >> M;
  for (int n = 0; n < N; n++) cin >> A[n];
  for (int m = 0; m < M; m++) cin >> B[m];
  
  for (int y = 0; y <= N - M; y++) {
    for (int x = 0; x <= N - M; x++) {
      
      int cnt = 0;
      for (int dx = 0; dx < M; dx++) {
        if (A[x + dx].substr(y, M) == B[dx]) cnt++;
      }
      if (cnt == M) {
        cout << "Yes" << endl;
        return 0;
      }
      
    }
  }
  cout << "No" << endl;
  return 0;
}
