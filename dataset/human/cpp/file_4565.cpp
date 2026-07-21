#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdio>
using namespace std;
using ll = long long;
int main(){
  int n,r;
  cin >> n >> r;
  if(n>=10){
    cout << r << "\n";
  }else{
    cout << r + 100 * (10 - n) << "\n";
  }
  return 0;
}
