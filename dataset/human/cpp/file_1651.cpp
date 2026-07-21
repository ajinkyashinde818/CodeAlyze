#include <iostream>
#include <fstream>
#include <cmath>  
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <numeric>
#include <functional>
#include <string> 
#include <vector>
#include <bitset>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>

using namespace std;
using ll = long long;

template<class T> using V = vector<T>;
template<class T,class U> using P = pair<T,U>;

#define REP(i,n) for(int i = 0; i < int(n); i++)
#define FOR(i, m, n) for(int i = int(m);i < int(n);i++)
#define ALL(obj) (obj).begin(),(obj).end()

const ll MOD = (ll)1e9 + 7;
const ll HINF = (ll)1e18;
const ll LINF = (ll)1e9;
const long double PI = 3.1415926535897932384626433;

vector<int> dy = { 0,0,1,-1 };
vector<int> dx = { 1,-1,0,0 };

template<class T> void corner(bool flg, T hoge) {
	if (flg) {
		cout << hoge << endl;
		exit(0);
	}
	else return;
}

template <class T, class U>ostream &operator<<(ostream &o, const map<T, U>&obj) {
	o << "{"; for (auto &x : obj) o << " {" << x.first << " : " << x.second << "}" << ","; o << " }"; return o;
}

template <class T>ostream &operator<<(ostream &o, const set<T>&obj) {
	o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr) o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;
}

template <class T>ostream &operator<<(ostream &o, const vector<T>&obj) {
	o << "{"; for (int i = 0; i < (int)obj.size(); ++i)o << (i > 0 ? ", " : "") << obj[i]; o << "}"; return o;
}

template <class T, class U>ostream &operator<<(ostream &o, const pair<T, U>&obj) {
	o << "{" << obj.first << ", " << obj.second << "}"; return o;
}

template <template <class tmp>  class T, class U> ostream &operator<<(ostream &o, const T<U> &obj) {
	o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr)o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;
}

void print(void) {
	cout << endl;
}

template <class Head> void print(Head&& head) {
	cout << head;
	print();
}

template <class Head, class... Tail> void print(Head&& head, Tail&&... tail) {
	cout << head << " ";
	print(forward<Tail>(tail)...);
}

void YN(bool flg) {
	cout << ((flg) ? "YES" : "NO") << endl;
}

void Yn(bool flg) {
	cout << ((flg) ? "Yes" : "No") << endl;
}

void yn(bool flg) {
	cout << ((flg) ? "yes" : "no") << endl;
}

int main() {
	ll N; cin >> N;

	if(N == 1){
		cout << "Yes" << endl;
		cout << 2 << endl;
		cout << 1 << " " << 1 << endl;
		cout << 1 << " " << 1 << endl;
		return 0;
	}

	V<ll> A(100000+1,-1);
	ll cnt = 3, idx = 3;
	while(cnt <= 100000){
		A[cnt] = idx;
		cnt += idx;
		idx++;
	}

	if(A[N] == -1){
		cout << "No" << endl;
		return 0;
	}
	else {
		cout << "Yes" << endl;
	}

	ll M = A[N];
	V<V<int>> B(M);

	idx = 0;
	REP(i,M){
		B[i%M].push_back(idx);
		B[(i+1)%M].push_back(idx);
		idx++;
	}
	REP(i,M-1){
		if (idx == N) break;
		for (int j = i + 2; j < M; ++j) {
			if (i == 0 && j == M - 1) continue;
			B[i].push_back(idx);
			B[j].push_back(idx);
			idx++;
		}
	}
	
	//ans
	cout << M << endl;
	REP(i, M) {
		cout << M - 1; REP(j, B[i].size()) cout << " " << B[i][j]+1; cout << endl;
	}
	


	return 0;
}
