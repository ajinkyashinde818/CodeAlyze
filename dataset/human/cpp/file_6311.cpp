#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cstdint>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

template<int64_t Prime>
struct mod_int {
  int64_t v_;
  mod_int(int64_t x=0) : v_(x) { normalize(); }
  void normalize() { ((v_ %= Prime) += Prime) %= Prime; }
  mod_int operator+=(mod_int const& r){ (v_ += r.v_) %= Prime; return *this; }
  mod_int operator-=(mod_int const& r){ (v_ += Prime - r.v_) %= Prime; return *this; }
  mod_int operator*=(mod_int const& r){ (v_ *= r.v_) %= Prime; return *this; }
  mod_int operator+(mod_int const& r) const { mod_int res(*this); return res += r; }
  mod_int operator-(mod_int const& r) const { mod_int res(*this); return res -= r; }
  mod_int operator*(mod_int const& r) { mod_int res(*this); return res *= r; }
  mod_int pow(int x) const {
    int64_t res = 1, v = v_;
    while(x > 0) {
      if(x&1) (res *= v) %= Prime;
      x/=2; (v *= v) %= Prime;
    }
    return mod_int(res);
  }
  mod_int inv() const { return pow(Prime-2); }
};

int64_t const MOD = 1e9+7;
typedef mod_int<MOD> mint;

int main() {
  std::cin.tie(0); std::ios::sync_with_stdio(false);
  int N; std::string S; std::cin >> N >> S;
  std::vector<int> v(1, 0);
  if(S[0] == 'W') fin(0);

  for(int i = 1; i < N+N; ++i) {
    if((S[i] == S[i-1]) != (v.back() == i-1)) v.push_back(i);
  }
  if(v.size() != N) fin(0);
  mint ans=1;
  for(int i = 0; i < N; ++i) ans *= mint(i+1)*mint(i+i+1 - v[i]);
  fin(ans.v_);
  return 0;
}
