#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
 
using namespace std;
 
int main(int argc, char** argv) {
  int n, r;
  cin >> n >> r;
  if (n < 10) {
    cout << r + 100 * (10 - n) << endl;
  } else {
    cout << r;
  }
  return 0;
}
