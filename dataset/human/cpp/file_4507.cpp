#include <iostream>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
 
int main() {
  int T,D,tA,tB,dA,dB;
  scanf("%d %d %d %d %d %d",&T,&D,&tA,&tB,&dA,&dB);
  double dTemp = 999999999999.9;
  for(int i = 0; i < 10000; i++) {
    for(int j = 0; j < 10000; j++) {
      if(i == 0 && j == 0) continue;
      if(dA * i + dB * j > D) break;
      int vA = dA * i;
      int vB = dB * j;
      dTemp = min(fabs(T - ((double)tA * vA + (double)tB * vB) / (double)(vA + vB)),dTemp);
    }
  }
  printf("%.20f\n",dTemp);
}
