#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main (int argc, char* argv[])
{
  int R, G, B, N; cin >> R >> G >> B >> N;

  vector<int> RG;
  for (int i = 0; i <= N/R; i++) {
    for (int j = 0; j <= N/G ; j++) {
      RG.push_back(i*R+j*G);
    }
  }

  set<int> removeB;
  for (int i = 0;; i++) {
    if (N-B*i < 0) {
      break;
    }
    removeB.insert(N-B*i);
  }

  int ans = 0;
  for (int i = 0; i < RG.size(); i++) {
    if (removeB.find(RG[i]) != removeB.end()) {
      ans++;
    }
  }
  
  cout << ans << endl;
  return 0;
}
