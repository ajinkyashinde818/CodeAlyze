#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

int64_t EuclidMod(int64_t v, int64_t m){
  if(0 <= v && v < m){
    return v;
  }else if(-m <= v && v < 0){
    return v + m;
  }else{
    int64_t result = v % m;
    if(result < 0){
      result += m;
    }
    return result;
  }
}

int64_t ModInv(int64_t a, int64_t m){
  int64_t b = m, u = 1, v = 0;
  while(b){
    int64_t t = a / b;
    a -= t * b;
    std::swap(a, b);
    u -= t * v;
    std::swap(u, v);
  }
  EuclidMod(u, m);
  return u;
}

// return base^exponent (MOD. mod).
int64_t RepeatedPowMod(int64_t base, int64_t exponent, int64_t mod) {
  if (exponent == 0)
    return 1;
  else if (exponent % 2 == 0) {
    int64_t root = RepeatedPowMod(base, exponent / 2, mod);
    return (root * root) % mod;
  } else {
    return (base * RepeatedPowMod(base, exponent - 1, mod)) % mod;
  }
}

template<int64_t mod>
class ModInt{
  int64_t value_;

public:
  explicit ModInt(const int64_t x = 0): value_(x % mod){
  };

  ModInt& operator=(const ModInt& another){
    value_=another.value_;
    return *this;
  }

  ModInt& operator^=(const ModInt& another){
    value_=RepeatedPowMod(value_,another.value_,mod);
    return *this;
  }

  ModInt& operator+=(const ModInt& another){
    value_ += another.value_;
    value_ = EuclidMod(value_, mod);
    return *this;
  }

  ModInt& operator-=(const ModInt& another){
    value_ -= another.value_;
    value_ = EuclidMod(value_, mod);
    return *this;
  }

  ModInt& operator*=(const ModInt& another){
    value_ *= another.value_;
    value_ = EuclidMod(value_, mod);
    return *this;
  }

  ModInt& operator/=(const ModInt& another){
    value_ = value_ * ModInv(another.value_, mod);
    value_ = EuclidMod(value_, mod);
    return *this;
  }

  ModInt& operator++(){
    *this += ModInt(1);
    return *this;
  }

  ModInt operator++(int){
    ModInt tmp = *this;
    ++tmp;
    return tmp;
  }

  ModInt& operator--(){
    *this-=ModInt(1);
    return *this;
  }

  ModInt operator--(int){
    ModInt tmp=*this;
    --tmp;
    return tmp;
  }



  int64_t GetValue() const{
    return value_;
  }

};

template<int64_t mod>
ModInt<mod>
operator+(const ModInt<mod>& left, const ModInt<mod>& right){
  return ModInt<mod>(left) += right;
}

template<int64_t mod>
ModInt<mod>
operator-(const ModInt<mod>& left, const ModInt<mod>& right){
  return ModInt<mod>(left) -= right;
}

template<int64_t mod>
ModInt<mod>
operator/(const ModInt<mod>& left, const ModInt<mod>& right){
  return ModInt<mod>(left) /= right;
}

template<int64_t mod>
ModInt<mod>
operator*(const ModInt<mod>& left, const ModInt<mod>& right){
  return ModInt<mod>(left) *= right;
}

template<int64_t mod>
ModInt<mod>
operator^(const ModInt<mod>& left, const ModInt<mod>& right){
  return ModInt<mod>(left) ^= right;
}

template<int64_t mod>
std::ostream& operator<<(std::ostream& stream, const ModInt<mod>& mod_int){
  stream << mod_int.GetValue();
  return stream;
}

template<int64_t mod>
std::istream& operator>>(std::istream& stream, ModInt<mod>& mod_int){
  int64_t v;
  stream>>v;
  mod_int=ModInt<mod>(v);
  return stream;
}

const int64_t MOD=1000000007;

int main(void) {
  cout << std::fixed << std::setprecision(10);
  cin.tie(0);
  std::ios::sync_with_stdio(false);

  int n;
  cin>>n;
  std::string s;
  cin>>s;

  if(s.front()=='W'||s.back()=='W'){
    cout<<0<<endl;
    return 0;
  }

  std::string lr="L";
  for(int i=1;i<2*n;i++){
    if(s[i-1]!=s[i]){
      lr+=lr.back();
    }else{
      if(lr.back()=='L'){
        lr+="R";
      }else{
        lr+="L";
      }
    }
  }
  int lcount=0,rcount=0;
  for(int i=0;i<2*n;i++){
    char c=lr[i];
    if(c=='L'){
      lcount++;
    }else{
      rcount++;
    }
  }

  if(lcount!=rcount){
    cout<<0<<endl;
    return 0;
  }

  ModInt<MOD> result(1);

  ModInt<MOD> lcum(0);
  for(auto c:lr){
    if(c=='L'){
      lcum+=ModInt<MOD>(1);
    }else{
      result*=lcum;
      lcum-=ModInt<MOD>(1);
    }
  }


  for(int i=n;i>=1;i--){
    result*=ModInt<MOD>(i);
  }






  cout<<result<<endl;






  return 0;
}
