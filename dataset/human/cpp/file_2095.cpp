#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(int argv, char** argc) {
  int N;
  int min,min_i=0;
  long int sum=0;
  bool flag = false;
  cin >> N;
  vector<int> A(N);
  for(int i=0;i<N;i++) cin >> A.at(i);

  min = A.at(0);
  for(int i=0;i<N-1;i++){
    if(abs(min)>abs(A.at(i+1))){
      min=A.at(i+1);
      min_i=i+1;
    }
    if(A.at(i)<0){
      A.at(i)*=-1;
      A.at(i+1)*=-1;
    }
  }

  if(A.at(N-1)<0)
    flag=true;

  if(flag==true){
    for(int i=N-1;i>min_i;i--){
      A.at(i)*=-1;
      A.at(i-1)*=-1;
    }
  }
  for(int i=0;i<N;i++) sum += A.at(i);
  cout << sum;

  return 0;
}
