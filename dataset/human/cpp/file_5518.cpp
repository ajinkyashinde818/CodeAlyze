/**
 * author: moririn_cocoa       
**/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
using namespace std;

int main(void) {
  
  int N;
  int R;
  
  cin >> N;
  cin >> R;
  
  if ( N < 10 ) {
    
    cout << 100 * ( 10 - N ) + R << endl;
  }
  
  else if ( N >= 10 ) {
    
    cout << R << endl;
  }
  
  return 0;
}
