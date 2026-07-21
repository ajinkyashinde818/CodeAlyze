#include <iostream>
#include<bits/stdc++.h>
#include <string>
using namespace std;
//typedef long long ll;

int main() {
  int N;
  cin >> N;
  long long int A[N];
  for(int i=0; i < N; i++){
    cin >>  A[i];
  }
  int pra =0;
  int mina = 0;
  int flag =0;
  for(int i=0; i < N; i++){
    if (A[i] < 0 )mina +=1;
    if (A[i] == 0 ) flag =1;
  }
  if (mina % 2 == 0) flag =1;
  long long int ans=0;
  if (flag ==1 ){
    for(int i=0; i < N; i++){
      ans += abs(A[i]);
    }
  }
  else{
    long long int B[N];
    for(int i=0; i < N; i++){
      B[i] = abs(A[i]);
    }
    sort(B,B+N);
    ans -= B[0];
    for(int i=1; i < N; i++){
      ans += B[i];
    }
  }
  cout << ans << endl;

}
