#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
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
  int R,G,B,N,count=0;
  cin >> R >> G >> B >> N;
  for(int i=N/R;i>=0;i--){
    for(int j=(N-i*R)/G;j>=0;j--){
      if((N-i*R-j*G)%B == 0) count++;
      
    }
  }
  cout << count;
}
