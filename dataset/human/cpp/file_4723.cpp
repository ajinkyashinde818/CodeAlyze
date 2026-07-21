#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <deque>
#include <utility>


int main(){
  int N, R;
  scanf("%d", &N);
  scanf("%d", &R);
  if (N<10){
    R+=100*(10-N);
  }
  std::cout << R << std::endl;
  return 0;
}
