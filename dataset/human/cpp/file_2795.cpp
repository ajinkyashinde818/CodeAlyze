#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
  int N,x,flag,zero;
  cin >> N;
  flag = 0;
  zero = 0;
  long sum;
  sum = 0;
  vector<int> kari(N);
  vector<int> vec(N);
  
  for (int i = 0; i < N; i++) {
    cin >> kari.at(i);
    if(kari.at(i) < 0){
      flag ++;
      kari.at(i) = 0 - kari.at(i);
    }
    if(kari.at(i) == 0){
      zero ++;
    }
    vec.at(i) = kari.at(i);
    sum += kari.at(i);
  }
  sort(vec.begin(),vec.end());
  if( flag % 2 == 1 && zero == 0){
     sum = sum - 2 * vec.at(0);
  }
  cout << sum << endl;
}
