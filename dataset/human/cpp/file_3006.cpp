#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

ll as[100001];

int main(void) {
  ll N;
  cin >> N;
  ll mc = 0;
  for(ll i = 0; i < N; i++)
  {
    ll t; cin >> t;
    mc += t < 0 ? 1 : 0;
    t = t < 0 ? -t : t;
    as[i] = t;
  }

  ll mina = as[0];
  ll mini = 0;
  for(ll i = 0; i < N; i++)
  {
    if (mina > as[i]) {
      mini = i;
      mina = as[i];
    }
  }
  
  ll sum = 0;
  
  for(ll i = 0; i < N; i++)
  {
    sum += as[i];
  }

  if (mc % 2 == 1)
    sum -= mina * 2;

  cout << sum << endl;

  return 0;
}
