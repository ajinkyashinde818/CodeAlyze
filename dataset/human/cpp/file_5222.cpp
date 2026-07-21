#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
#include <cmath>
#include <stack>

using namespace std;
using ll = long long int;

template <class T> ostream &operator<<(ostream &os, vector<T> &v) {
  for (auto i = v.begin(); i != v.end(); i++) {
    os << *i << " ";
  }
  return os;
}


void solve(long long N, long long R){
  if(N>=10)
    std::cout << R << std::endl;
  else
    std::cout << R+100*(10-N) << std::endl;
}

int main(){
  long long N;
  scanf("%lld",&N);
  long long R;
  scanf("%lld",&R);
  solve(N, R);
  return 0;
}
