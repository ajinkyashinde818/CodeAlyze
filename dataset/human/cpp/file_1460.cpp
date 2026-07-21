#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main(){
  long long N;
  cin >> N;

  long long k = 2;
  while(1){
    long long test = k*(k-1);
    if(test == 2*N){
      break;
    }else if(test > 2*N){
      cout << "No" <<"\n";
      return 0;
    }else{
      k++;
    }
  }

  cout << "Yes" << "\n";
  cout << k << "\n";

  int sum[k] = {};
  sum[0]= 1;
  for(int i=1;i<k;i++){
    sum[i] = sum[i-1] + i;
  }

  for(int i=0;i<k-1;i++){
    cout << k-1 << " ";
    for(int j=0;j<i;j++){
      cout << sum[i] + j << " ";
    }
    for(int j=i;j<k-1;j++){
      cout << sum[j] + i;
      if(j != k-2){
        cout << " ";
      }
    }
    cout << "\n";
  }

  cout << k-1 << " ";
  for(int j=0;j<k-1;j++){
    cout << sum[j] + j;
    if(j != k-2){
      cout << " ";
    }
  }
  cout << "\n";

  return 0;
}
