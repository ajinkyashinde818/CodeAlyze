#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<math.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  vector<long long> A(N);
  for (int i=0; i<N; i++) cin >> A[i];
  
  int cnt1 = 0;
  int cnt2 = 0;
  for (int i=0; i<N; i++) {
    if (A[i] < 0) cnt1++;
    else cnt2++;
  }
  vector<long long> nexta(N);
  for (int i=0; i<N; i++) {
    nexta[i] = abs(A[i]);
  }
  sort(nexta.begin(),nexta.end());
  if (cnt1%2 == 0) {
    long long sum = 0;
    for (int i=0; i<N; i++) {
      sum += nexta[i];
    }
    cout << sum << endl;
  }
  if (cnt1%2 == 1) {
    long long sum = 0;
    for (int i=1; i<N; i++) {
      sum += nexta[i];
    }
    cout << sum - nexta[0] << endl;
  }
}
