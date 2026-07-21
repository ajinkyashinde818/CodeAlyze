#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
using namespace std;


int main(void) {
  int N;
  cin >> N;
  vector<int>A(N);
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }

  int cnt = 0;
  long long ans = 0;
  long long mini = (int) 1e10;
  int judge = 0;
  for(int i = 0; i < N; i++) {
    if(A[i] < 0) cnt++;
    if(A[i] == 0) judge = 1;
    if(abs(A[i]) < mini) mini = abs(A[i]);
    ans+=abs(A[i]);
  }
  if(cnt % 2 == 0) judge = 1;
  cout << (judge ? ans:ans - 2*mini) << endl;
  
  return 0;
}
