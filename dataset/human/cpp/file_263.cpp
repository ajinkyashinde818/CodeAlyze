#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <math.h>
#include <algorithm>
using namespace std;
namespace mp = boost::multiprecision;
using llll = mp::cpp_int;
// 仮数部が1024ビットの浮動小数点数型(TLEしたら小さくする)
using Real = mp::number<mp::cpp_dec_float<1024>>;
using ll = long long;
const double EPS = 1e-10;
const ll MOD = 7+(1e+9);

int main(){
  ll r,g,b,n;
  ll ans=0;
  cin>>r>>g>>b>>n;
  for(ll i=0;i<=(n/r)+1;i++){
    for(ll j=0;j<=(n/g)+1;j++){
      if(n-i*r-j*g>=0&&(n-i*r-j*g)%b==0){
        ans++;
      }
    }
  }
  cout<<ans<<endl;
}
