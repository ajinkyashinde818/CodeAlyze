#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>

#define rep(i,n) for((i)=0;(i)<(int)(n);(i)++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(void) {
  int n, r;
  cin >> n >> r;

  if(n<10){
    cout << r+(100*(10-n)) << endl;
  }
  else {
    cout << r << endl;
  }
  return 0;
}
