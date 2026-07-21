#include <bits/stdc++.h>
using namespace std;

int main() {
  //vector<int> b(101);
  //b.at(0)=1;
  int N, M, MM;
  long int A, S, a=1000000000;
  cin >> N;
  int i;
  int z=0;
  int o=0;
  for (i=0, S=0; i<N; i++) {
    cin >> A;
    if (A == 0) z=1;
    else if (A>0) S+=A;
    else {
      S-=A;
      o++;
    }
    a=min(a, abs(A));
  }
  o=o % 2;
  if ((z==0) && (o==1)) {
    S-=2*a;
  }
  cout << S << endl;
  return 0;
}
