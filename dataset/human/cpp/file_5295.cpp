#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
//template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T a, T b) { if (a > b) { a = b; return 1; } return 0; }

const long long INF = 1LL << 60;
typedef long long int ll ;


#define INF 2000000000

int main() {

	int N,R,tmp;
	cin >> N >> R ;

	if(N >= 10) {
		cout << R << endl;
	}else{
		cout << R+100*(10-N) << endl;
	}
}
