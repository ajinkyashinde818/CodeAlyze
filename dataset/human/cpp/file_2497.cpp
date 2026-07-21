#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, count=0;
  long result=0, min=LONG_MAX;
  cin >> N;
  int A[N];

  for(int i=0;i<N;i++){
    cin >> A[i];
    if(A[i]<0){
      count+=1;
    }
    result += abs(A[i]);
    if(abs(A[i])<min){
      min = abs(A[i]);
    }
  }

  if(count%2==0){

  }else{
    result -= 2*min;
  }

  cout << result << endl;
}
