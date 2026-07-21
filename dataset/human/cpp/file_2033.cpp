#include <cstdio>
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

long long int gcd(long long int x, long long int y) {
	if (x < y){
      return gcd(y, x);
    }
	long long int r;
	while (r = x % y) {
		x = y;
		y = r;
	}
	return y;
}

int main(void){
  long long int n,i,j;
  cin >> n;
  long long int a[n];
  long long int minusCount=0;
  long long int minAbs=1000000000;
  long long int total = 0;
  long long int tmp = 0;
  for(i=0;i<n;i++){
    cin >> a[i];
    if(a[i]<0) minusCount++;
    tmp = abs(a[i]);
    if(tmp<minAbs) minAbs = tmp;
    total += tmp;
  }
  
  if(minusCount%2!=0){
    total -= minAbs*2;
  }
  cout << total << endl;
  return 0;
}
