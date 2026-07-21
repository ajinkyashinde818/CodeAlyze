#include <vector>
#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>


using namespace std;


int main(void){
  
  int N,R,rate;
  
  cin >> N >> R;
  
 if(N < 10){
   rate = R + 100 * (10 - N);
 }else{
   rate = R;
 }



  cout << rate << endl;

  return 0;
}
