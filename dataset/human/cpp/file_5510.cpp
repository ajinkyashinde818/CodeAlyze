#include <algorithm>
#include <climits>
#include <iostream>
#include <random>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>

using std::cin;
using std::cerr;
using std::cout;
using std::endl;
using std::make_pair;
using std::pair;
using std::stack;
using std::string;
using std::unordered_set;
using std::vector;
using std::lower_bound;
using std::upper_bound;

int main(int argc, char* argv[]) {
  int n, r;
  cin >> n >> r;
  if (n <= 10) {
    cout << r + 100 * (10 - n);
  } else {
    cout << r;
  }
  return 0;
}
