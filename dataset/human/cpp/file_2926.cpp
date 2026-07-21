#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int N;cin >> N;
  vector<ll> A(N);
  ll sum = 0;
  int count_nega=0;
  for(int i=0;i<N;i++){
    cin >> A[i];
    if(A[i]<0){
      count_nega ++;
      A[i] = -A[i];
    }
    sum += A[i];
  }
  sort(A.begin(),A.end());
  if(count_nega%2==0){
    cout << sum << endl;
  }else{
    cout << sum - 2*A[0] << endl;
  }
}
