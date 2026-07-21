#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
typedef long long ll;

int main(){
  int N;
  cin >> N;
  ll A[N];
  ll B[N];
  ll num=0;
  ll sum=0;
  for(int i=0;i<N;i++){
    cin >> A[i];
    B[i] = abs(A[i]);
    sum += B[i];
    if(A[i]<0) num++;
  }
  sort(B,B+N);
  if(num%2!=0) sum -= 2*B[0];
  cout << sum << endl;
}
