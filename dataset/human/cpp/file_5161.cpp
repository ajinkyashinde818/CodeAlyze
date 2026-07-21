#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <limits.h>
using namespace std;

int main(){
  int A, B , ans=0 ;
  cin >> A >> B ;
  if(A < 10){
    ans = B + 100 * (10 - A) ;
  }  
  else{
    ans = B ;
  }  
  cout << ans << endl ;
  return 0 ;
}
