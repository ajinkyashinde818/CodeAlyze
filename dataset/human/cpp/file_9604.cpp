#include <iostream>
using namespace std;

int BOARD_N[100][100];
int BOARD_M[100][100];

bool isPattern(int h, int w, int M) {
  for(int y = 0; y < M; ++y) {
    for(int x = 0; x < M; ++x) {
      if(BOARD_N[h + y][w + x] != BOARD_M[y][x]) {
        // cout << h << ", " << w << " : " << BOARD_N[h + y][w + x] << " => " << y << ", " << x
        //    << " : " << BOARD_M[y][x] << endl;

        return false;
      }
    }
  }
  return true;
}

int main() {
  int N, M;
  cin >> N >> M;
  {
    string s;
    for(int n = 0; n < N; ++n) {
      cin >> s;
      for(int i = 0; i < N; ++i) {
        BOARD_N[n][i] = (s[i] == '#') ? 1 : 0;
      }
    }
  }
  {
    string s;
    for(int m = 0; m < M; ++m) {
      cin >> s;
      for(int i = 0; i < M; ++i) {
        BOARD_M[m][i] = (s[i] == '#') ? 1 : 0;
      }
    }
  }
  for(int h = 0; h <= N - M; ++h) {
    for(int w = 0; w <= N - M; ++w) {
      if(isPattern(h, w, M)) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
