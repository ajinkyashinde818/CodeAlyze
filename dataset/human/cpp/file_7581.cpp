#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main(void){
  int N;
  cin >> N;

  vector<long>num(N,0);
  for(int i=0;i<N;i++){
    cin >> num[i];
  }

  for(int i=1;i<N;i++){
    num[i] = num[i] + num[i - 1];
  }

  long sum = num[N - 1] / 2;

  long gap = 9999999999;
  int c = 0;
  for(int i=0;i<N - 1;i++){
    if(gap > abs(sum - num[i])){
      gap = abs(sum - num[i]);
      c = i;
    }
  }

  cout << abs(num[N - 1] - num[c] - num[c]) << endl;


  return 0;
}
