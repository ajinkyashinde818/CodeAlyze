//#include <boost/multiprecision/cpp_dec_float.hpp>
//#include <boost/multiprecision/cpp_int.hpp>
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
#include <bitset>
using namespace std;
//namespace mp = boost::multiprecision;
//using llll = mp::cpp_int;
// 仮数部が1024ビットの浮動小数点数型(TLEしたら小さくする)
//using Real = mp::number<mp::cpp_dec_float<1024>>;
using ll = long long;
const double EPS = 1e-10;
const ll MOD = 7+(1e+9);

int main(){
  ll n,ans=1;
  cin>>n;
  string s;
  cin>>s;
  vector<ll>v(2*n,0);
  vector<ll>a(2*n,0);
  for(ll i=0;i<2*n;i++){
    if(s[i]=='B')v[i]=1;
  }
  ll tmp=0;
  for(ll i=0;i<2*n;i++){
    if(v[i]^tmp){
      a[i]=1;//開始
    }
    tmp^=1;
  }
  ll aa=0,bb=0,f=0;
  ll k=0;
  for(ll i=0;i<2*n;i++){
    if(a[i])aa++;
    else bb++;
    if(aa<bb)f=1;
  }
  if(aa!=bb)f=1;
  if(f){
    cout<<0<<endl;
    return 0;
  }
  for(ll i=0;i<2*n;i++){
    if(a[i])k++;
    else{
      ans=ans*k%MOD;
      k--;
    }
  }
  for(ll i=1;i<=n;i++){
    ans=ans*i%MOD;
  }
  cout<<ans<<endl;
}
