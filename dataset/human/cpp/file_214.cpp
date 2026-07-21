#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
  int R,G,B,N;
  cin>>R>>G>>B>>N;
  ll ans = 0;
  for (int i = 0; i <= N/R; i++) {
    for (int j = 0; j <= N/G; j++) {
      if ((N - i * R - j * G) >= 0 && (N - i * R - j * G) % B == 0) {
        ans++;
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}
