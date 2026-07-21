#include <bits/stdc++.h>
using namespace std;
int main(){
  int N, count_minus = 0;
  bool existence_zero = false;
  long S=0, min=100000000;
  cin >> N;
  
  vector<long> A(N);
  for(int i=0;i<N;i++){
    cin >> A.at(i);
    if(A.at(i)<0){
      count_minus++;
      A.at(i) = -A.at(i);
    }
    else if(A.at(i)==0){
      existence_zero = true;
    }
    
    if(A.at(i)<=min && existence_zero==false){
      min = A.at(i);
    }
    
    S += A.at(i);
  }
  
  if(count_minus%2==1 && existence_zero==false){
    S -= 2*min;
  }
  cout << S << endl;
}
