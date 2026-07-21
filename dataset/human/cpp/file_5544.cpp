#include <iostream>
#include <cstdio>
#include <iterator>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, r;
  cin >> n >> r;
  if(n < 10){
    cout << r + (100*(10 - n));
  }else{
    cout << r;
  }


  return 0;
}
