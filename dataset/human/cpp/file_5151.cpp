#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<cmath>
#include<math.h>
#include<algorithm>
#include<string.h>
#include <iomanip>
#include <sstream>
using namespace std;

int main() {
  int N, R;
  int ans = 0;

  cin >> N >> R;

  if( N >= 10){
    ans = R;
  }else{
    ans = R + 100*(10-N);
  }
  cout << ans << endl;

}
