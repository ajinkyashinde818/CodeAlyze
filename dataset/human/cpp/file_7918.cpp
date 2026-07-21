#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
  int n;
  cin >> n;

  vector<int> v(n);
  long long arai = 0;
  for(int i = 0; i < n; i++){
    cin >> v[i];
    arai += v[i];
  }
  arai -= v[0];

  long long sunu = v[0];
  long long ans = abs(sunu - arai);
  for(int i = 1; i < n - 1; i++){
    sunu += v[i];
    arai -= v[i];
    if(ans < abs(sunu - arai)) ans = ans;
    else ans = abs(sunu - arai);
  }
  cout << ans << endl;

  return 0;
}
