#include <algorithm>
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<string>

#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>

using namespace std;
int main(){

  long n,ii;
  vector<long> a;
  long zeroNum = 0;
  long plsNum = 0;
  long minusNum = 0;
  long min = LONG_MAX;
  long minPos = -1;
  long sum =0;
  cin >> n;

  a.resize(n);
  for(ii=0;ii<n;ii++){
    cin >> a[ii];

    if(a[ii] == 0){
      zeroNum++;
    }
    else if(a[ii] > 0){
      plsNum++;
    }
    else if(a[ii] < 0){
      minusNum++;
    }

    if( abs(a[ii]) < abs(min)){
      min = a[ii];
      minPos = ii;
    }
  }

  //cout << "minPos" << minPos << endl << LONG_MIN << endl;
  if(zeroNum >= 1 ||
     (minusNum % 2) == 0){

    for(ii=0;ii<n;ii++){
      sum += abs(a[ii]);
    }
    
  }
  else{

    for(ii=0;ii<n;ii++){
      if(ii==minPos){
	if(a[ii] > 0){
	  sum -= a[ii];
	}
	else{
	  sum += a[ii];
	}
      }
      else{
	sum += abs(a[ii]);
      }
    }
  }

  cout << sum << endl;
    
  return 0;
}
