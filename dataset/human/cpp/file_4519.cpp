#include <iostream>
#include <cstdio>
using namespace std;
int main(){
  int T,D,ta,tb,da,db,i,j;
  double min=2000000000,cal;
  cin >> T >> D >> ta >> tb >> da >> db;
  i=0;
  while(1){
    j=0;
    if(i+j>D) break;
    while(1){
      cal=(1.0*ta*i+tb*j)/(i+j);
      if(cal>T&&min>cal-T) min=cal-T;
      else if(cal<=T&&min>T-cal) min=T-cal;
      j+=db;
      if(i+j>D)	break;
    }
    i+=da;
  }
  printf("%.10f\n",min);
  return 0;
}
