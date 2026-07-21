#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <math.h>
#include <vector>
using namespace std;

int main(){
  int n,r; cin>>n>>r;
  int k;
  if(n<10){
    k=100*(10-n);
    cout<<r+k<<endl;
  }
  else cout<<r<<endl;
  return 0;
}
