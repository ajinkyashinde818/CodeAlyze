/**********************************************
 * author : deepak nayan
 * file   : e:/Solutions/atcoder/abc156_a.cpp
 * time   : Sat May  2 19:27:06 2020
 * quest  : A - Beginner
 *********************************************/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, r;
  cin >> n >> r;
  cout << ((n >= 10) ? r : (r + 100 * (10 - n))) << "\n";
  return 0;
}
