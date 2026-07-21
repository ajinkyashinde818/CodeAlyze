#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
using namespace std;

int main(){
  // 入力
  int N, R;
  cin >> N >> R;
  
  int result;
  if (N>=10) {
    result = R; 
  } else {
    result = R + 100*(10-N);
  }

  cout << result << endl;
  return 0;
}
