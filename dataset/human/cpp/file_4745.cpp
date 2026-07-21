#include<iostream>
#include<algorithm>
#include<cmath>
#include<map>
#include<string>
#include<set>
#include<vector>
using namespace std;

int solve(){
  int n, r; cin >> n >> r;
  cout << (n>=10 ? r : r+100*(10-n)) << endl;
  return 0;
}

int main(){
  solve();
  return 0;
}
