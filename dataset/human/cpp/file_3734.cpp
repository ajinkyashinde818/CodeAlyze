#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  int mnum=0;
  long long sum=0;
  for (int i=0; i<N; i++) {
    cin >> a.at(i);
    if (a.at(i)<0) {
      mnum++;
    }
  }
  if (mnum%2==0) {
    for (int i=0; i<N; i++) {
      sum += abs(a.at(i));
    }
  }
  else {
    for (int i=0; i<N; i++) {
      a.at(i) = abs(a.at(i));
    }
    sort(a.begin(), a.end());
    for (int i=0; i<N; i++) {
      sum += a.at(i);
    }
    sum-=2*a.at(0);
  }
    
  cout << sum << endl;
}
