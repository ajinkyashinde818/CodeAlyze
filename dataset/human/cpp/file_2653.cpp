#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
  int N,mcount;
  long v1, min1;
  cin >> N;
  cin >> min1;
  if (min1<0){
    min1 = min1*(-1);
    mcount++;
  }
  long ans = min1;
  
  for ( int i = 1; i< N; i++ ){
  cin >> v1;
  if(v1 < 0){
    v1 = v1*(-1);
    mcount++;
  }
  ans = ans + v1;
  min1 = min(min1,v1); 
  }
  
  if (mcount%2 != 0){
    min1 = 2 * min1;
    ans = ans - min1;
  }
  cout << ans << endl;
  return 0;
}
