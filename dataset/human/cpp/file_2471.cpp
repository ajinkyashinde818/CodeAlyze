#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main(){
  int N;
  int OddCount = 0;
  bool ZeroFlag = false;
  cin >> N;
  vector<int> A;
  for(int i=0;i<N;i++){
    int a;
    cin >> a;
    if(a < 0){
      OddCount++;
    }
    if(a == 0){
      ZeroFlag = true;
    }
    A.push_back(a);
  }
  bool breakflag = false;

  long int ans = 0;
  while(!breakflag){
    if(OddCount % 2 == 0 || ZeroFlag){
        for(int i=0;i<A.size();i++){
	  ans += abs(A[i]);
	}
      break;
    }
    else{
      int min = abs(A[0]);
      int minE = 0;
      for(int i=0;i<A.size();i++){
	if(min > abs(A[i])){
	  min = abs(A[i]);
	  minE = i;
	}
      }
      for(int i=0;i<A.size();i++){
	 ans += abs(A[i]);
      }
      ans -= abs(A[minE]) * 2;
      break;
    }
  }

  cout << ans << endl;
  
  return 0;
}
