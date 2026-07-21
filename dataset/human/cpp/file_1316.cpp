#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<numeric>
#include<iomanip>
#include<deque>
#include<tuple>
#include<queue>
#include<stack>
#include<map>
#include<cstdint>
#include<unordered_map>
#include<boost/multiprecision/cpp_int.hpp>


#define rep(i, n) for(int i = 0; i < ( int)(n); i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
#define Cin cin>>a;

namespace mp = boost::multiprecision;

using cpp_int = mp::cpp_int;
using ll = long long;
using namespace std;

int main(void){
	int R, G, B, N;
	cin >> R >> G >> B >> N;
	int count = 0;
	for (int r = 0; r * R <= N; r++) {
		for (int g = 0; g * G <= N; g++) {
			int tmp = N - r * R - g * G;
			if (tmp >= 0 && tmp % B == 0) {
				count++;
			}
		}
	}
	cout << count << endl;

}
