#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;

#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;
// 任意長整数型
using Bint = mp::cpp_int;
// 仮数部が1024ビットの浮動小数点数型(TLEしたら小さくする)
using Real = mp::number<mp::cpp_dec_float<1024>>;

int Min(vector<long> x){
  int a=x.size();
  for(int i=0;i<a-1;i++){
    x.at(i+1)=min(x.at(i),x.at(i+1));
  }
  return x.at(a-1);
}

long long f(vector<long> x){
  long long ans=0;
  for(int i=0;i<x.size();i++){
    ans+=x.at(i);
  }
  return ans;
}

int main() {
  int N,c;
  cin>>N;
  vector<long> a(N);
  Bint ans=0;
  for(int i=0;i<N;i++){
    cin>>a.at(i);
    if(a.at(i)<0){
      c++;
      a.at(i)=labs(a.at(i));
    }
  }
  //  cout<<a.at(0)<<Min(a);
  ans=f(a);
  if(c%2==1){
    ans-=2*Min(a);
  }
  //Bint X=10000000*100000;
  cout<<ans;
  return 0;
}
