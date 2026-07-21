#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int N;
  cin >> N;

  vector< int > sz[1000000];
  int used = 0;

  while(N > 0) {
    int need = used;

    for(int i = used - 1; i >= 0; i--) {
      sz[need].push_back(N);
      sz[i].push_back(N);
      --N;
    }
    ++used;
  }

  if(N == 0) {
    cout << "Yes\n";
    cout << used << endl;
    for(int i = 0; i < used; i++) {
      cout << sz[i].size() << " ";
      for(int j : sz[i]) cout << j << " ";
      cout << endl;
    }
  } else {
    cout << "No\n";
  }
}
