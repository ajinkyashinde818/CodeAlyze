/* ＵＴＦ－８ */
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <array>
#include <queue>
#include <stack>
#include <algorithm>
#include <tuple>
#include <numeric>
#include <type_traits>
#include <limits>

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define USE_COLORED 1

#ifdef USE_COLORED
static const char stdout_pre[]  = "\033[1m"; // bold black
static const char stderr_pre[]  = "\033[31;1m"; // bold red
static const char stdxxx_post[] = "\033[m";

// 当然ながら GCC(g++)/libstdc++ 依存
#include <ext/stdio_filebuf.h>
using stdio_filebuf = __gnu_cxx::stdio_filebuf<char>;
class colored_stdio_filebuf : public stdio_filebuf {
private:
	const char* const pre_;
	const char* const post_;

public:
	colored_stdio_filebuf(FILE* fp, const char* pre, const char* post) : stdio_filebuf(fp, std::ios_base::out), pre_(pre), post_(post)
	{
	}

protected:
	std::streamsize xsputn(const char* s, std::streamsize count) override
	{
		stdio_filebuf::xsputn(pre_, strlen(pre_));
		auto ret = stdio_filebuf::xsputn(s, count);
		stdio_filebuf::xsputn(post_, strlen(post_));
		return ret;
	}
};
#endif

template<unsigned int MOD>
struct modcalc
{
	static_assert(MOD < std::numeric_limits<unsigned int>::max() / 4, "");

	static unsigned int add(unsigned int a, unsigned int b) __attribute__ ((warn_unused_result))
	{
		return (a + b) % MOD;
	}

	static void addeq(unsigned int& a, unsigned int b)
	{
		a = add(a, b);
	}

	static unsigned int sub(unsigned int a, unsigned int b) __attribute__ ((warn_unused_result))
	{
		return (MOD + a - b) % MOD;
	}

	static void subeq(unsigned int& a, unsigned int b)
	{
		a = sub(a, b);
	}

	static unsigned int neg(unsigned int a) __attribute__ ((warn_unused_result))
	{
		return (MOD - a) % MOD;
	}

	static void negeq(unsigned int& a)
	{
		a = neg(a);
	}

	static unsigned int mul(unsigned int a, unsigned int b) __attribute__ ((warn_unused_result))
	{
		return (static_cast<unsigned long long>(a) * static_cast<unsigned long long>(b)) % MOD;
	}

	static void muleq(unsigned int& a, unsigned int b)
	{
		a = mul(a, b);
	}

	static unsigned int pow(unsigned int a, unsigned int b) __attribute__ ((warn_unused_result))
	{
		int ret = 1;
		while (b) {
			if (b & 1)
				ret = mul(ret, a);
			a = mul(a, a);
			b >>= 1;
		}
		return ret;
	}


	// 階乗

	static std::vector<unsigned int> fac_table; // n!

	static void init_fac(unsigned int last)
	{
		fac_table.resize(last);
		fac_table[0] = 1;
		for (unsigned int i = 1; i < last; ++i) {
			fac_table[i] = mul(fac_table[i - 1], i);
		}
	}

	static unsigned int fac(unsigned int x) __attribute__ ((warn_unused_result))
	{
		return fac_table[x];
	}


	// 逆数

	static std::vector<unsigned int> inv_table; // n^-1

	static void init_inv(unsigned int last)
	{
		inv_table.resize(last);
		inv_table[0] = 0; // XXX
		inv_table[1] = 1;
		for (unsigned int i = 2; i < last; ++i) {
			inv_table[i] = MOD - mul(inv_table[MOD % i], MOD / i);
		}
	}

	static unsigned int inv(unsigned int x) __attribute__ ((warn_unused_result))
	{
		return inv_table[x];
	}

	static unsigned int div(unsigned int a, unsigned int b) __attribute__ ((warn_unused_result))
	{
		return mul(a, inv(b));
	}

	static void diveq(unsigned int a, unsigned int b)
	{
		a = div(a, b);
	}


	// 階乗の逆数

	static std::vector<unsigned int> invfac_table; // (n!)^-1

	static unsigned int init_invfac(unsigned int last)
	{
		invfac_table.resize(last);
		invfac_table[0] = 0; // XXX
		invfac_table[1] = 1;
		for (unsigned int i = 2; i < last; ++i) {
			invfac_table[i] = mul(invfac_table[i - 1], inv_table[i]);
		}
	}

	static unsigned int invfac(unsigned int x) __attribute__ ((warn_unused_result))
	{
		return invfac_table[x];
	}


	// 二項係数

	static unsigned int combination(unsigned int n, unsigned int k) __attribute__ ((warn_unused_result))
	{
		if (n < k)
			return 0;
		return mul(fac(n), mul(invfac(k), invfac(n - k)));
	}
};

template<unsigned int MOD> std::vector<unsigned int> modcalc<MOD>::fac_table;
template<unsigned int MOD> std::vector<unsigned int> modcalc<MOD>::inv_table;
template<unsigned int MOD> std::vector<unsigned int> modcalc<MOD>::invfac_table;

using mod = modcalc<1000000007U>;

int main()
{
#ifdef USE_COLORED
	if (getenv("DEBUG")) {
		std::cout.rdbuf(new colored_stdio_filebuf(stdout, stdout_pre, stdxxx_post));
		std::cerr.rdbuf(new colored_stdio_filebuf(stderr, stderr_pre, stdxxx_post));
	} else
#endif
	{
		int fd = open("/dev/null", O_WRONLY);
		dup2(fd, 2);
		close(fd);
	}
	
	int N;
	std::string S;
	
	std::cin >> N;
	std::cin >> S;


	if (S[0] == 'W' || S[N*2-1] == 'W') {
		std::cout << "0\n";
		return 0;
	}
	std::vector<unsigned char> canleft(N*2);
	canleft[0] = 1;
	int lefts = 1;
	int rights = 0;
	for (int i = 1; i < N*2; ++i) {
		if (S[i] == S[i-1]) {
			canleft[i] = !canleft[i-1];
		} else {
			canleft[i] = canleft[i-1];
		}
		if (canleft[i]) {
			++lefts;
		} else {
			++rights;
		}
	}
	if (lefts != rights) {
		std::cout << "0\n";
		return 0;
	}

	unsigned int numleft = 0;
	unsigned int pattern = 1;
	for (int i = 0; i < canleft.size(); ++i) {
		if (canleft[i]) {
			mod::addeq(numleft, 1);
		} else {
			mod::muleq(pattern, numleft);
			mod::subeq(numleft, 1);
		}
	}

	for (int i = 1; i <= N; ++i) {
		mod::muleq(pattern, i);
	}
	
	std::cout << pattern << "\n";
}
