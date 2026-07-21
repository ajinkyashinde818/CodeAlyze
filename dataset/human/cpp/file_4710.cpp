#include <iostream>
  #include <vector>
  #include <algorithm>
  #include <ctime>
  #include <cmath>
  #include <string>
  #include <stdlib.h>
  #include <fstream>
  #include <set>
  #include <map>
  #include <stack>
  #include <deque>
  #include <iterator>
  using namespace std;

  
  int main(){
      long long n, p;
      cin >> n >> p;
      cout << (n >= 10? p:p + 100 * (10 - n));
  }
