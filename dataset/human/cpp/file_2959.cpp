#include <bits/stdc++.h>
using namespace std;

bool isminus(long long i){
  return i < 0;
}

bool absmin(long long i, long long j){
  return abs(i) < abs(j);
}

long long abssum(vector<long long> &A){
  long long sum = 0LL;
  for(long long &i : A){
    sum += abs(i);
  }
  return sum;
}

int main(){
  int N;
  cin >> N;
  
  vector<long long> A(N);
  
  for(long long &i : A)
    cin >> i;
  
  int minus = count_if(A.begin(), A.end(), isminus);
  
  if(minus % 2 == 0)
    cout << abssum(A) << endl;
  else{
    long long two = 2;
    cout << abssum(A)
    	- two * abs(*min_element(A.begin(), A.end(), absmin)) << endl;
  }
}
