#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdio>
#include<numeric>
using namespace std;
using ll = long long;
int main(){
  int r, g, b, n;
  cin >> r >> g >> b >> n;
  int cnt = 0;
  for(int i = 0; i * r <= n; i++){
    for(int j = 0; j * g <= n; j++){
      if(r * i + g * j > n){
        continue;
      }
      if((n - r * i - g * j ) % b == 0){
        cnt++;
      }
    }
  }
  cout << cnt << endl;
  return 0;
}
