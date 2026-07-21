#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

typedef long long int ll;

int main () {
  int N;
  vector<ll> avec;
  cin >> N;
  ll total = 0;
  for (int i = 0; i < N; i++) {
    ll temp;
    cin >> temp;
    total += temp;
    avec.push_back(temp);
  }
  //cout << total << endl;
  ll x, y, min;
  x = 0;
  y = total;
  for (int i = 0; i < N - 1; i++) {
    x += avec.at(i);
    y -= avec.at(i);
    //cout << x << " " << y << endl;
    ll temp = x - y;
    if (temp < 0) temp = -temp;
    if (i == 0 || temp < min) min = temp;
  }
  cout << min << endl;
  return 0;
}
