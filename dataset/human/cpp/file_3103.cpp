#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  long long A;
  long long m=1000000000;
  long long c=0;
  long long s=0;
  for (int i;i<N;i++){
    cin >> A;
    m=min(abs(A),m);
    c=A<0?1-c:c;
    s+=abs(A);
  }
  cout << (c==1?s-m*2:s) << endl;
}
