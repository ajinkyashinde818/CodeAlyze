#include <iostream>
#include <vector>
using namespace std;
int main(){
  int n, m;
  cin >> n >> m;
  bool used[n];
  for(int i = 0; i < n; ++i) used[i] = false;
  vector<int> V;
  int e[m];
  for(int i = 0; i < m; ++i)
    cin >> e[i];

  for(int i = m-1; i >= 0; --i){
    if(!used[e[i]-1]){
      V.push_back(e[i]-1);
      used[e[i]-1] = true;
    }
  }

  for(int i = 0; i < n; ++i)
    if(!used[i]) V.push_back(i);

  for(int i = 0; i < n; ++i) cout << V[i]+1 << endl;
  return 0;
}
