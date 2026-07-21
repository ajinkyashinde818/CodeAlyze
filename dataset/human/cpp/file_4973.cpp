#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int main(){
  int n,r,k = 0;
  cin >> n >> r;
  if (n >= 10){
    cout << r << '\n';
  }
  k = 100 * (10 - n);
  if (n < 10){
    cout << r + k << '\n';
  }
  return 0;   
}
