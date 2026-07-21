#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <limits>

using namespace std;

int main(){
  int N,R;
  scanf("%d %d", &N, &R);

  if(N>=10){
    printf("%d\n",R);
  }else{
    printf("%d\n",R+100*(10-N));
  }
  return 0;
}
