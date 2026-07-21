#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int main(void){
  int R, G, B, N;
  cin >> R >> G >> B >> N;
  long long ans = 0;
  for(long long b = 0; b <= N/B; ++b){
    for(long long g = 0; g <= N/G; ++g){
      long long tmp = b * B + g * G;
      if((N - tmp) >= 0 && ((N - tmp)%R) == 0){
        ++ans;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
