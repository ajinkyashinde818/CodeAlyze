//from:https://atcoder.jp/contests/exawizards2019/submissions/4794708

#include<cstdint>
using namespace std;

template <std::uint_fast64_t Modulus> class modint {
  using u64 = std::uint_fast64_t;

public:
  u64 a;

  constexpr modint(const u64 x = 0) noexcept : a(x % Modulus) {}
  constexpr u64 &value() noexcept { return a; }
  constexpr const u64 &value() const noexcept { return a; }
  constexpr modint operator+(const modint rhs) const noexcept {
    return modint(*this) += rhs;
  }
  constexpr modint operator-(const modint rhs) const noexcept {
    return modint(*this) -= rhs;
  }
  constexpr modint operator*(const modint rhs) const noexcept {
    return modint(*this) *= rhs;
  }
  constexpr modint operator/(const modint rhs) const noexcept {
    return modint(*this) /= rhs;
  }
  constexpr modint &operator+=(const modint rhs) noexcept {
    a += rhs.a;
    if (a >= Modulus) {
      a -= Modulus;
    }
    return *this;
  }
  constexpr modint &operator-=(const modint rhs) noexcept {
    if (a < rhs.a) {
      a += Modulus;
    }
    a -= rhs.a;
    return *this;
  }
  constexpr modint &operator*=(const modint rhs) noexcept {
    a = a * rhs.a % Modulus;
    return *this;
  }
  constexpr modint &operator/=(modint rhs) noexcept {
    u64 exp = Modulus - 2;
    while (exp) {
      if (exp % 2) {
        *this *= rhs;
      }
      rhs *= rhs;
      exp /= 2;
    }
    return *this;
  }
};

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<iomanip>
#include<set>
#include<queue>

using namespace std;

#define MOD 1000000007

int main()
{
//	using mint=modint<1000000007>;

	int n;
	string s;
	cin >> n >> s;

	if(s[0]=='W')
	{
		cout << 0 << endl;
		return 0;
	}

	long long left=1;			
	long long ans=1;	

	for(int i=1;i<2*n;i++)
	{
		int odd=(s[i]=='B' ? 1:0);
		if(left%2==odd)
		{
			ans*=left;
			ans%=MOD;
			left--;

			if(left<0)
			{
				cout << 0 << endl;
				return 0;
			}

		}
		else
		{
			left++;
		}
//		cout << i << " : " << s[i] << " : " << left << " : " << ans << endl;
	}

	if(left!=0)
	{
		cout << 0 << endl;
		return 0;
	}

	for(int i=1;i<=n;i++)
	{
		ans*=i;
		ans%=MOD;
	}


	cout << ans%MOD << endl;

}
