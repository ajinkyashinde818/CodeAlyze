#include <bits/stdc++.h>
#include <math.h>
#include <cmath>
using namespace std;
using ll = long long;

int main(){
  int n;
  cin >> n;
  int r;
  cin >> r;

  if(n >= 10) cout << r << endl;
  else cout << r+ 100 * (10 - n) << endl;

}
