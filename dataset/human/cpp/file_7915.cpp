#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <algorithm>

#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char *argv[]){

  int N;
  cin >> N;
  int a[N];
   long long  x  = 0, y = 0;
  for(int i = 0; i < N; i++){
    cin >> a[i];
    y += a[i];
  }
  x = a[0];
  y -= a[0];
   long long  mini = abs(x - y);
  for(int i = 1; i < N-1; i++){
    x += a[i];
    y -= a[i];
    //printf("x : %llu\n", x);
    //printf("y : %llu\n", y);
     long long tmp = abs(x-y);
    //printf("tmp : %llu\n", tmp);
    mini = (tmp < mini)? tmp:mini;
  }
  //printf("x : %d\n", x);
  printf("%llu\n", mini);

  return 0;
}
