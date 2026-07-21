#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>

using namespace std;

int main() {
  int n,r;
  cin >> n >> r;

  if(n >= 10) cout << r << endl;
  else cout << r + 100*(10-n) << endl;
}
