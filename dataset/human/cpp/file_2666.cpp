#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  int count = 0;
  long long int sum = 0;
  for(int i=0;i<N;i++){
    cin >> A.at(i);
    if(A.at(i)<0){
      A.at(i)*=-1;
      count++;
    }
    sum+=A[i];
  }
  sort(A.begin(),A.end());
  if(count%2==0){
    cout << sum << endl;
  }else{
    cout << sum-2*A.at(0) << endl;
  }
}
