#include<bits/stdc++.h>
using namespace std;

template<typename T, typename U> bool chmin(T &a, const U &b) {
	return (a > b ? a = b, true : false);
}
template<typename T, typename U> bool chmax(T &a, const U &b) {
	return (a < b ? a = b, true : false);
}

typedef long long ll;

#define writeln(n) cout<<n<<"\n";

typedef pair<int, int> P;
typedef pair<string, int> Psi;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n,k;
	cin>>n>>k;

	if(n >=10){
		writeln(k);
	}else {
		cout<<k+100*(10-n)<<endl;
	}

}
