#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <list>
#include <string>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
const int MOD = 998244353;

int gcd(int a, int b){
  if(b == 0) return a;
  return gcd(b, a%b);
}

int main()
{
  int N,minuscount = 0;
  ll abssum=0,absmin,num;
  cin >> N >> num;
  abssum = absmin = llabs(num);
  if(num < 0) minuscount++;
  for(int i=1;i<N;i++){
    cin >> num;
    abssum += llabs(num);
    if(absmin > llabs(num)) absmin = llabs(num);
    if(num < 0) minuscount++;
  }
  if(minuscount %2 == 0) cout << abssum;
  else cout << abssum - absmin*2;
}
