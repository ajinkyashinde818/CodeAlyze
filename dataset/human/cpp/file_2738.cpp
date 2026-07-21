#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  scanf("%d", &N);
  int a[N];
  for (int i = 0; i < N; ++i) {
    scanf("%d", &a[i]);
  }
  int b[N];
  for (int i = 0; i < N; ++i) {
    b[i] = a[i];
    if(b[i]<0) b[i] *= -1; 
  }

  int mincount = 0;
  for (int i = 0; i < N; ++i) {
    if(a[i]<0) ++mincount;
  }

  long long sum = 0;

  if(mincount%2==0) {
    for (int i = 0; i < N; ++i) {
      sum += b[i];
    }
  }
  else{

    long min = 1000000000;
    for (int i = 0; i < N; ++i) {
      if(b[i]<min) min = b[i];
    }

    for (int i = 0; i < N; ++i) {
      sum += b[i];
    }

    sum -= 2*min;
  }

  cout << sum << endl;

}
