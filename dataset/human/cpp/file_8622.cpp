#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>
#include <limits>

using namespace std;

template<class T = int,T divided_by = 10>
constexpr T PINF(){ return std::numeric_limits<T>::max()/divided_by; }
template<class T = int,T divided_by = 10>
constexpr T MINF(){ return std::numeric_limits<T>::lowest()/divided_by; }

template<class T = int> T gcd(T a, T b){ return b ? gcd(b,a%b) : a; }
template<class T = int> T lcm(T a, T b){ return a / gcd(a,b) * b; }
template<class T = int> T lcm_safe(T a, T b){ T p = a/gcd(a,b); return (b <= PINF<T>()/p) ? p*b:PINF<T>(); }
//オーバーフローするとき+INFを返す
//
int main() {
	cin.tie(nullptr); ios::sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
		vector<string> a(n), b(m); 
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}

	for(int i = 0; i < m; ++i){
		cin >> b[i];
	}

	for(int i_zero = 0; i_zero < n-m+1; ++i_zero){
		for(int j_zero = 0; j_zero < n-m+1; ++j_zero){
			bool isSame = true;
			for(int i = 0; i < m; ++i){
				for(int j = 0; j < m; ++j){
					isSame = isSame && (b[i][j] == a[i_zero+i][j_zero+j]);
				}
			}

			if(isSame) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
	return 0;
}
