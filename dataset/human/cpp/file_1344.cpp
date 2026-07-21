#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ll R, G, B, N;
  cin >> R >> G >> B >> N;
  ll triples = 0;
  for(ll r = 0; r <= N / R; r++) {
    for(ll g = 0; g <= N / G; g++) {
      ll cur = N - r * R - g * G;
      if(cur >= 0) {
        triples += (cur % B == 0);
      }
    }
  }
  cout << triples << '\n';
}
