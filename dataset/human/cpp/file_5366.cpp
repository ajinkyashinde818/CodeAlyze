#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <climits>
#include <utility>
typedef long long ll;
using namespace std;

int main(void){
  int n, r;
  cin >> n >> r;

  if(n<10){
    cout << r + 100 * (10-n);
  }
  else{
    cout << r << endl;
  }
  
  return 0;
}
