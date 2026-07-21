#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <queue>
#include <bitset>

#define rep(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, n) for(int i = (a); i < (n); i++)
#define MP make_pair
#define all(s) (s).begin(), (s).end()
#define rev(s) (s).rbegin(), (s).rend()
#define X first
#define Y second

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> P;

struct bits{
	bitset<32> b;

	bits(){ rep(i, 32) b[i] = 0; }

	bits(string s){
	}

	double to_f(){
		double res = 0;
		rep(i, 7) if(b[i]) res += pow(2.0, i-7);
		FOR(i, 7, 31) if(b[i]) res += 1<<(i-7);
		if(b[31]) res *= -1;

		return res;
	}
};

int main(){
	int n;
	cin >> n;
	while(n--){
		int bits = 0;
		string s;
		cin >> s;
		rep(i, 8){
			bits <<= 4;
			int b;
			if(s[i] >= '0' && s[i] <= '9') b = s[i] - '0';
			else b = s[i] - 'a' + 10;
			bits += b;
		}

		double b = 0;
		int a = 0;
		rep(i, 7) if(bits&(1<<i)) b += pow(2.0, i-7);
		FOR(i, 7, 31) if(bits&(1<<i)) a += 1<<(i-7);

		string str;
		while(abs(b-(int)b) > pow(2.0, -8)){
			b *= 10;
			str += '0'+(int)b%10;
		}
		if(str.empty()) str = '0';

		if(bits&(1<<31)) cout << '-';
		cout << a << '.' << str << endl;
	}


	return 0;
}
