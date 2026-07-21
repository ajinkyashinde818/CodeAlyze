////////////////////////////////////////
///  tu3 pro-con template            ///
////////////////////////////////////////
#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <functional>
#include <vector>
#include <queue>
#include <string>
#include <complex>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <regex>
using namespace std;

//// MACRO ////
#define countof(a) (sizeof(a)/sizeof(a[0]))

#define REP(i,n) for (int i = 0; i < (n); i++)
#define RREP(i,n) for (int i = (n)-1; i >= 0; i--)
#define FOR(i,s,n) for (int i = (s); i < (n); i++)
#define RFOR(i,s,n) for (int i = (n)-1; i >= (s); i--)
#define pos(c,i) c.being() + (i)
#define allof(c) c.begin(), c.end()
#define aallof(a) a, countof(a)
#define partof(c,i,n) c.begin() + (i), c.begin() + (i) + (n)
#define apartof(a,i,n) a + (i), a + (i) + (n)
#define long long long

#define EPS 1e-9
#define INF (1L << 30)
#define LINF (1LL << 60)

#define PREDICATE(t,a,exp) [&](const t & a) -> bool { return exp; }
#define COMPARISON_T(t) bool(*)(const t &, const t &)
#define COMPARISON(t,a,b,exp) [&](const t & a, const t & b) -> bool { return exp; }
#define CONVERTER(TSrc,t,TDest,exp) [&](const TSrc &t)->TDest { return exp; }

//// i/o helper ////

template <class T> struct vevector : public vector<vector<T>> { vevector(int n = 0, int m = 0, const T &initial = T()) : vector<vector<T>>(n, vector<T>(m, initial)) { } };
template <class T> struct vevevector : public vector<vevector<T>> { vevevector(int n = 0, int m = 0, int l = 0, const T &initial = T()) : vector<vevector<T>>(n, vevector<T>(m, l, initial)) { } };
template <class T> struct vevevevector : public vector<vevevector<T>> { vevevevector(int n = 0, int m = 0, int l = 0, int k = 0, const T &initial = T()) : vector<vevevector<T>>(n, vevevector<T>(m, l, k, initial)) { } };

template <class T> T read() { T t; cin >> t; return t; }
template <class T> vector<T> read(int n) { vector<T> v; v.reserve(n); REP(i, n) { v.push_back(read<T>()); } return v; }
template <class T> vevector<T> read(int n, int m) { vevector<T> v; v.reserve(n); REP(i, n) v.push_back(read<T>(m)); return v; }
template <class T> vector<T> readjag() { return read<T>(read<int>()); }
template <class T> vevector<T> readjag(int n) { vevector<T> v; REP(i, n) v.push_back(readjag<T>()); return v; }

template <class T1, class T2> inline istream & operator >> (istream & in, pair<T1, T2> &p) { in >> p.first >> p.second; return in; }
template <class T1, class T2> inline ostream & operator << (ostream &out, pair<T1, T2> &p) { out << p.first << p.second; return out; }
template <class T> inline ostream & operator << (ostream &out, const vector<T> &v)
{
	ostringstream ss;
	for (auto x : v) ss << x << ' ';
	auto s = ss.str();
	out << s.substr(0, s.length() - 1);
	return out;
}

struct _Reader { template <class T> _Reader operator ,(T &rhs) { cin >> rhs; return *this; } };
struct _Writer { bool f; _Writer() : f(false) { } template <class T> _Writer operator ,(const T &rhs) { cout << (f ? " " : "") << rhs; f = true; return *this; } };
#define READ(t,...) t __VA_ARGS__; _Reader(), __VA_ARGS__
#define WRITE(...) _Writer(), __VA_ARGS__; cout << endl

////////////////////
/// template end ///
////////////////////


int main()
{
	READ(long, N, C);
	auto xv = read<pair<long, long>>(N);

	std::vector<long> ansA;
	{
		ansA.reserve(N + 1);
		ansA.push_back(0);
		long currentPos = 0;
		REP(i, N)
		{
			long distance = xv[i].first - currentPos;
			long calorie = xv[i].second;
			ansA.push_back(ansA.back() - distance + calorie);
			currentPos += distance;
		}

		FOR(i, 1, N + 1)
		{
			ansA[i] = std::max(ansA[i - 1], ansA[i]);
		}
		//WRITE(ansA);
	}


	std::vector<long> ansB;
	{
		ansB.reserve(N + 1);
		ansB.push_back(0);
		long currentPos = 0;
		RREP(i, N)
		{
			long distance = (C - xv[i].first) - currentPos;
			long calorie = xv[i].second;
			ansB.push_back(ansB.back() - distance + calorie);
			currentPos += distance;
		}

		FOR(i, 1, N + 1)
		{
			ansB[i] = std::max(ansB[i - 1], ansB[i]);
		}
		//WRITE(ansB);
	}

	long result = max(ansA[N], ansB[N]);
	FOR(i, 1, N + 1)
	{
		long cwDistance = xv[i - 1].first;
		long ccwDistance = C - xv[N - i].first;

		//WRITE(ansA[i] - cwDistance + ansB[N - i], ansB[i] - ccwDistance + ansA[N - i]);

		result = max(result, ansA[i] - cwDistance + ansB[N - i]);
		result = max(result, ansB[i] - ccwDistance + ansA[N - i]);
	}

	WRITE(result);
}
