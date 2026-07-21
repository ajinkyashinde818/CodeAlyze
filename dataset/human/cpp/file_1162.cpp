#include <iostream>
#include <utility>
#include <map>
#include <array>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> p;

array<ll, 3> balls;
map<p, ll> memo;

ll solve(ll n, ll ball_index) {
  if (n == 0) {
    return 1;
  }

  if (ball_index == balls.size() - 1) {
    if (balls[2] == 0) {
      return 0;
    }
    return n % balls[2] == 0 ? 1 : 0;
  }

  if (balls[ball_index] == 0) {
    return solve(n, ball_index + 1);
  }

  auto key = p(n, ball_index);

  auto it = memo.find(key);
  if (it != memo.end()) {
    return it->second;
  }

  ll answer = 0;
  for (ll i = 0; ; i++) {
    ll rest_n = n - i * balls[ball_index];
    if (rest_n < 0) {
      break;
    }
    answer += solve(rest_n, ball_index + 1);
  }
  memo.insert(make_pair(key, answer));
  return answer;
}

int main() {
  ll n;
  cin >> balls[0] >> balls[1] >> balls[2] >> n;
  cout << solve(n, 0) << endl;
  return 0;
}
