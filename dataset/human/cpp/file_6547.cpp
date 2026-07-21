#include <functional>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>
#include <type_traits>
namespace loquat {
template <int MOD>
class modulus_integer {
public:
	typedef modulus_integer<MOD> self_type;
private:
	int m_value;
	static self_type unsafe_construct(int x) noexcept {
		self_type y;
		y.m_value = x;
		return y;
	}
public:
	modulus_integer() noexcept
		: m_value(0)
	{ }
	modulus_integer(int x) noexcept
		: m_value(x % MOD)
	{
		if(m_value < 0){ m_value += MOD; }
	}
	int operator*() const noexcept { return m_value; }
	self_type& operator=(const self_type& x) noexcept {
		m_value = x.m_value;
		return *this;
	}
	self_type operator*(const self_type& x) const noexcept {
		return unsafe_construct(
			static_cast<long long>(m_value) * x.m_value % MOD);
	}
	self_type& operator*=(const self_type& x) noexcept {
		return (*this = *this * x);
	}
};
template <int MOD>
inline std::ostream& operator<<(
	std::ostream& os, const modulus_integer<MOD>& x)
{
	os << *x;
	return os;
}
}
using namespace std;
static const int MOD = 1000000007;
using mint = loquat::modulus_integer<MOD>;
int main(){
	ios_base::sync_with_stdio(false);
	int n;
	string s;
	cin >> n >> s;
	mint answer = 1;
	int pos = 0;
	for(int i = 0; i < 2 * n; ++i){
		if(s[i] == 'W'){
			if(pos % 2 == 0){
				answer *= pos;
				--pos;
			}else{
				++pos;
			}
		}else{
			if(pos % 2 == 0){
				++pos;
			}else{
				answer *= pos;
				--pos;
			}
		}
		if(pos < 0){
			answer = 0;
		}
	}
	if(pos != 0){ answer = 0; }
	for(int i = 1; i <= n; ++i){
		answer *= i;
	}
	cout << answer << endl;
	return 0;
}
