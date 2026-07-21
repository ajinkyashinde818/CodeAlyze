#include <stdlib.h>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main(){
  int N,K;
  int ret;

  cin >> N >> K;
  if(10<=N) ret=K;
  else ret=K+100*(10-N);

  cout << ret << endl;
  
  return 0;
}
