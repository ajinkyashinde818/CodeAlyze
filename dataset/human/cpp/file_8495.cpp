#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
int N, M;
char a[51][51];
char b[51][51];
bool check(int y, int x) {
  if (y + M > N || x + M > N) {
    return false;
  }
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < M; j++) {
      if (a[y + i][x + j] != b[i][j]) {
        return false;
      }
    }
  }
  return true;
}

int main(int argc, const char * argv[]) {
  cin >> N >> M;
  
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> a[i][j];
    }
  }
  
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < M; j++) {
      cin >> b[i][j];
    }
  }
  
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if(check(i, j)) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
