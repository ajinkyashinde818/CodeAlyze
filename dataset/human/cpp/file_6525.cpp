#include <iostream>
#include <string>
#include <vector>

template<long long int MODVALUE>
class modllint{
  long long int val;
  void mod(){
    while( this->val < 0 ) this->val += MODVALUE;
    this->val %= MODVALUE;
  }
  void assign(const long long int val){
    this->val = val;
    mod();
  }
public:
  modllint(): val(0){};
  modllint(const long long int val){assign(val);};
  
  modllint operator+(const long long int val){
    return modllint<MODVALUE>(this->val + val);
  }
  modllint operator+(const modllint& obj){return *this + obj.val;}
  modllint& operator+=(const long long int val){
    this->assign(this->val + val);
    return *this;
  }
  modllint& operator+=(const modllint& obj){
    this->assign(this->val + obj.val);
    return *this;
  }
  
  modllint operator*(const long long int val){
    return modllint<MODVALUE>(this->val * val);
  }
  modllint operator*(const modllint& obj){return *this * obj.val;}
  modllint& operator*=(const long long int val){
    this->assign(this->val * val);
    return *this;
  }
  modllint& operator*=(const modllint& obj){
    this->assign(this->val * obj.val);
    return *this;
  }

  modllint& operator=(const modllint& obj){
    assign(obj.val);
    return *this;
  }
  modllint& operator=(const long long int intvalue){
    assign(intvalue);
    return *this;
  }
  
  friend std::ostream& operator<<(std::ostream& os, const modllint<MODVALUE>& val){
    os << val.val;
    return os;
  }
  friend std::istream& operator>>(std::istream& is, modllint<MODVALUE>& val){
    is >> val.val;
    return is;
  }
};

const int MOD = 1000000007;

int main(void){
  int n;
  std::string s;
  std::cin >> n >> s;

  std::vector<bool> v(2*n);
  for(int i=0; i<2*n; i++){
    v[i] = (s[i]=='B');
  }
  for(int i=0; i<2*n; i++){
    if(i%2 == 0) v[i] = !v[i];
  }

  modllint<MOD> result = 1;
  int l_count = 0;
  for(int i=0; i<2*n; i++){
    if(v[i]){ //R
      if(l_count == 0){
	std::cout << 0 << std::endl;
	return 0;
      }
      result *= l_count--;
    }else{
      l_count++;
    }
  }
  if(l_count != 0){
    std::cout << 0 << std::endl;
  }else{
    modllint<MOD> fac = 1;
    for(int i=1; i<=n; i++){
      fac *= i;
    }
    std::cout << (result * fac) << std::endl;
  }
  return 0;
}
